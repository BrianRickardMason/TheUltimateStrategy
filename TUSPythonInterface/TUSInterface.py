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

    def echo(self):
        command = self.m_command_builder.build("ECHO", [], [])
        return self.__send(command)

    def createWorld(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("CREATE_WORLD", [a_login, a_password], [a_world_name])
        print("CREATE_WORLD(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def createEpoch(self, a_login, a_password, a_world_name, a_epoch_name):
        command = self.m_command_builder.build("CREATE_EPOCH", [a_login, a_password], [a_world_name, a_epoch_name])
        print("CREATE_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ", " + a_epoch_name + ")")
        return self.__send(command)

    def deleteEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("DELETE_EPOCH", [a_login, a_password], [a_world_name])
        print("DELETE_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def activateEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("ACTIVATE_EPOCH", [a_login, a_password], [a_world_name])
        print("ACTIVATE_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def deactivateEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("DEACTIVATE_EPOCH", [a_login, a_password], [a_world_name])
        print("DEACTIVATE_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def finishEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("FINISH_EPOCH", [a_login, a_password], [a_world_name])
        print("FINISH_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def tickEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("TICK_EPOCH", [a_login, a_password], [a_world_name])
        print("TICK_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def getEpoch(self, a_login, a_password, a_world_name):
        command = self.m_command_builder.build("GET_EPOCH", [a_login, a_password], [a_world_name])
        print("GET_EPOCH(" + a_login + ", " + a_password + ", " + a_world_name + ")")
        return self.__send(command)

    def createUser(self, a_login, a_password):
        command = self.m_command_builder.build("CREATE_USER", [], [a_login, a_password])
        return self.__send(command)

    def createLand(self, a_login, a_password, a_world_name, a_land_name):
        command = self.m_command_builder.build("CREATE_LAND", [a_login, a_password], [a_world_name, a_land_name])
        return self.__send(command)

    def deleteLand(self, a_login, a_password, a_land_name):
        command = self.m_command_builder.build("DELETE_LAND", [a_login, a_password], [a_land_name])
        return self.__send(command)

    def getLand(self, a_login, a_password, a_land_name):
        command = self.m_command_builder.build("GET_LAND", [a_login, a_password], [a_land_name])
        return self.__send(command)

    def getLands(self, a_login, a_password):
        command = self.m_command_builder.build("GET_LANDS", [a_login, a_password], [])
        return self.__send(command)

    def createSettlement(self, a_login, a_password, a_land_name, a_settlement_name):
        command = self.m_command_builder.build("CREATE_SETTLEMENT", [a_login, a_password], [a_land_name, a_settlement_name])
        return self.__send(command)

    def deleteSettlement(self, a_login, a_password, a_settlement_name):
        command = self.m_command_builder.build("DELETE_SETTLEMENT", [a_login, a_password], [a_settlement_name])
        return self.__send(command)

    def getSettlement(self, a_login, a_password, a_settlement_name):
        command = self.m_command_builder.build("GET_SETTLEMENT", [a_login, a_password], [a_settlement_name])
        return self.__send(command)

    def getSettlements(self, a_login, a_password, a_land_name):
        command = self.m_command_builder.build("GET_SETTLEMENTS", [a_login, a_password], [a_land_name])
        return self.__send(command)

    def buildBuilding(self,
                      a_login,
                      a_password,
                      a_id_holder_class,
                      a_holder_name,
                      a_id_building_class,
                      a_id_building,
                      a_volume):
        command = self.m_command_builder.build("BUILD_BUILDING",
                                               [a_login, a_password],
                                               [a_id_holder_class,
                                                a_holder_name,
                                                a_id_building_class,
                                                a_id_building,
                                                a_volume])
        return self.__send(command)

    def destroyBuilding(self,
                        a_login,
                        a_password,
                        a_id_holder_class,
                        a_holder_name,
                        a_id_building_class,
                        a_id_building,
                        a_volume):
        command = self.m_command_builder.build("DESTROY_BUILDING",
                                               [a_login, a_password],
                                               [a_id_holder_class,
                                                a_holder_name,
                                                a_id_building_class,
                                                a_id_building,
                                                a_volume])
        return self.__send(command)

    def getBuilding(self,
                    a_login,
                    a_password,
                    a_id_holder_class,
                    a_holder_name,
                    a_id_building_class,
                    a_id_building):
        command = self.m_command_builder.build("GET_BUILDING",
                                               [a_login, a_password],
                                               [a_id_holder_class, a_holder_name, a_id_building_class, a_id_building])
        return self.__send(command)

    def getBuildings(self,
                    a_login,
                    a_password,
                    a_id_holder_class,
                    a_holder_name):
        command = self.m_command_builder.build("GET_BUILDINGS",
                                               [a_login, a_password],
                                               [a_id_holder_class, a_holder_name])
        return self.__send(command)

    def dismissHuman(self,
                     a_login,
                     a_password,
                     a_id_holder_class,
                     a_holder_name,
                     a_id_human_class,
                     a_id_human,
                     a_experience,
                     a_volume):
        command = self.m_command_builder.build("DISMISS_HUMAN",
                                               [a_login, a_password],
                                               [a_id_holder_class,
                                                a_holder_name,
                                                a_id_human_class,
                                                a_id_human,
                                                a_experience,
                                                a_volume])
        return self.__send(command)

    def engageHuman(self,
                    a_login,
                    a_password,
                    a_id_holder_class,
                    a_holder_name,
                    a_id_human_class,
                    a_id_human,
                    a_volume):
        command = self.m_command_builder.build("ENGAGE_HUMAN",
                                               [a_login, a_password],
                                               [a_id_holder_class,
                                                a_holder_name,
                                                a_id_human_class,
                                                a_id_human,
                                                a_volume])
        return self.__send(command)

    def getHuman(self,
                 a_login,
                 a_password,
                 a_id_holder_class,
                 a_holder_name,
                 a_id_human_class,
                 a_id_human,
                 a_experience):
        command = self.m_command_builder.build("GET_HUMAN",
                                               [a_login, a_password],
                                               [a_id_holder_class, a_holder_name, a_id_human_class, a_id_human, a_experience])
        return self.__send(command)

    def getHumans(self,
                  a_login,
                  a_password,
                  a_id_holder_class,
                  a_holder_name):
        command = self.m_command_builder.build("GET_HUMANS",
                                               [a_login, a_password],
                                               [a_id_holder_class, a_holder_name])
        return self.__send(command)

    def getResource(self, a_login, a_password, a_id_holder_class, a_holder_name, a_id_resource):
        command = self.m_command_builder.build("GET_RESOURCE",
                                               [a_login, a_password],
                                               [a_id_holder_class, a_holder_name, a_id_resource])
        return self.__send(command)

    def getResources(self, a_login, a_password, a_id_holder_class, a_holder_name):
        command = self.m_command_builder.build("GET_RESOURCES",
                                               [a_login, a_password],
                                               [a_id_holder_class, a_holder_name])
        return self.__send(command)

    def transportHuman(self,
                       a_login,
                       a_password,
                       a_settlement_name_source,
                       a_settlement_name_destination,
                       a_id_human_class,
                       a_id_human,
                       a_experience,
                       a_volume):
        command = self.m_command_builder.build("TRANSPORT_HUMAN",
                                               [a_login, a_password],
                                               [a_settlement_name_source,
                                                a_settlement_name_destination,
                                                a_id_human_class,
                                                a_id_human,
                                                a_experience,
                                                a_volume])
        return self.__send(command)

    def transportResource(self,
                          a_login,
                          a_password,
                          a_settlement_name_source,
                          a_settlement_name_destination,
                          a_id_resource,
                          a_volume):
        command = self.m_command_builder.build("TRANSPORT_RESOURCE",
                                               [a_login, a_password],
                                               [a_settlement_name_source,
                                                a_settlement_name_destination,
                                                a_id_resource,
                                                a_volume])
        return self.__send(command)

    def __send(self, a_command):
        link = TUScomm.CommLink('127.0.0.1', 2222)
        return link.exchange_xmls(a_command)

