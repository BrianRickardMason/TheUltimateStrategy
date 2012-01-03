#!/usr/bin/env python3

#Name: TUS Communication provider
#Description: Handles communication between UI/BI and The Ultimate Strategy, based on TUScomm
#Author: Bajron

import socket, xml.dom.minidom, queue, threading
from  TUScomm import CommLinkFailure

class AsynchCommLink():
    """Allows quick and painless communication between The Ultimate Strategy and bot/user."""

    def __init__(self, ip, port):
        """ Initializes the CommLink class by creating a default 
        socket and stores information about the host.
        
        The socket is initialized at creation and serves for the 
        communication till the end of life of this object.
        
        Requires two argumets:
            ip - string with the IP to the host
            port - int storing the port for communication with the host
            
        """
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
            self._stop_receiving()
        except:
            pass
        
    def _send(self, message):
        """Private method for sending a single request
        
        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns the number of sent bytes.

        @remark Socket must be initialized
        
        """

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
        """Private method for recieving a single heap of data

        Returns a string that was decoded from the socket (assuming it was UTF-8 encoded).
        
        @remark Socket must be initialized
        
        """
        while self.doReceive :
            reply = b''
            # TODO better message extracting
            while not str(reply, 'UTF-8').endswith('</reply>\n'):
                r = self._socket.recv(2048);
                
                # handle graceful socket shutdown
                if not r:
                    self.doReceive = False
                    break;
                reply += r
            
            # handling of received bytes
            if  reply:
                reply = str(reply, 'UTF-8')
                try:
                    document = xml.dom.minidom.parseString(reply)
                    self.msgQueue.put(document);
                except xml.parsers.expat.ExpatError:
                    raise CommLinkFailure('validation_reply', message=reply)
        #end of main loop [while self.doReceive]
        
    def _start_receiving(self):
        self.doReceive = True
        self.receiveThread = threading.Thread(target=self._receive);
        
        self.receiveThread.start()
        
    def _stop_receiving(self):
        self.doReceive = False
        self._socket.shutdown(socket.SHUT_RD);
        self._socket.close()
        try :
            self.receiveThread.join(2.0)
        finally:
            del self.receiveThread
                
    def exchange_xmls(self, message):
        """Public method responsible for synchronous request to the server.

        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns a string that was decoded from the socket (assuming it was UTF-8 encoded).
        
        """
        self._send(message);
        reply = self.msgQueue.get();
        self.msgQueue.task_done();
        
        return reply
