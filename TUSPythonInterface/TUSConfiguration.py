#!/usr/bin/python

# Description: Extract stuff from server configuration. xml practice
# Author: bkramarski 

from xml.dom.minidom import *
from pprint import *

def removeWsNodes(dom):
	from xml.dom.minidom import Node
	if dom.hasChildNodes() :
		for ch in dom.childNodes:
			removeWsNodes(ch)
	elif dom.nodeType == Node.TEXT_NODE and dom.data.strip(" \t\n\r") == '' :
	    dom.data = ''

def normalizeTotally(dom):
	removeWsNodes(dom)
	dom.normalize()

def getObjectsAsMap(aFileName, aObjectTagName):
	root = parse(aFileName)
	normalizeTotally(root)

	# humans.human.{key|class|name|experience} 

	xList = root.getElementsByTagName(aObjectTagName);
	oList = {}

	for x in xList:
		h = {}
		for ch in x.childNodes:
			h[ ch._get_localName() ] = ch.firstChild.nodeValue
		oList[ h['key'] ] = h
	return oList

def printPossibleResources(aFileName):
	# resources.resource.{key|name} 

	hList = getObjectsAsMap(aFileName, 'resource')
	for i, r in hList.iteritems():
		print( r['name'])
	
def printPossibleHumans(aFileName):
	# humans.human.{key|class|name|experience} 

	hList = getObjectsAsMap(aFileName, 'human')
	for i, h in hList.iteritems():
		if h['experience'] == 'novice':
			print( h['class'] + '/' + h['name'])

def getBuildingProperties(aFileName):
	root = parse(aFileName)
	normalizeTotally(root)
	
	bList = root.getElementsByTagName('building')
	oDict = {}
	for b in bList:
		k = b.getAttribute('key');
		props = {}
		for ch in b.childNodes:
			props[ ch._get_localName() ] = ch.getAttribute('value')
		oDict[k] = props
	return oDict
	
def printPossibleBuildings(aFileName, aPropFileName):
	# buildings.building.{key|class|name} 

	bList = getObjectsAsMap(aFileName, 'building')
	pList = getBuildingProperties(aPropFileName)
	
	for i, b in pList.iteritems():
		for p, v in b.iteritems():
			bList[i][p]=v
	
	for i, b in bList.iteritems():
		print( b['class'] + '/' + b['name'] + '/' + b['capacity'])
			
import sys

type = sys.argv[1]
#file = sys.argv[2]

hFile = '/home/bkramarski/tus/TheUltimateStrategy/TUSCore/GameServer/Configuration/Data/Test/Human/humans.xml'
bFile =  '/home/bkramarski/tus/TheUltimateStrategy/TUSCore/GameServer/Configuration/Data/Test/Building/buildings.xml'
bpFile = '/home/bkramarski/tus/TheUltimateStrategy/TUSCore/GameServer/Configuration/Data/Test/Building/properties.xml'
rFile = '/home/bkramarski/tus/TheUltimateStrategy/TUSCore/GameServer/Configuration/Data/Test/Resource/resources.xml'

if type == 'humans' :
	printPossibleHumans(hFile)
elif type == 'buildings':
	printPossibleBuildings(bFile, bpFile)
elif type == 'resources':
	printPossibleResources(rFile)

