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

def getObjectsWithProperties(aObjectName, aFileName, aPropFileName):
    """Extracts objects and properties, and combines them in one map"""
    oDict = getObjectsAsMap(aFileName, aObjectName)
    pDict = getPropertiesAsMap(aPropFileName, aObjectName)

    for i, ob in pDict.items():
        for p, v in ob.items():
            oDict[i][p]=v
    return oDict
    
def prepareBuildings(aFileName, aPropFileName):
    """Extracts buildings and its properties from given files"""
    return getObjectsWithProperties('building', aFileName, aPropFileName)
 
def prepareHumans(aFileName, aPropFileName):
    """Extracts humans from given file"""
    return getObjectsWithProperties('human', aFileName, aPropFileName)
 
def prepareResources(aFileName):
    """Extracts resources from given file"""
    return getObjectsAsMap(aFileName, 'resource')


# Functions for presenting the data

def printPossibleResources(aResourceDict):
    """Prints resources' definitions from given file in one line format."""
    # resources.resource.{key|name} 
    for i, r in aResourceDict.items():
        print( r['name'])

def printPossibleHumans(aHumansDict):
    """Prints engageable humans' definitions from given file in one line format."""
    # humans.human.{key|class|name|experience} 
    print( "{0:>10}{1:>16}{2:>6}{3:>6}#".format('class', 'name', 'dism.','prod.'))
    print( "{0:->10}{1:->16}{2:->6}{3:->6}#".format('', '', '',''))
    for i, h in aHumansDict.items():
        if h['engageable'] == 'true':
            print( "{0:>10}{1:>16}{2:>6}{3:>6}".format(
                h['class'], h['name'], h['dismissable'], h['production']))

def printPossibleBuildings(aBuildingsDict):
    """Prints buildings' definitions from given files in one line format."""
    # buildings.building.{key|class|name} 
    print( "{0:>10}{1:>20}{2:>6}#".format('class', 'name', 'cap.'))
    print( "{0:->10}{1:->20}{2:->6}#".format('', '', ''))
    for i, b in aBuildingsDict.items():
        print( "{0:>10}{1:>20}{2:>6}".format(
            b['class'], b['name'], b['capacity']))


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
    
    hFile =  dataRoot + '/Human/humans.xml'
    hpFile = dataRoot + '/Human/properties.xml'
    bFile =  dataRoot + '/Building/buildings.xml'
    bpFile = dataRoot + '/Building/properties.xml'
    rFile =  dataRoot + '/Resource/resources.xml'
    
    humans = prepareHumans(hFile, hpFile) 
    buildings = prepareBuildings(bFile, bpFile) 
    resources = prepareResources(rFile) 
    
    if type == 'humans' :
        printPossibleHumans(humans)
    elif type == 'buildings':
        printPossibleBuildings(buildings)
    elif type == 'resources':
        printPossibleResources(resources)
    else:
        pprint( humans )
        pprint( buildings )
        pprint( resources )
    
    return 0
    
if __name__ == "__main__":
    sys.exit(main())
