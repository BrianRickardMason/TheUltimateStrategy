#!/usr/bin/env python3

# Name: TUSModeratorBot.py
# Description: "Moderator" bot.
# Author: Marcin Skrobiranda.

import sys
sys.path.append("../../TUSPythonInterface")

import TUSInterface

from time import sleep

# Define bot specific "constants".
MODBOT_LOGIN = "modbot"
MODBOT_PASSWORD = "modbotpass"

# Define tournament specific "constants".
NUMBER_OF_EPOCHS = 1
NUMBER_OF_TICKS = 20
SLEEP_BETWEEN_TICKS = 3

# Define names.
WORLD_NAME = "World"
EPOCH_NAME = "Epoch"

interface = TUSInterface.TUSInterface()

# Create the world.
# TODO: Delete the world is needed to be bullet proof.
interface.createWorld(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)

# Control the tournament of X epochs.
for epoch in range(NUMBER_OF_EPOCHS):
    epoch_name = EPOCH_NAME + repr(epoch)
    interface.createEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME, epoch_name)
    interface.activateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)

    # Control the epoch of X ticks.
    for tick in range(NUMBER_OF_TICKS):
        sleep(SLEEP_BETWEEN_TICKS)
        interface.deactivateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
        interface.tickEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
        interface.activateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)

    interface.deactivateEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
    interface.finishEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
    interface.deleteEpoch(MODBOT_LOGIN, MODBOT_PASSWORD, WORLD_NAME)
    
del interface
