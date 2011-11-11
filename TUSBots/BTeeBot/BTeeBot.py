#!/usr/bin/env python3

# Name: BTeeBot.py
# Description: moredullboyjack.
# Author: Bajron

import sys
sys.path.append("../../TUSPythonInterface")

from TUSUserInterface import *
from TUSDictionary import *
from time import sleep

def removeWsNodes(dom):
    from xml.dom.minidom import Node
    if dom.hasChildNodes() :
        for ch in dom.childNodes:
            removeWsNodes(ch)
    elif dom.nodeType == Node.TEXT_NODE and dom.data.strip(" \t\n\r") == '' :
        dom.data = ''
    
def printResponse( ret ):
    # get status and message
    st = int(ret.getElementsByTagName('status')[0].getAttribute('value') );
    
    msgs = ret.getElementsByTagName('message');
    msg = "" if not msgs else msgs[0].getAttribute('value');
    
    print ( "Reply is: " + REPLY_STATUSES[st] + " / " + msg)
    # print the whole message
    removeWsNodes(ret)
    ret.normalize();
    print(ret.toprettyxml(indent="    ", newl="\n"));
    
LAND = ['login','world_name','land_name','granted']
SITE = ['land_name', 'settlement_name']
BUILDING =['idbuildingclass','idbuilding','volume']
HUMAN = ['idhumanclass','idhuman','experience','volume']
RESOURCE =['idresource','volume']

def extract(tags, elements):
    ret = []
    for obj in elements:
        item = {}
        for tag in tags:
            item[tag] = obj.getElementsByTagName(tag)[0].getAttribute('value')
        ret.append(item)
    return ret
    
# Define bot specific "constants".
LOGIN = "btee"
PASSWORD = "bteepasswd"
interface = TUSUserInterface(LOGIN, PASSWORD)

# Define names.
WORLD_NAME = "World"
LAND_NAME = "BTee Land"
SETTLEMENT_NAME = "BTee Settlement"

print ("Creating user") 

ret = interface.createUser()
printResponse(ret)

print ("Creating land" )
ret = interface.createLand(WORLD_NAME, LAND_NAME)
printResponse(ret)

print ("Creating settlement") 
ret = interface.createSettlement(LAND_NAME, SETTLEMENT_NAME)
printResponse(ret)

print ("Engaging human?") 
# aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aVolume
ret = interface.engageHuman("1", SETTLEMENT_NAME, "4", "2", "10")
printResponse(ret)

print( "Building...")
ret = interface.buildBuilding("1", SETTLEMENT_NAME, "4", "2", "1")
printResponse(ret)


# Take a look around

print ("Getting epoch")
ret = interface.getEpoch(WORLD_NAME)
printResponse(ret)

print ("Getting lands")
ret = interface.getLands()
printResponse(ret)

lands = extract(LAND, ret.getElementsByTagName('object'));
    
for land in lands:
    ret = interface.getLand(land['land_name']);
    printResponse(ret)
    
    ret = interface.getSettlements(land['land_name']);
    printResponse(ret)
    sites = extract(SITE, ret.getElementsByTagName('object'))
    
    land['_sites'] = sites
    
    site_class = "1" # ????
    for site in sites:
        ret = interface.getSettlement( site['settlement_name'] )
        printResponse(ret)
        
        ret = interface.getHumans( site_class, site['settlement_name'])
        printResponse(ret);
        humans = extract(HUMAN, ret.getElementsByTagName('object'))
        
        site['_humans'] = humans
        
        for h in humans:
            ret = interface.getHuman( 
                site_class, site['settlement_name'], h['idhumanclass'], h['idhuman'], h['experience'] )
            printResponse(ret)
        
        ret = interface.getBuildings( site_class, site['settlement_name'])
        printResponse(ret)
        buildings = extract(BUILDING, ret.getElementsByTagName('object'));
        
        site['_buildings'] = buildings
        
        for b in buildings:
            ret = interface.getBuilding( 
                site_class, site['settlement_name'], b['idbuildingclass'], b['idbuilding'] )
            printResponse(ret)
        
        ret = interface.getResources( site_class, site['settlement_name'] )
        printResponse(ret)
        resources = extract(RESOURCE, ret.getElementsByTagName('object'))
        
        site['_resources'] = resources
        
        for r in resources:
            ret = interface.getResource( 
                site_class, site['settlement_name'], r['idresource'] )
            printResponse(ret)


from pprint import pprint

pprint( lands, indent=4)

print( "What now?") 

