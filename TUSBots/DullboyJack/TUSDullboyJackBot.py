#!/usr/bin/env python3

# Name: TUSDullboyJackBot.py
# Description: "Dullboy Jack" bot.
# Author: Marcin Skrobiranda.

import sys
sys.path.append("../../TUSPythonInterface")

import TUSInterface

from time import sleep

# Define bot specific "constants".
LOGIN = "DullboyJack"
PASSWORD = "DullboyJackPassword"

# Define names.
WORLD_NAME = "World"
LAND_NAME = "Land"
SETTLEMENT_NAME = "Settlement"

interface = TUSInterface.TUSInterface()

interface.createUser(LOGIN, PASSWORD)
interface.createLand(LOGIN, PASSWORD, WORLD_NAME, LAND_NAME)
interface.createSettlement(LOGIN, PASSWORD, LAND_NAME, SETTLEMENT_NAME)
interface.engageHuman(LOGIN, PASSWORD, "1", SETTLEMENT_NAME, "4", "2", "100")

