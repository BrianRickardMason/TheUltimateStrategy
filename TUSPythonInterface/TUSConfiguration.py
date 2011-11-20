#!/usr/bin/env python3
"""Extract stuff from server configuration."""

# Author: bkramarski 

from xml.dom.minidom import *
from pprint import *

def removeWsNodes(dom):
    """Whitespace textnodes are replaced with empty textnodes, so they can be 
    easily stripped by normalize method."""
    from xml.dom.minidom import Node
    if dom.hasChildNodes() :
        for ch in dom.childNodes:
            removeWsNodes(ch)
    elif dom.nodeType == Node.TEXT_NODE and dom.data.strip(" \t\n\r") == '' :
        dom.data = ''

def normalizeTotally(dom):
    """Strips whitespace textnodes from DOM Node."""
    removeWsNodes(dom)
    dom.normalize()


# TUS specific functions
    
def getObjectsAsMap(aFileName, aObjectTagName):
    """Changes dom elements to map elements {key:{arg:val, arg:val}}."""
    root = parse(aFileName)
    normalizeTotally(root)

    xList = root.getElementsByTagName(aObjectTagName);
    oList = {}

    for x in xList:
        h = {}
        for ch in x.childNodes:
            h[ ch._get_localName() ] = ch.firstChild.nodeValue
        oList[ h['key'] ] = h
    return oList

def getPropertiesAsMap(aFileName, aObjectTagName):
    """Extracts properties from the file as map {key: {prop:val}}."""
    root = parse(aFileName)
    normalizeTotally(root)

    bList = root.getElementsByTagName(aObjectTagName)
    oDict = {}
    for b in bList:
        k = b.getAttribute('key');
        props = {}
        for ch in b.childNodes:
            props[ ch._get_localName() ] = ch.getAttribute('value')
        oDict[k] = props
    return oDict

def getCostAsMap(aFileName, aObjectTagName):
    """Extracts cost for given object action from xml file"""
    root = parse(aFileName)
    normalizeTotally(root)
    
    obCostDict = {}
    obList = root.getElementsByTagName(aObjectTagName)
    for ob in obList:
        k = ob.getAttribute('key')
        obCostDict[k] = {}
        for act in ob.childNodes :
            cost = {}
            if act :
                for r in act.childNodes :
                    cost[r.tagName] = r.getAttribute('value')
            obCostDict[k][act.tagName] = cost
    return obCostDict
    
def getObjectsWithProperties(aObjectName, aFileName, aPropFileName='',aCostFileName=''):
    """Extracts objects and properties, and combines them in one map"""
    oDict = getObjectsAsMap(aFileName, aObjectName)

    if aPropFileName :
        pDict = getPropertiesAsMap(aPropFileName, aObjectName)
        for i, ob in pDict.items():
            for p, v in ob.items():
                oDict[i][p]=v
    if aCostFileName :
        cDict = getCostAsMap(aCostFileName, aObjectName)
        for i, ob in cDict.items():
            oDict[i]['costs'] = {}
            for c, v in ob.items():
                oDict[i]['costs'][c] = v
    return oDict

def prepareBuildings(aFileName, aPropFileName, aCostFileName):
    """Extracts buildings and its properties from given files"""
    return getObjectsWithProperties('building', aFileName, aPropFileName, aCostFileName)
 
def prepareHumans(aFileName, aPropFileName, aCostFileName):
    """Extracts humans from given file"""
    return getObjectsWithProperties('human', aFileName, aPropFileName, aCostFileName)
 
def prepareResources(aFileName):
    """Extracts resources from given file"""
    return getObjectsAsMap(aFileName, 'resource')


# Functions for presenting the data

def costFormatString(aCostDict, aWidth = 3):
    """Prepares map indexed format string for cost displaying"""
    fs = ""
    for c,v in aCostDict.items():
        fs += "{" + c + ":>"+ str(aWidth) +"}"
    return fs

def costString(aCost, aResSet = None, aWidth = 3):
    """Returns cost strings for presenting in one line."""
    fullCost = {}
    if not aResSet:
        aResSet = ['food','gold','wood','iron','rock','mana','coal']
    
    # Prepare values
    for i in aResSet:
        fullCost[i] = 0
    for c,v in aCost.items():
        fullCost[c] += int(v)
        #^^ indirect check of resource consistency
    
    fs = costFormatString(fullCost, aWidth)
    return fs.format(**fullCost)

