BEGIN;

-- Users.
INSERT INTO users(login, password, moderator) VALUES('modbot', 'modbotpass', true);

-- Achievements.
INSERT INTO achievements_available(achievement_name) VALUES ('survived22');
INSERT INTO achievements_available(achievement_name) VALUES ('survived44');
INSERT INTO achievements_available(achievement_name) VALUES ('survived88');

-- Cost type: ID_COST_TYPE_HUMAN_LIVING.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 5, 'wood', 1);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 5, 'wood', 1);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 5, 'wood', 1);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 5, 'wood', 1);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'coal', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'food', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'gold', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'iron', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'mana', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'rock', 1);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 5, 'wood', 1);

COMMIT;
