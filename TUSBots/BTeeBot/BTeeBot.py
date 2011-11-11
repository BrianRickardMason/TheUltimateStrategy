#!/usr/bin/env python3

# Name: BTeeBot.py
# Description: giving some smartness to dullboyjack.
# Author: Bajron

import sys
sys.path.append("../../TUSPythonInterface")

from TUSUserInterface import *
from time import sleep

def dom2list( dom ):
    print (dom);
    
    
def printResponse( ret ):
    ret.normalize();
    st = int(ret.getElementsByTagName('status')[0].getAttribute('value') );
    print (st)
    print(ret.toprettyxml(indent=" ", newl=""));
    

# Define bot specific "constants".
LOGIN = "btee"
PASSWORD = "bteepasswd"

# Define names.
WORLD_NAME = "World"
LAND_NAME = "BTee Land"
SETTLEMENT_NAME = "BTee Settlement"

interface = TUSUserInterface(LOGIN, PASSWORD)

print ("Creating user") 

ret = interface.createUser()
printResponse(ret)

print ("Creating land" )
ret = interface.createLand(WORLD_NAME, LAND_NAME)
printResponse(ret)

print ("Creating settlement") 
ret = interface.createSettlement(LAND_NAME, SETTLEMENT_NAME)
printResponse(ret)

print ("Creating engaging human?") 
ret = interface.engageHuman("1", SETTLEMENT_NAME, "4", "2", "100")
printResponse(ret)

print ("Getting lands") 
ret = interface.getLands()
printResponse(ret)

print ("What now?") 