def costHead(aResSet = None, aWidth = 3):
    """Returns cost header string."""
    if not aResSet:
        aResSet = ['food','gold','wood','iron','rock','mana','coal']
    
    resSet = {}
    # Setup header names
    for c in aResSet:
        resSet[c] = c[0]
        
    fs = costFormatString(resSet, aWidth)
    return fs.format(**resSet)    

def printPossibleResources(aResourceDict):
    """Prints resources' definitions from given file in one line format."""
    # resources.resource.{key|name} 
    for i, r in aResourceDict.items():
        print( r['name'])

# TODO: tidy up the format strings mess
        
def printPossibleHumans(aHumansDict, aEngageableOnly = True):
    """Prints engageable humans' definitions from given file in one line format."""
    # humans.human.{key|class|name|experience} 
    print( "{:>10}{:>16}{:>9}{:>6}{:>6}| e:{:->21}| d:{:->21}| l:{:->21}#".format(
        'class', 'name', 'exp.', 'dism.','prod.', costHead(), costHead(), costHead()))
    print( "{:->10}{:->16}{:->9}{:->6}{:->6}|---{:->21}|---{:->21}|---{:->21}#".format(
        '', '', '', '','','','',''))
    for i, h in aHumansDict.items():
        if aEngageableOnly and h['engageable'] != 'true':
            continue
        print( "{:>10}{:>16}{:>9}{:>6}{:>6}|   {}|   {}|   {}".format(
            h['class'], h['name'], h['experience'], h['dismissable'], h['production'],
            costString(h['costs']['engage']),
            costString(h['costs']['dismiss']),
            costString(h['costs']['live'])
        ))        
    
def printPossibleBuildings(aBuildingsDict):
    """Prints buildings' definitions from given files in one line format."""
    # buildings.building.{key|class|name} 
    print( "{0:>10}{1:>20}{2:>6}| b:{3:->21}| d:{3:->21}#".format(
        'class', 'name', 'cap.', costHead(), costHead()))
    print( "{0:->10}{1:->20}{2:->6}|---{3:->21}|---{3:->21}#".format(
        '', '', '', '',''))
    for i, b in aBuildingsDict.items():
        print( "{0:>10}{1:>20}{2:>6}|   {3}|   {4}".format(
            b['class'], b['name'], b['capacity'], 
            costString(b['costs']['build']),  
            costString(b['costs']['destroy']) 
        ))


# Common actions
def read_configuration(aDataRoot):
    """Reads all configuration data. Returns (resources, buildings, humans)."""
    hFile =  aDataRoot + '/Human/humans.xml'
    hpFile = aDataRoot + '/Human/properties.xml'
    hcFile = aDataRoot + '/Human/costs.xml'
    bFile =  aDataRoot + '/Building/buildings.xml'
    bpFile = aDataRoot + '/Building/properties.xml'
    bcFile = aDataRoot + '/Building/costs.xml'
    rFile =  aDataRoot + '/Resource/resources.xml'
    
    humans = prepareHumans(hFile, hpFile, hcFile) 
    buildings = prepareBuildings(bFile, bpFile, bcFile) 
    resources = prepareResources(rFile) 
    
    return resources, buildings, humans
        
# Handling usage as script

import sys

def main(argv=None):
    """Handles commandline call.
    
    First argument should be path to the configurtion files directory.
    Second argument can be [humans|buildings|resources] or empty, and it 
    controls what data is being printed"""
    
    if argv is None:
        argv = sys.argv

    dataRoot =  argv[1]
    type =      argv[2] if len(argv) > 2 else ''
    
    resources, buildings, humans = read_configuration(dataRoot)
    
    if type == 'humans' :
        printPossibleHumans(humans)
    elif type == 'allhumans' :
        printPossibleHumans(humans, False)
    elif type == 'buildings':
        printPossibleBuildings(buildings)
    elif type == 'resources':
        printPossibleResources(resources)
    elif type == 'all' or type == 'raw':
        pprint( humans )
        pprint( buildings )
        pprint( resources )
    else: 
        print("""
*** Use second parameter to choose data to print.
    Possible targets:
        humans      -- prints engageable humans
        allhumans   -- prints all defined humans
        buildings   -- prints buildings
        resources   -- prints resources
        all|raw     -- prints all data collected by pprint
""") 
    
    return 0
    
if __name__ == "__main__":
    sys.exit(main())
