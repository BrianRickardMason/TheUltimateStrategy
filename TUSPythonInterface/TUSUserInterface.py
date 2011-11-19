#!/usr/bin/env python3

# Name: TUSUserInterface.py
# Description: The callable interface with some facilities.
# Author: Bajron.

from TUSInterface import TUSInterface
from TUSIds import *
import TUSConfiguration

def set_up_consts(aDataRoot, outResource, outBuildings, outHumans):
    """Fills in the given maps with easy to use key:data"""
    hFile =  aDataRoot + '/Human/humans.xml'
    hpFile =  aDataRoot + '/Human/properties.xml'
    bFile =  aDataRoot + '/Building/buildings.xml'
    bpFile = aDataRoot + '/Building/properties.xml'
    rFile =  aDataRoot + '/Resource/resources.xml'
    
    b = TUSConfiguration.prepareBuildings(bFile, bpFile)
    h = TUSConfiguration.prepareHumans(hFile, hpFile);
    r = TUSConfiguration.prepareResources(rFile);
    
    for i in r.values():
        outResource[i['name']] = i
    for i in b.values():
        outBuildings[i['name']] = i
    for i in h.values():
        if i['experience'] == 'novice':
            outHumans[i['name']] = i
    
    
class TUSUserInterface(TUSInterface):
    """ TODO """

    def __init__(self, aUser, aPassword):
        """ TODO """
        TUSInterface.__init__(self)
        self.mUser = aUser
        self.mPassword = aPassword
        
        self.mCurrentSettlement = None

    def createWorld(self, aWorldName):
        return TUSInterface.createWorld(self, self.mUser, self.mPassword, aWorldName)

    def createEpoch(self, aWorldName, aEpochName):
        return TUSInterface.createEpoch( self, self.mUser, self.mPassword, aWorldName, aEpochName)

    def deleteEpoch(self, aWorldName):
        return TUSInterface.deleteEpoch( self, self.mUser, self.mPassword, aWorldName)

    def activateEpoch(self, aWorldName):
        return TUSInterface.activateEpoch( self, self.mUser, self.mPassword, aWorldName)

    def deactivateEpoch(self, aWorldName):
        return TUSInterface.deactivateEpoch( self, self.mUser, self.mPassword, aWorldName)

    def finishEpoch(self, aWorldName):
        return TUSInterface.finishEpoch( self, self.mUser, self.mPassword, aWorldName)

    def tickEpoch(self, aWorldName):
        return TUSInterface.tickEpoch( self, self.mUser, self.mPassword, aWorldName)

    def getEpoch(self, aWorldName):
        return TUSInterface.getEpoch( self, self.mUser, self.mPassword, aWorldName)

    def createUser(self):
        return TUSInterface.createUser( self, self.mUser, self.mPassword)

    def createLand(self, aWorldName, aLandName):
        return TUSInterface.createLand( self, self.mUser, self.mPassword, aWorldName, aLandName)

    def deleteLand(self, aLandName):
        return TUSInterface.deleteLand( self, self.mUser, self.mPassword, aLandName)

    def getLand(self, aLandName):
        return TUSInterface.getLand( self, self.mUser, self.mPassword, aLandName)

    def getLands(self):
        return TUSInterface.getLands( self, self.mUser, self.mPassword)

    def createSettlement(self, aLandName, aSettlementName):
        return TUSInterface.createSettlement( self, self.mUser, self.mPassword, aLandName, aSettlementName)

    def deleteSettlement(self, aSettlementName):
        return TUSInterface.deleteSettlement( self, self.mUser, self.mPassword, aSettlementName)

    def getSettlement(self, aSettlementName):
        return TUSInterface.getSettlement( self, self.mUser, self.mPassword, aSettlementName)

    def getSettlements(self, aLandName):
        return TUSInterface.getSettlements( self, self.mUser, self.mPassword, aLandName)

    def buildBuilding(self,
            aIdHolderClass, aHolderName, aIdBuildingClass, aIdBuilding, aVolume):
        return TUSInterface.buildBuilding( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName, aIdBuildingClass, aIdBuilding, aVolume)

    def buildOn( self, aSettlementName, aBuilding, aVolume):
        return self.buildBuilding( 
            str(ID_HOLDER_CLASS_SETTLEMENT), aSettlementName, 
            str(aBuilding[0]), str(aBuilding[1]), str(aVolume) );

    def build(self, aBuilding, aVolume):
        return buildOn(self.mCurrentSettlement, aBuilding, aVolume);
            
    def destroyBuilding(self,
            aIdHolderClass, aHolderName, aIdBuildingClass, aIdBuilding, aVolume):
        return TUSInterface.destroyBuilding( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName, aIdBuildingClass, aIdBuilding, aVolume)

    def getBuilding(self,
            aIdHolderClass, aHolderName, aIdBuildingClass, aIdBuilding):
        return TUSInterface.getBuilding( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName, aIdBuildingClass, aIdBuilding)

    def getBuildings(self, aIdHolderClass, aHolderName):
        return TUSInterface.getBuildings( self, self.mUser, self.mPassword, aIdHolderClass, aHolderName)

    def dismissHuman(self,
            aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aExperience, aVolume):
        return TUSInterface.dismissHuman( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aExperience, aVolume)

    def dismissFrom(self, aSettlementName, aHuman, aExperience, aVolume):
        return self.dismissHuman( 
            str(ID_HOLDER_CLASS_SETTLEMENT), aSettlementName,
            str(aHuman[0]), str(aHuman[1]), str(aExperience), str(aVolume));
            
    def engageHuman(self,
            aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aVolume):
        return TUSInterface.engageHuman( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aVolume)

    def humanTo( self, aSettlementName, aHuman, aVolume):
        return self.engageHuman( 
            str(ID_HOLDER_CLASS_SETTLEMENT), aSettlementName,
            str(aHuman[0]), str(aHuman[1]), str(aVolume) );

    def getHuman(self,
            aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aExperience):
        return TUSInterface.getHuman( self, self.mUser, self.mPassword, 
            aIdHolderClass, aHolderName, aIdHumandClass, aIdHuman, aExperience)

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
            aSettlementNameSource, aSettlementNameDestination, aIdHumandClass, aIdHuman,
            aExperience, aVolume)

    def transportResource(self,
            aSettlementNameSource, aSettlementNameDestination, aIdResource, aVolume):
        return TUSInterface.transportResource( self, self.mUser, self.mPassword, 
            aSettlementNameSource, aSettlementNameDestination, aIdResource, aVolume)


