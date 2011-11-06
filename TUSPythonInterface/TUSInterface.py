#!/usr/bin/env python3

# Name: TUSInterface.py
# Description: The callable interface taking care of "all at once".
# Author: Marcin Skrobiranda.

import TUScomm

from TUSCommandBuilder import *

class TUSInterface():
    """ TODO """

    def __init__(self):
        """ TODO """

        self.m_command_builder = CommandBuilder()

    def createWorld(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("CREATE_WORLD", [a_login, a_password], [a_world_name])
        self.__send(command)

    def createEpoch(self, a_login, a_password, a_world_name, a_epoch_name):
        command = self.m_command_builder.build("CREATE_EPOCH", [a_login, a_password], [a_world_name, a_epoch_name])
        self.__send(command)

    def deleteEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("DELETE_EPOCH", [a_login, a_password], [a_world_name])
        self.__send(command)

    def activateEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("ACTIVATE_EPOCH", [a_login, a_password], [a_world_name])
        self.__send(command)

    def deactivateEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("DEACTIVATE_EPOCH", [a_login, a_password], [a_world_name])
        self.__send(command)

    def finishEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("FINISH_EPOCH", [a_login, a_password], [a_world_name])
        self.__send(command)

    def tickEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("TICK_EPOCH", [a_login, a_password], [a_world_name])
        self.__send(command)

    def getEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("GET_EPOCH", [a_login, a_password], [a_world_name])
        self.__send(command)

    def __send(self, a_command):
        link = TUScomm.CommLink('127.0.0.1', 2222)
        link.exchange_xmls(a_command)

