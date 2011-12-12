#!/usr/bin/env python3

# Name: BTeeBot.py
# Description: moredullboyjack.
# Author: Bajron

import sys, os
MDIR = os.path.dirname(sys.argv[0])

sys.path.append(MDIR + "/../../TUSPythonInterface")
sys.path.append(MDIR + "/../Moderator")

from TUSUserInterface import *
from TUSDictionary import *

from time import sleep

def remove_whitespace_nodes(dom):
    from xml.dom.minidom import Node
    if dom.hasChildNodes() :
        for ch in dom.childNodes:
            remove_whitespace_nodes(ch)
    elif dom.nodeType == Node.TEXT_NODE and dom.data.strip(" \t\n\r") == '' :
        dom.data = ''

def clean_up_reply(dom):
    remove_whitespace_nodes(dom)
    dom.normalize();
    return dom

def print_response( ret, full = False ):
    # get status and message
    st = int(ret.getElementsByTagName('status')[0].getAttribute('value') );

    msgs = ret.getElementsByTagName('message');
    msg = "" if not msgs else msgs[0].getAttribute('value');

    print ( "Reply is: " + REPLY_STATUSES[st] + " / " + msg)
    # print the whole message
    if(full or st != 10):
        remove_whitespace_nodes(ret)
        ret.normalize();
        print(ret.toprettyxml(indent="    ", newl="\n"));

def extract_items(aItemTagName, aReply):
    clean_up_reply(aReply)
    ret = []
    for obj in aReply.getElementsByTagName(aItemTagName):
        item = {}
        for ch in obj.childNodes:
            # 'value' attribute variant
            item[ch._get_localName()] = ch.getAttribute('value')
            # Tag contents variant below
            #item[ch._get_localName()]  = ch.firstChild.nodeValue

        ret.append(item)
    return ret

LAND = ['login','world_name','land_name','granted']
SITE = ['land_name', 'settlement_name']
BUILDING =['buildingclass','buildingname','volume']
HUMAN = ['humanclass','humanname','experience','volume']
RESOURCE =['resourcename','volume']

def extract(tags, elements):
    ret = []
    for obj in elements:
        item = {}
        for tag in tags:
            item[tag] = obj.getElementsByTagName(tag)[0].getAttribute('value')
        ret.append(item)
    return ret

################################################################################

B,H,R = {},{},{}
set_up_consts(MDIR + '/../../TUSCore/GameServer/Configuration/Data/Test',R,B,H)
#
# now use short name to get the object map
# B['farm'] == {'name':'farm', 'class':'regular', ... }
#

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
TICK_LEN = 3
SETTLEMENT_NAME = "BTee Settlement"
ID_HOLDER_CLASS_SETTLEMENT = "1" # ????

print ("Creating user")

ret = interface.createUser()
print_response(ret)

print ("Creating land" )
ret = interface.createLand(WORLD_NAME, LAND_NAME)
print_response(ret)

print ("Creating settlement")
ret = interface.createSettlement(LAND_NAME, SETTLEMENT_NAME)
print_response(ret)

print( "Building...")
interface.setCurrentHolder(ID_HOLDER_CLASS_SETTLEMENT, SETTLEMENT_NAME)

ret = interface.build(B['farm'], 2)
print_response(ret)

ret = interface.build(B["sawmill"], 1)
print_response(ret)

ret = interface.build(B["marketplace"], 1)
print_response(ret)

ret = interface.build(B["mine"], 1)
print_response(ret)

ret = interface.build(B["quarry"], 1)
print_response(ret)

ret = interface.build(B["steelworks"], 1)
print_response(ret)

print ("Engaging human")

ret = interface.engage(H["farmer"] , 10)
print_response(ret)

ret = interface.engage(H["lumberjack"] , 5)
print_response(ret)

ret = interface.engage(H["merchant"], 5)
print_response(ret)

ret = interface.engage(H["miner"], 5)
print_response(ret)

ret = interface.engage(H["stone mason"], 5)
print_response(ret)

ret = interface.engage(H["breeder"], 5)
print_response(ret)

ret = interface.engage(H["steelworker"], 1)
print_response(ret)

ret = interface.engage(H["fisherman"], 3)
print_response(ret)

print ("Dismissing jobless")
ret = interface.dismiss( {'key':'workerjoblessnovice'}, 750)
print_response(ret)

# Take a look around

print ("Getting epoch")
ret = interface.getEpoch(WORLD_NAME)
print_response(ret, True)

print ("Getting lands")
ret = interface.getLands()
print_response(ret)

lands = extract(LAND, ret.getElementsByTagName('object'));

for land in lands:
    ret = interface.getLand(land['land_name']);
    print_response(ret)

    ret = interface.getSettlements(land['land_name']);
    print_response(ret)
    sites = extract(SITE, ret.getElementsByTagName('object'))

    land['_sites'] = sites

    for site in sites:
        ret = interface.getSettlement( site['settlement_name'] )
        print_response(ret)

        interface.setCurrentHolder( ID_HOLDER_CLASS_SETTLEMENT, site['settlement_name'])

        ret = interface.listHumans()
        print_response(ret,True);
        humans = extract_items('object', ret)

        site['_humans'] = humans

        for h in humans:
            ret = interface.humanDetails(h)
            print_response(ret)

        ret = interface.listBuildings()
        print_response(ret)
        buildings = extract_items('object', ret);

        site['_buildings'] = buildings

        for b in buildings:
            ret = interface.buildingDetails(b)
            print_response(ret)

        ret = interface.listResources()
        print_response(ret, True)
        resources = extract_items('object',ret)

        site['_resources'] = resources

        for r in resources:
            ret = interface.resourceDetails(r)
            print_response(ret)


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

rDict = {}
for i,r in R.items():
    rDict[r['name']] = []

hDict = {}

interface.setCurrentHolder( ID_HOLDER_CLASS_SETTLEMENT, SETTLEMENT_NAME)

for iEpoch in range(NUMBER_OF_EPOCHS):
    for iTick in range(NUMBER_OF_TICKS):
        print(iTick)
        ret = interface.listResources()
        res = extract_items('object', ret);
        for r in res:
            rDict[r['resourcename']].append( int(r['volume']) )
        print( res)

        ret = interface.listHumans()
        hum = extract_items('object', ret)
        for h in hum:
            assert_human_key(h)
            if not h['key'] in hDict :
                hDict[h['key']] = iEpoch * [0]
            hDict[h['key']].append( int(h['volume']) )

            #hVol.append( int( hum[0]['volume']) )
            #hExp.append( int( hum[0]['experience']) )

        sleep(SLEEP_BETWEEN_TICKS)

for i,r in rDict.items():
    print( pRVec( r, "res_"+str(i)) + ";")
for i,h in hDict.items():
    print( pRVec( h, "hum_"+str(i)) + ";")
#print(pRVec( hExp, "hExp") + ";")
#print(pRVec( hVol, "hVol") + ";")
