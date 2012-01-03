#!/usr/bin/env python3

# Name: TUSUserInterface.py
# Description: The callable interface with some facilities.
# Author: Bajron.

from TUSInterface import TUSInterface
from TUSIds import *
import TUSConfiguration

def set_up_consts(aDataRoot, outResource, outBuildings, outHumans):
    """Fills in the given maps with easy to use key:data"""

    r, b, h = TUSConfiguration.read_configuration(aDataRoot)

    for i in r.values():
        outResource[i['name']] = i
    for i in b.values():
        outBuildings[i['name']] = i
    for i in h.values():
        if i['engageable'] == 'true':
            outHumans[i['name']] = i

            
def make_human_key(aHuman):
    aHuman['key'] = aHuman['humanclass'] + aHuman['humanname'] + aHuman['experience']
    return aHuman['key']

def make_building_key(aBuilding):
    aBuilding['key'] = aBuilding['buildingclass'] + aBuilding['buildingname']
    return aBuilding['key']

def make_resource_key(aResource):
    aResource['key'] = aResource['resourcename']
    return aResource['key']

def assert_human_key(aHuman):
    if not 'key' in aHuman:
        make_human_key(aHuman)

def assert_building_key(aBuilding):
    if not 'key' in aBuilding:
        make_building_key(aBuilding)

def assert_resource_key(aResource):
    if not 'key' in aResource:
        make_resource_key(aResource)
    
