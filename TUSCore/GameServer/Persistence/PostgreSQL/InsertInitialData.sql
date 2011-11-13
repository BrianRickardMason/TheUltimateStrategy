BEGIN;

-- Users.
INSERT INTO users(login, password, moderator) VALUES('modbot', 'modbotpass', true);

-- Achievements.
INSERT INTO achievements_available(achievement_name) VALUES ('survived22');
INSERT INTO achievements_available(achievement_name) VALUES ('survived44');
INSERT INTO achievements_available(achievement_name) VALUES ('survived88');

-- Cost type: ID_COST_TYPE_BUILDING_BUILD.
-- Building class: ID_BUILDING_CLASS_DEFENSIVE.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 1, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_GOLD.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 1, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_REGULAR.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 1, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_SPECIAL.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 1, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 1, 'wood', 10);

-- Cost type: ID_COST_TYPE_BUILDING_DESTROY.
-- Building class: ID_BUILDING_CLASS_DEFENSIVE.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000101, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000102, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000103, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000104, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000105, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000106, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000107, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000108, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000109, 2, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_GOLD.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000201, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000202, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000203, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000204, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000205, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000206, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000207, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000208, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000209, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000210, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000211, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000212, 2, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_REGULAR.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000301, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000302, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000303, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000304, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000305, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000306, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000307, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000308, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000309, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000310, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000311, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000312, 2, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_SPECIAL.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000401, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000402, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000403, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000404, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000405, 2, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(1000406, 2, 'wood', 10);

-- Cost type: ID_COST_TYPE_HUMAN_DISMISS.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 3, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 3, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 3, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 3, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 3, 'wood', 10);

-- Cost type: ID_COST_TYPE_HUMAN_ENGAGE.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 4, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 4, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 4, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 4, 'wood', 10);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'coal', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'food', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'gold', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'iron', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'mana', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'rock', 10);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 4, 'wood', 10);

-- Cost type: ID_COST_TYPE_HUMAN_LIVING.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010101, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010102, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010201, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010202, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010301, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2010302, 5, 'wood', 1);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020101, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020102, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020201, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020202, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020301, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020302, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020401, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2020402, 5, 'wood', 1);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030101, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030102, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030201, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030202, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030301, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2030302, 5, 'wood', 1);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040101, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040102, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040201, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040202, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040301, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040302, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040401, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040402, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040501, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040502, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040601, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040602, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040701, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040702, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040801, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040802, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040901, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2040902, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041001, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041002, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041101, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041102, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041201, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041202, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041301, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041302, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041401, 5, 'wood', 1);

INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'coal', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'food', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'gold', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'iron', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'mana', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'rock', 1);
INSERT INTO costs(key_hash, id_cost_type, resource_key, volume) VALUES(2041402, 5, 'wood', 1);

-- Property id: ID_PROPERTY_BUILDING_CAPACITY.
-- Building class: ID_BUILDING_CLASS_DEFENSIVE.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000101, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000102, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000103, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000104, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000105, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000106, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000107, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000108, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000109, 1, 2, 10);

-- Building class: ID_BUILDING_CLASS_GOLD.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000201, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000202, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000203, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000204, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000205, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000206, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000207, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000208, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000209, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000210, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000211, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000212, 1, 2, 10);

-- Building class: ID_BUILDING_CLASS_REGULAR.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000301, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000302, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000303, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000304, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000305, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000306, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000307, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000308, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000309, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000310, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000311, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000312, 1, 2, 10);

-- Building class: ID_BUILDING_CLASS_SPECIAL.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000401, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000402, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000403, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000404, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000405, 1, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(1000406, 1, 2, 10);

-- Property id: ID_PROPERTY_HUMAN_DISMISSABLE.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010101, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010102, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010201, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010202, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010301, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010302, 2, 1, true );

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020101, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020102, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020201, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020202, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020301, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020302, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020401, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020402, 2, 1, true );

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030101, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030102, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030201, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030202, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030301, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030302, 2, 1, true );

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040101, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040102, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040201, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040202, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040301, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040302, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040401, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040402, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040501, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040502, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040601, 2, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040602, 2, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040701, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040702, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040801, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040802, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040901, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040902, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041001, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041002, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041101, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041102, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041201, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041202, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041301, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041302, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041401, 2, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041402, 2, 1, true );

-- Property id: ID_PROPERTY_HUMAN_ENGAGEABLE.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010101, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010102, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010201, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010202, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010301, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2010302, 3, 1, false);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020101, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020102, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020201, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020202, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020301, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020302, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020401, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2020402, 3, 1, false);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030101, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030102, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030201, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030202, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030301, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2030302, 3, 1, false);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040101, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040102, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040201, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040202, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040301, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040302, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040401, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040402, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040501, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040502, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040601, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040602, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040701, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040702, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040801, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040802, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040901, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2040902, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041001, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041002, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041101, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041102, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041201, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041202, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041301, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041302, 3, 1, false);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041401, 3, 1, true );
INSERT INTO properties(key_hash, id_property, value_discriminator, value_boolean) VALUES(2041402, 3, 1, false);

-- Property id: ID_PROPERTY_HUMAN_PRODUCTION.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2010101, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2010102, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2010201, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2010202, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2010301, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2010302, 4, 2,  0);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020101, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020102, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020201, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020202, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020301, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020302, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020401, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2020402, 4, 2,  0);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2030101, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2030102, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2030201, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2030202, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2030301, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2030302, 4, 2,  0);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040101, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040102, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040201, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040202, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040301, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040302, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040401, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040402, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040501, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040502, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040601, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040602, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040701, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040702, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040801, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040802, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040901, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2040902, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041001, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041002, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041101, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041102, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041201, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041202, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041301, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041302, 4, 2, 10);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041401, 4, 2,  0);
INSERT INTO properties(key_hash, id_property, value_discriminator, value_integer) VALUES(2041402, 4, 2,  0);

COMMIT;
