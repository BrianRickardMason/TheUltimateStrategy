#Name: TUSlang.py
#Description: Holds language specification - dictionaries of avaliable commands.
#Author: Lukasz Czarnecki

#Full list of avaliable commands with their identifiers as well as the number, type and name of required fields for each XML request (command)
#TODO: Handle default 'status' : '' (only params in dict)
#TODO: Handle login
commands = {
'ECHO' : (1, {}, {}),
'ERROR' : (2, {}, {}),

'CREATE_LAND' : (3, {'idworld': 'unsigned integer', 'idepoch': 'unsigned integer', 'name': 'string'}, {'message': 'string'}),
'DELETE_LAND' : (4, {'idland': 'unsigned integer'}, {'message': 'string'}),
'GET_LAND_BY_ID_LAND' : (5, {'idland': 'unsigned integer'}, {'message': 'string', 'iduser': 'unsigned integer', 'idworld': 'unsigned integer', 'idland': 'unsigned integer', 'name': 'string', 'granted': 'boolean'}),
'GET_LAND_BY_NAME' : (6, {'name': 'string'}, {'idland': 'unsigned integer'}, {'message': 'string', 'iduser': 'unsigned integer', 'idworld': 'unsigned integer', 'idland': 'unsigned integer', 'name': 'string', 'granted': 'boolean'}),
#'GET_LANDS_BY_ID_WORLD' : (7, {}, {}), - not used in this version of the language

'CREATE_SETTLEMENT' : (8, {'idland': 'unsigned integer', 'name': 'string'}, {'message': 'string'}),
'DELETE_SETTLEMENT' : (9, {}, {}),
'GET_SETTLEMENT_BY_ID_LAND_AND_NAME' : (10, {}, {}),
'GET_SETTLEMENT_BY_ID_SETTLEMENT' : (11, {}, {}),
'GET_SETTLEMENTS_BY_ID_LAND' : (12, {}, {}),

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
