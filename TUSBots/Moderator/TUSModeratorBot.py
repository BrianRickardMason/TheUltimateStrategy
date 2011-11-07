#!/usr/bin/env python3

# Name: TUSModeratorBot.py
# Description: A moderator bot.
# Author: Marcin Skrobiranda.

import sys
sys.path.append("../../TUSPythonInterface")

import TUSInterface

from time import sleep

interface = TUSInterface.TUSInterface()

interface.createWorld("modbot", "modbotpass", "World")
interface.createEpoch("modbot", "modbotpass", "World", "Epoch")
interface.activateEpoch("modbot", "modbotpass", "World")

while 1:
    sleep(60)
    interface.deactivateEpoch("modbot", "modbotpass", "World")
    interface.tickEpoch("modbot", "modbotpass", "World")
    interface.activateEpoch("modbot", "modbotpass", "World")