class TUSUserInterface(TUSInterface):
    """ TODO """

    def __init__(self, aUser, aPassword, aModerated = True):
        """ TODO """
        TUSInterface.__init__(self, aModerated)
        self.mUser = aUser
        self.mPassword = aPassword

        self.mHolder = None
        self.mHolderId = None

    def setCurrentHolder(self, aHolderId, aName):
        self.mHolderId = aHolderId
        self.mHolder = aName
     
     
    # Wrappers starts...
     
    def createUser(self):
        return TUSInterface.createUser( self, self.mUser, self.mPassword)
        
    def createWorld(self, aWorldName):
        return TUSInterface.createWorld(self, self.mUser, self.mPassword, aWorldName)

    # Epoch interface
        
    def createEpoch(self, aWorldName, aEpochName):
        return TUSInterface.createEpoch( self, self.mUser, self.mPassword, 
            aWorldName, aEpochName)

    def deleteEpoch(self, aWorldName):
        return TUSInterface.deleteEpoch( self, self.mUser, self.mPassword, 
            aWorldName)

    def activateEpoch(self, aWorldName):
        return TUSInterface.activateEpoch( self, self.mUser, self.mPassword, 
            aWorldName)

    def deactivateEpoch(self, aWorldName):
        return TUSInterface.deactivateEpoch( self, self.mUser, self.mPassword, 
            aWorldName)

    def finishEpoch(self, aWorldName):
        return TUSInterface.finishEpoch( self, self.mUser, self.mPassword, 
            aWorldName)

    def tickEpoch(self, aWorldName):
        return TUSInterface.tickEpoch( self, self.mUser, self.mPassword, 
            aWorldName)

    def getEpoch(self, aWorldName):
        return TUSInterface.getEpoch( self, self.mUser, self.mPassword, 
            aWorldName)

    # Land
        
    def createLand(self, aWorldName, aLandName):
        return TUSInterface.createLand( self, self.mUser, self.mPassword, 
            aWorldName, aLandName)

    def deleteLand(self, aLandName):
        return TUSInterface.deleteLand( self, self.mUser, self.mPassword, 
            aLandName)

    def getLand(self, aLandName):
        return TUSInterface.getLand( self, self.mUser, self.mPassword, 
            aLandName)

    def getLands(self):
        return TUSInterface.getLands( self, self.mUser, self.mPassword)

    # Settlements
        
    def createSettlement(self, aLandName, aSettlementName):
        return TUSInterface.createSettlement( self, self.mUser, self.mPassword, 
            aLandName, aSettlementName)

    def deleteSettlement(self, aSettlementName):
        return TUSInterface.deleteSettlement( self, self.mUser, self.mPassword, 
            aSettlementName)

    def getSettlement(self, aSettlementName):
        return TUSInterface.getSettlement( self, self.mUser, self.mPassword, 
            aSettlementName)

    def getSettlements(self, aLandName):
        return TUSInterface.getSettlements( self, self.mUser, self.mPassword, 
            aLandName)

    #
    # Holder actions
    #
    # Minimal call interface. "Setup and call" approach as in OpenGL for example.
    # First holder which should be used must be set, then we can examine/modify
    # the holder with the methods below.
    #
    # @see setCurrentHolder 
    #
    
    def build(self, aBuilding, aVolume):
        assert_building_key(aBuilding)
        return self.buildBuilding(self.mHolderId, self.mHolder, 
            aBuilding['key'], str(aVolume));
    
    def engage( self, aHuman, aVolume):
        assert_human_key(aHuman)
        return self.engageHuman(self.mHolderId, self.mHolder, 
            aHuman['key'], str(aVolume) );
    
    def dismiss(self, aHuman, aVolume):
        assert_human_key(aHuman)
        return self.dismissHuman(
            self.mHolderId, self.mHolder, 
            aHuman['key'], str(aVolume));
    
    def listHumans(self):
        return self.getHumans(self.mHolderId, self.mHolder)
    
    def humanDetails(self, aHuman):
        assert_human_key(aHuman)
        return self.getHuman(self.mHolderId, self.mHolder,
            aHuman['key'] );
    
    def listBuildings(self):
        return self.getBuildings(self.mHolderId, self.mHolder)
    
    def buildingDetails(self, aBuilding):
        assert_building_key(aBuilding)
        return self.getBuilding(self.mHolderId, self.mHolder,
            aBuilding['key'] )
    
    def listResources(self):
        return self.getResources(self.mHolderId, self.mHolder)
    
    def resourceDetails(self, aResource):
        assert_resource_key(aResource)
        return self.getResource(self.mHolderId, self.mHolder,
            aResource['key'] )
            
    
    # Pure holder wrappers
        
    def buildBuilding(self,
            aIdHolderClass, aHolderName, aIdBuildingKey, aVolume):
        return TUSInterface.buildBuilding( self, self.mUser, self.mPassword,
            aIdHolderClass, aHolderName, aIdBuildingKey, aVolume)

    def destroyBuilding(self,
            aIdHolderClass, aHolderName, aIdBuildingKey, aVolume):
        return TUSInterface.destroyBuilding( self, self.mUser, self.mPassword,
            aIdHolderClass, aHolderName, aIdBuildingKey, aVolume)

    def getBuilding(self,
            aIdHolderClass, aHolderName, aIdBuildingKey):
        return TUSInterface.getBuilding( self, self.mUser, self.mPassword,
            aIdHolderClass, aHolderName, aIdBuildingKey)

    def getBuildings(self, aIdHolderClass, aHolderName):
        return TUSInterface.getBuildings( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName)

    def dismissHuman(self, aIdHolderClass, aHolderName, aHumanKey, aVolume):
        return TUSInterface.dismissHuman( self, self.mUser, self.mPassword,
            aIdHolderClass, aHolderName, aHumanKey, aVolume)

    def engageHuman(self,
            aIdHolderClass, aHolderName, aIdHumandKey, aVolume):
        return TUSInterface.engageHuman( self, self.mUser, self.mPassword,
            aIdHolderClass, aHolderName, aIdHumandKey, aVolume) 

    def getHuman(self,
            aIdHolderClass, aHolderName, aIdHumandKey):
        return TUSInterface.getHuman( self, self.mUser, self.mPassword,
            aIdHolderClass, aHolderName, aIdHumandKey)

    def getHumans(self, aIdHolderClass, aHolderName):
        return TUSInterface.getHumans( self, self.mUser, self.mPassword, aIdHolderClass, aHolderName)

    def getResource(self, aIdHolderClass, aHolderName, aIdResource):
        return TUSInterface.getResource( self, self.mUser, self.mPassword, aIdHolderClass, aHolderName, aIdResource)

    def getResources(self, aIdHolderClass, aHolderName):
        return TUSInterface.getResources( self, self.mUser, self.mPassword, aIdHolderClass, aHolderName)

    def transportHuman(self,
            aSettlementNameSource, aSettlementNameDestination, aIdHumandClass, aIdHuman,
            aExperience, aVolume):
        return TUSInterface.transportHuman( self, self.mUser, self.mPassword,
            aSettlementNameSource, aSettlementNameDestination, aIdHumandClass + aIdHuman + aExperience, aVolume)

    def transportResource(self,
            aSettlementNameSource, aSettlementNameDestination, aIdResource, aVolume):
        return TUSInterface.transportResource( self, self.mUser, self.mPassword,
            aSettlementNameSource, aSettlementNameDestination, aIdResource, aVolume)


