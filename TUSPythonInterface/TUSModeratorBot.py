#!/usr/bin/env python3

# Name: TUSEchoBot.py
# Description: A moderator bot.
# Author: Marcin Skrobiranda.

import TUSInterface

from time import sleep

interface = TUSInterface.TUSInterface()

interface.createWorld("modbot", "modbotpass", "world1")
interface.createEpoch("modbot", "modbotpass", "world1", "epoch1")
interface.activateEpoch("modbot", "modbotpass", "world1")

while 1:
    sleep(60)
    interface.deactivateEpoch("modbot", "modbotpass", "world1")
    interface.tickEpoch("modbot", "modbotpass", "world1")
    interface.activateEpoch("modbot", "modbotpass", "world1")
