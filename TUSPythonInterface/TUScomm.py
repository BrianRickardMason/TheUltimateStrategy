#!/usr/bin/env python3

#Name: TUScomm.py
#Description: Handles communication between UI/BI and The Ultimate Strategy
#Author: Lukasz Czarnecki

import socket, xml.dom.minidom

class CommLinkFailure(Exception):
    """Exception for handling communication problems between The Ultimate Strategy and the bot/user"""
    def __init__(self, exception_type, **kwargs):
        self.exception_type = exception_type
        self.total_bytes = total_bytes
        self.sent_bytes = sent_bytes
    def __str__(self):
        if self.exception_type == 'send':
            return 'Sent only ' + str(kwargs['sent_bytes']) + ' out of ' + str(kwargs['total_bytes'])
        elif self.exception_type == 'validation_request':
            return 'Request is not a proper XML\n Message: ' + kwargs['message']
        elif self.exception_type == 'validation_reply':
            return 'Response is not a proper XML\n Message: ' + kwargs['message']

class CommLink:
    """Allows quick and painless communication between The Ultimate Strategy and bot/user."""

    def __init__(self, ip, port):
        """ Initializes the CommLink class by creating a default socket and stores information about the host.

        Initialization is not done in the constructor as the socket is meant to operate in a create - send - receive - close cycle.
        Requires two argumets:
        ip - string with the IP to the host
        port - int storing the port for communication with the host

        """
        self._server = (ip, port)
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._socket.settimeout(30)

    def _send(self, message):
        """Private method for sending a single request - DOES NOT INITIALIZE NOR CLOSE THE SOCKET

        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns the number of sent bytes.

        """
        #TODO: Add validation
        try:
            document = xml.dom.minidom.parseString(message)
        except xml.parsers.expat.ExpatError:
            raise CommLinkFailure('validation_request', message)
        bytes_sent = self._socket.send(bytes(message, 'UTF-8'))
        return bytes_sent

    def _receive(self):
        """Private method for recieving a single heap of data - DOES NOT INITIALIZE NOR CLOSE THE SOCKET

        Returns a string that was decoded from the socket (assuming it was UTF-8 encoded).

        """
        reply = b''
        while not str(reply, 'UTF-8').endswith('</reply>\n'):
            reply += self._socket.recv(2048)
        reply = str(reply, 'UTF-8')
        try:
            document = xml.dom.minidom.parseString(reply)
            return document.toprettyxml(indent="    ")
        except xml.parsers.expat.ExpatError:
            raise CommLinkFailure('validation_reply', reply)

    def exchange_xmls(self, message):
        """Public method responsible for connecting, sending, recieving and closing the socket.
        print(data_size, sent_size)

        Requires one argument:
        message - string with the message. Message will be encoded with UTF-8 prior to sending
        Returns a string that was decoded from the socket (assuming it was UTF-8 encoded).

        """
        self._socket.connect(self._server)
        data_size = len(bytes(message, 'UTF-8'))
        sent_size = self._send(message)
        if data_size != sent_size:
            raise CommLinkFailure('send', data_size=data_size, sent_size=sent_size)
        reply = self._receive()
        self._socket.close()
        return reply
