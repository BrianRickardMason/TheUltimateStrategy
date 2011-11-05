#!/usr/bin/env python3

# Name: TUSEchoBot.py
# Description: An exemplary echo bot.
# Author: Marcin Skrobiranda.

# TODO: This naive implementation must be removed soon.

import TUScomm

from TUSCommandBuilder import *

command_builder = CommandBuilder()

command = command_builder.build("ECHO", [], [])

link = TUScomm.CommLink('127.0.0.1', 2222)

xml = link.exchange_xmls(command)
