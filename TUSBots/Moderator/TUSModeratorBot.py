#!/usr/bin/env python3

# Name: TUSModeratorBot.py
# Description: A moderator bot.
# Author: Marcin Skrobiranda.

import sys
sys.path.append("../../TUSPythonInterface")

import TUSInterface

from time import sleep

# Define "constants".
MODBOT_LOGIN = "modbot"
MODBOT_PASSWORD = "modbotpass"
WORLD_NAME = "World"
EPOCH_NAME = "Epoch"

interface = TUSInterface.TUSInterface()

interface.createWorld(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
interface.createEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME, EPOCH_NAME)
interface.activateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)

while 1:
    sleep(60)
    interface.deactivateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
    interface.tickEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
    interface.activateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
