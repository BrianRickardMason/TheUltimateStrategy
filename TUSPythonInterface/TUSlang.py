#Name: TUSlang.py
#Description: Holds language specification - dictionaries of avaliable commands.
#Author: Lukasz Czarnecki

#Full list of avaliable commands with their identifiers as well as the number, type and name of required fields for each XML request (command)
#TODO: Handle default 'status' : '' (only params in dict)
#TODO: Handle login
#TODO: Request ids have to be consistent with the ones that are held in Request.hpp file.

# Command: ( REQUEST_ID, {<user></user>}, {<parameters></parameters>} ).
commands = {
# Generic.
'ECHO'              : ( 1, {}, {}),
'ERROR'             : ( 2, {}, {}),

# Land.
'CREATE_LAND'       : ( 3, {'login', 'password'}, {'world_name', 'land_name'}),
'DELETE_LAND'       : ( 4, {'login', 'password'}, {'land_name'}),
'GET_LAND'          : ( 5, {'login', 'password'}, {'land_name'}),
'GET_LANDS'         : ( 6, {'login', 'password'}, {}),

# Settlement.
'CREATE_SETTLEMENT' : ( 7, {'login', 'password'}, {'land_name', 'settlement_name'}),
'DELETE_SETTLEMENT' : ( 8, {'login', 'password'}, {'settlement_name'}),
'GET_SETTLEMENT'    : ( 9, {'login', 'password'}, {'settlement_name'}),
'GET_SETTLEMENTS'   : (10, {'login', 'password'}, {'land_name'}),

'BUILD_BUILDING' : (13, {}, {}),
'DESTROY_BUILDING' : (14, {}, {}),
'GET_BUILDING' : (15, {}, {}),
'GET_BUILDINGS' : (16, {}, {}),

'DISMISS_HUMAN' : (17, {}, {}),
'ENGAGE_HUMAN' : (18, {}, {}),
'GET_HUMAN' : (19, {}, {}),
'GET_HUMANS' : (20, {}, {}),

'GET_RESOURCE' : (21, {}, {}),
'GET_RESOURCES' : (22, {}, {}),

'CREATE_USER' : (23, {}, {}),

'CREATE_WORLD' : (24, {}, {}),

'TURN' : (25, {}, {}),

'CREATE_EPOCH' : (26, {}, {}),
'DELETE_EPOCH' : (27, {}, {}),
'ACTIVATE_EPOCH' : (28, {}, {}),
'DEACTIVATE_EPOCH' : (29, {}, {}),
'FINISH_EPOCH' : (30, {}, {}),
'TICK_EPOCH' : (31, {}, {}),
'GET_EPOCH' : (32, {}, {}),

'TRANSPORT_HUMAN' : (33, {}, {}),
'TRANSPORT_RESOURCE' : (34, {}, {}),
}

#TODO: FIXME
status = {
1 : 'REPLY_STATUS_SERVER_IS_NOT_LISTENING',
2 : 'REPLY_STATUS_INVALID_REQUEST',
3 : 'REPLY_STATUS_INVALID_RANGE',
4 : 'REPLY_STATUS_UNAUTHENTICATED',
5 : 'REPLY_STATUS_ACTING_USER_HAS_NOT_BEEN_GOT',
6 : 'REPLY_STATUS_UNAUTHORIZED',
7 : 'REPLY_STATUS_EPOCH_IS_NOT_ACTIVE',
8 : 'REPLY_STATUS_ACTION_UNAVAILABLE',
9 : 'REPLY_STATUS_OK'
}
