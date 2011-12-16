#!/usr/bin/env python3

#Name: TUScomm.py
#Description: Handles communication between UI/BI and The Ultimate Strategy
#Author: Lukasz Czarnecki

import socket, xml.dom.minidom

class CommLinkFailure(Exception):
    """Exception for handling communication problems between The Ultimate Strategy and the bot/user"""
    def __init__(self, exception_type, **kwargs):
        self.exception_type = exception_type
        self.kwargs = kwargs
        
    def __str__(self):
        if self.exception_type == 'send':
            return 'Sent only ' + str(self.kwargs['sent_bytes']) + ' out of ' + str(self.kwargs['total_bytes'])
        elif self.exception_type == 'validation_request':
            return 'Request is not a proper XML\n Message: ' + str(self.kwargs['message'])
        elif self.exception_type == 'validation_reply':
            return 'Response is not a proper XML\n Message: |' + str(self.kwargs['message']) + '|'

class CommLink:
    """Allows quick and painless communication between The Ultimate Strategy and bot/user."""

    def __init__(self, ip, port, persistent=False):
        """ Initializes the CommLink class by creating a default socket and stores information about the host.

        There are two possible connection modes -- persistent or not persistent.
        When persistent mode is chosen, the socket is created and initialized on object creation.
        When persistent mode is off (default), initialization is not done in the constructor 
        as the socket is meant to operate in a create - send - receive - close cycle.
        
        Requires two argumets:
        ip - string with the IP to the host
        port - int storing the port for communication with the host

        """
        self._persistent = persistent
        self._server = (ip, port)
        
        if self._persistent :
            self._init_socket()
            self._socket.connect(self._server)

    def __del__(self):
        if self._persistent :
            self._dispose_socket()

    def _init_socket(self):
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._socket.settimeout(30)
        
    def _dispose_socket(self):
        self._socket.shutdown(socket.SHUT_RDWR)
        self._socket.close()
        
    def _send(self, message):
        """Private method for sending a single request - DOES NOT INITIALIZE NOR CLOSE THE SOCKET

        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns the number of sent bytes.

        """
        #TODO: Add validation
        #TODO? What validation?
        data_size = len(bytes(message, 'UTF-8'))
        
        try :
            document = xml.dom.minidom.parseString(message)
        except xml.parsers.expat.ExpatError :
            raise CommLinkFailure('validation_request', message)
            
        bytes_sent = self._socket.send(bytes(message, 'UTF-8'))
        
        if data_size != bytes_sent :
            raise CommLinkFailure('send', pack (data_size=data_size, sent_size=sent_size))
            
        return bytes_sent

    def _receive(self):
        """Private method for recieving a single heap of data - DOES NOT INITIALIZE NOR CLOSE THE SOCKET

        Returns a document that was decoded from the socket (assuming it was UTF-8 encoded)
        or empy string when nothing is received from the socket (graceful socket close)
        """
        reply = b''
        r = True
        while r and not str(reply, 'UTF-8').endswith('</reply>\n'):
            r = self._socket.recv(2048)
            if r:
                reply += r
        
        if reply :
            reply = str(reply, 'UTF-8')
            try:
                document = xml.dom.minidom.parseString(reply)
                return document
            except xml.parsers.expat.ExpatError:
                raise CommLinkFailure('validation_reply', reply)
        else:
            return reply

    def exchange_xmls(self, message):
        """Public method responsible for connecting, sending, recieving and closing the socket.
        print(data_size, sent_size)

        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns a document that was decoded from the socket (assuming it was UTF-8 encoded).

        """
        if not self._persistent :
            self._init_socket()
            self._socket.connect(self._server)
        
        self._send(message)
        reply = self._receive()

        if not self._persistent :
            self._dispose_socket()
        
        return reply
    
    def stop(self):
        """ Disposes socket """
        if self._persistent :
            self._dispose_socket()

import queue, threading

class AsynchCommLink(CommLink):
    """Allows quick and painless communication between 
    The Ultimate Strategy and bot/user in asynchronous manner.
    """

    def __init__(self, ip, port):
        """ Initializes the CommLink class by creating a default 
        socket and stores information about the host.
        
        The socket is initialized at creation and serves for the 
        communication till the end of life of this object.
        
        Requires two argumets:
            ip - string with the IP to the host
            port - int storing the port for communication with the host
        """
        # The approach is different from CommLink so do not
        # use the base class constructor
        
        # Server information
        self._server = (ip, port)
        
        # Receiving thread 
        self.doReceive = False
        self.receiveThread = False
        
        # Queue for common replies
        self.msgQueue = queue.Queue()
        # Queue for indication
        self.indQueue = queue.Queue()

        # Initialization of the socket
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._socket.connect(self._server)
        
        # Starting recieving
        self._start_receiving();
    
    def __del__(self):
        """ Closes socket and stuff"""
        try:
            stop()
        except:
            pass

    def _receive_loop(self):
        """Receives messages in a loop and puts them on the queue
        """
        while self.doReceive :
            reply = self._receive()
            if reply:
                self.msgQueue.put(reply);
            else:
                self.doReceive = False
                break;
        
    def _start_receiving(self):
        self.doReceive = True
        self.receiveThread = threading.Thread(target=self._receive_loop);
        
        self.receiveThread.start()
        
    def _stop_receiving(self):
        self.doReceive = False
        self._socket.shutdown(socket.SHUT_RD);
        try :
            self.receiveThread.join(2.0)
        finally:
            del self.receiveThread
        self._socket.close()
    
    def stop(self):
        self._stop_receiving()
    
    def exchange_xmls(self, message):
        """Public method responsible for synchronous request to the server.

        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns a document that was decoded from the socket (assuming it was UTF-8 encoded).
        """
        self._send(message);
        reply = self.msgQueue.get();
        self.msgQueue.task_done();
        
        return reply

