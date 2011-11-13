#!/usr/bin/env python3

# Name: BTeeBot.py
# Description: moredullboyjack.
# Author: Bajron

import sys
sys.path.append("../../TUSPythonInterface")
sys.path.append("../Moderator")

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
    
def printResponse( ret, full = False ):
    # get status and message
    st = int(ret.getElementsByTagName('status')[0].getAttribute('value') );
    
    msgs = ret.getElementsByTagName('message');
    msg = "" if not msgs else msgs[0].getAttribute('value');
    
    print ( "Reply is: " + REPLY_STATUSES[st] + " / " + msg)
    # print the whole message
    if(full):
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

# synchronize with modbot, TODO better way
NUMBER_OF_EPOCHS = 1
NUMBER_OF_TICKS = 20
SLEEP_BETWEEN_TICKS = 3
    
# Define bot specific "constants".
LOGIN = "btee"
PASSWORD = "bteepasswd"
interface = TUSUserInterface(LOGIN, PASSWORD)

# Define names.
WORLD_NAME = "World"
LAND_NAME = "BTee Land"
TICK_LEN = 20
SETTLEMENT_NAME = "BTee Settlement"
ID_HOLDER_CLASS_SETTLEMENT = "1" # ????

print ("Creating user") 

ret = interface.createUser()
printResponse(ret)

print ("Creating land" )
ret = interface.createLand(WORLD_NAME, LAND_NAME)
printResponse(ret)

print ("Creating settlement") 
ret = interface.createSettlement(LAND_NAME, SETTLEMENT_NAME)
printResponse(ret)

print( "Building...")
ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_FARM, 2)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_SAWMILL, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_MARKETPLACE, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_MINE, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_QUARRY, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_SCHOOL, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_TEMPLE, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_HOUSE, 20)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_FORGE, 1)
printResponse(ret)

ret = interface.buildOn(SETTLEMENT_NAME, ID_BUILDING_REGULAR_STEELWORKS, 1)
printResponse(ret)

print ("Engaging human") 
# aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aVolume
ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_FARMER , 10)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_LUMBERJACK , 5)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_MERCHANT, 5)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_MINER, 5)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_STONE_MASON, 5)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_TEACHER, 5)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_PRIEST, 1)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_DRUID, 1)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_OFFICIAL, 1)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_BREEDER, 5)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_BLACKSMITH, 1)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_STEELWORKER, 1)
printResponse(ret)

ret = interface.humanTo(SETTLEMENT_NAME, ID_HUMAN_WORKER_FISHERMAN, 3)
printResponse(ret)

print ("Dismissing jobless") 
ret = interface.dismissFrom(SETTLEMENT_NAME, ID_HUMAN_WORKER_JOBLESS, 1, 750)
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
    
    for site in sites:
        ret = interface.getSettlement( site['settlement_name'] )
        printResponse(ret)
        
        ret = interface.getHumans( ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'])
        printResponse(ret);
        humans = extract(HUMAN, ret.getElementsByTagName('object'))
        
        site['_humans'] = humans
        
        for h in humans:
            ret = interface.getHuman( 
                ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'], h['idhumanclass'], h['idhuman'], h['experience'] )
            printResponse(ret)
        
        ret = interface.getBuildings( ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'])
        printResponse(ret)
        buildings = extract(BUILDING, ret.getElementsByTagName('object'));
        
        site['_buildings'] = buildings
        
        for b in buildings:
            ret = interface.getBuilding( 
                ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'], b['idbuildingclass'], b['idbuilding'] )
            printResponse(ret)
        
        ret = interface.getResources( ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'] )
        printResponse(ret)
        resources = extract(RESOURCE, ret.getElementsByTagName('object'))
        
        site['_resources'] = resources
        
        for r in resources:
            ret = interface.getResource( 
                ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'], r['idresource'] )
            printResponse(ret)


from pprint import pprint

pprint( lands, indent=4)

print( "What now?") 

def pRVec(aList,aName):
    s = ""
    s += aName + " <- c("
    first = True
    for el in aList:
        if not first:
            s += ", "
        else :
            first = False
        s += str(el)
    s += ")"
    return s

print( pRVec([1,2,3],"test"))

rSize = 7
rList = []
for i in range(rSize):
    rList.append([])

hList = []

for iEpoch in range(NUMBER_OF_EPOCHS):
    for iTick in range(NUMBER_OF_TICKS):
        print(iTick)
        ret = interface.getResources( ID_HOLDER_CLASS_SETTLEMENT, SETTLEMENT_NAME )
        res = extract(RESOURCE, ret.getElementsByTagName('object'));
        for r in res:
            rList[( int(r['idresource']) -1)].append( int(r['volume']) )
        print( res)
        
        ret = interface.getHumans( ID_HOLDER_CLASS_SETTLEMENT, SETTLEMENT_NAME)
        hum = extract(HUMAN, ret.getElementsByTagName('object'))
        if(hum):
            if not hList :
                for i in range(len(hum)):
                    hList.append([])
            for i in range(len(hList)):
                hList[i].append(hum[i]['volume'])

            #hVol.append( int( hum[0]['volume']) )
            #hExp.append( int( hum[0]['experience']) )
        
        sleep(SLEEP_BETWEEN_TICKS)

for r in range(rSize):
    print( pRVec( rList[r], "res"+str(r)) + ";")
for h in range(len(hList)):
    print( pRVec( hList[h], "hum"+str(h)) + ";")
#print(pRVec( hExp, "hExp") + ";")
#print(pRVec( hVol, "hVol") + ";")
