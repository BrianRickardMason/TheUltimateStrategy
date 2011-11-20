#!/usr/bin/env python3

# Name: TUSDictionary.py
# Description: Holds the language dictionary.
# Author: Lukasz Czarnecki, Marcin Skrobiranda.

# A complete list of available commands with their identifiers and a description of <user> and <parameter> blocks.
# Command: (REQUEST_ID, {<user></user>}, {<parameters></parameters>}).
COMMAND_SCHEMAS = {
# Generic.
'ECHO'               : ( 1, [                   ], []),
'ERROR'              : ( 2, [                   ], []), # Well... actually this one should never be executed.

# Land.
'CREATE_LAND'        : ( 3, ['login', 'password'], ['world_name', 'land_name']),
'DELETE_LAND'        : ( 4, ['login', 'password'], ['land_name']),
'GET_LAND'           : ( 5, ['login', 'password'], ['land_name']),
'GET_LANDS'          : ( 6, ['login', 'password'], []),

# Settlement.
'CREATE_SETTLEMENT'  : ( 7, ['login', 'password'], ['land_name', 'settlement_name']),
'DELETE_SETTLEMENT'  : ( 8, ['login', 'password'], ['settlement_name']),
'GET_SETTLEMENT'     : ( 9, ['login', 'password'], ['settlement_name']),
'GET_SETTLEMENTS'    : (10, ['login', 'password'], ['land_name']),

# Building.
'BUILD_BUILDING'     : (11, ['login', 'password'], ['idholderclass', 'holder_name', 'buildingkey', 'volume']),
'DESTROY_BUILDING'   : (12, ['login', 'password'], ['idholderclass', 'holder_name', 'buildingkey', 'volume']),
'GET_BUILDING'       : (13, ['login', 'password'], ['idholderclass', 'holder_name', 'buildingkey']),
'GET_BUILDINGS'      : (14, ['login', 'password'], ['idholderclass', 'holder_name']),

# Human.
'DISMISS_HUMAN'      : (15, ['login', 'password'], ['idholderclass', 'holder_name', 'humankey', 'volume']),
'ENGAGE_HUMAN'       : (16, ['login', 'password'], ['idholderclass', 'holder_name', 'humankey', 'volume']),
'GET_HUMAN'          : (17, ['login', 'password'], ['idholderclass', 'holder_name', 'humankey']),
'GET_HUMANS'         : (18, ['login', 'password'], ['idholderclass', 'holder_name']),

# Resource.
'GET_RESOURCE'       : (19, ['login', 'password'], ['idholderclass', 'holder_name', 'resourcekey']),
'GET_RESOURCES'      : (20, ['login', 'password'], ['idholderclass', 'holder_name']),

# User.
'CREATE_USER'        : (21, [                   ], ['login', 'password']),

# World.
'CREATE_WORLD'       : (22, ['login', 'password'], ['world_name']),

# Epoch
'CREATE_EPOCH'       : (23, ['login', 'password'], ['world_name', 'epoch_name']),
'DELETE_EPOCH'       : (24, ['login', 'password'], ['world_name']),
'ACTIVATE_EPOCH'     : (25, ['login', 'password'], ['world_name']),
'DEACTIVATE_EPOCH'   : (26, ['login', 'password'], ['world_name']),
'FINISH_EPOCH'       : (27, ['login', 'password'], ['world_name']),
'TICK_EPOCH'         : (28, ['login', 'password'], ['world_name']),
'GET_EPOCH'          : (29, ['login', 'password'], ['world_name']),

# Transport.
'TRANSPORT_HUMAN'    : (30, ['login', 'password'], ['settlement_name_source',
                                                    'settlement_name_destination',
                                                    'humankey',
                                                    'volume']),
'TRANSPORT_RESOURCE' : (31, ['login', 'password'], ['settlement_name_source',
                                                    'settlement_name_destination',
                                                    'resourcekey',
                                                    'volume']),
}

# A complete list of available statuses with their identifiers.
# TODO: Consider moving away from here.
REPLY_STATUSES = {
 1 : 'REPLY_STATUS_SERVER_IS_NOT_LISTENING',
 2 : 'REPLY_STATUS_INVALID_REQUEST',
 3 : 'REPLY_STATUS_INVALID_RANGE',
 4 : 'REPLY_STATUS_UNAUTHENTICATED',
 5 : 'REPLY_STATUS_ACTING_USER_HAS_NOT_BEEN_GOT',
 6 : 'REPLY_STATUS_NON_MODERATOR_FILTERED_OUT',
 7 : 'REPLY_STATUS_UNAUTHORIZED',
 8 : 'REPLY_STATUS_EPOCH_IS_NOT_ACTIVE',
 9 : 'REPLY_STATUS_ACTION_UNAVAILABLE',
10 : 'REPLY_STATUS_OK'
}
