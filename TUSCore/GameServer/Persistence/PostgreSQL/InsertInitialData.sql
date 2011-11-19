BEGIN;

-- Users.
INSERT INTO users(login, password, moderator) VALUES('modbot', 'modbotpass', true);

-- Achievements.
INSERT INTO achievements_available(achievement_name) VALUES ('survived22');
INSERT INTO achievements_available(achievement_name) VALUES ('survived44');
INSERT INTO achievements_available(achievement_name) VALUES ('survived88');

-- Cost type: ID_COST_TYPE_BUILDING_BUILD.
-- Building class: ID_BUILDING_CLASS_DEFENSIVE.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 1, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_GOLD.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 1, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_REGULAR.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 1, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_SPECIAL.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 1, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 1, 'wood', 10);

-- Cost type: ID_COST_TYPE_BUILDING_DESTROY.
-- Building class: ID_BUILDING_CLASS_DEFENSIVE.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebarbican', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivebattlements', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecasemate', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivecircumvallation', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivedonjon', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivemachicolation', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveportcullis', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensivepostern', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('defensiveviewingtower', 2, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_GOLD.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldaltarofwishes', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldcommunicationtowers', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldeternalcalendar', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofmeteors', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofrains', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofstorms', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldhunterofwinds', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldnecropolis', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldoracle', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldportalofelements', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldpsionicacademy', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('goldtowerofchaos', 2, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_REGULAR.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularbarracks', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularfarm', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularforge', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularguild', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularhouse', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmarketplace', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularmine', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularquarry', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsawmill', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularschool', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regularsteelworks', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('regulartemple', 2, 'wood', 10);

-- Building class: ID_BUILDING_CLASS_SPECIAL.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialaqueduct', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialbawdyhouse', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcommercialport', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialcourt', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialgranary', 2, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('specialsewerage', 2, 'wood', 10);

-- Cost type: ID_COST_TYPE_HUMAN_DISMISS.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 3, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 3, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 3, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 3, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 3, 'wood', 10);

-- Cost type: ID_COST_TYPE_HUMAN_ENGAGE.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarchernovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierarcheradvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemannovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierhorsemanadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymannovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('soldierinfantrymanadvanced', 4, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererearthadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfirenovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererfireadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwaternovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwateradvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('sorcerersorcererwindadvanced', 4, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyagentadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspynovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spyspyadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('spythugadvanced', 4, 'wood', 10);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerblacksmithadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreedernovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerbreederadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerdruidadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmernovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfarmeradvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermannovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerfishermanadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerjoblessadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjacknovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerlumberjackadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermerchantadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerminernovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workermineradvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerofficialadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerpriestadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkernovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workersteelworkeradvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonnovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerstonemasonadvanced', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteachernovice', 4, 'wood', 10);

INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'coal', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'food', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'gold', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'iron', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'mana', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'rock', 10);
INSERT INTO costs(key, id_cost_type, resource_key, volume) VALUES('workerteacheradvanced', 4, 'wood', 10);

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

-- Property id: ID_PROPERTY_BUILDING_CAPACITY.
-- Building class: ID_BUILDING_CLASS_DEFENSIVE.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivebarbican', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivebattlements', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivecasemate', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivecircumvallation', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivedonjon', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivemachicolation', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensiveportcullis', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensivepostern', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('defensiveviewingtower', 1, 2, 10);

-- Building class: ID_BUILDING_CLASS_GOLD.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldaltarofwishes', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldcommunicationtowers', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldeternalcalendar', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldhunterofmeteors', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldhunterofrains', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldhunterofstorms', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldhunterofwinds', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldnecropolis', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldoracle', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldportalofelements', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldpsionicacademy', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('goldtowerofchaos', 1, 2, 10);

-- Building class: ID_BUILDING_CLASS_REGULAR.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularbarracks', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularfarm', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularforge', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularguild', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularhouse', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularmarketplace', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularmine', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularquarry', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularsawmill', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularschool', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regularsteelworks', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('regulartemple', 1, 2, 10);

-- Building class: ID_BUILDING_CLASS_SPECIAL.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('specialaqueduct', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('specialbawdyhouse', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('specialcommercialport', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('specialcourt', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('specialgranary', 1, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('specialsewerage', 1, 2, 10);

-- Property id: ID_PROPERTY_HUMAN_ENGAGEABLE.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('soldierarchernovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('soldierarcheradvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('soldierhorsemannovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('soldierhorsemanadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('soldierinfantrymannovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('soldierinfantrymanadvanced', 3, 1, false);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererearthnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererearthadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererfirenovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererfireadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererwaternovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererwateradvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererwindnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('sorcerersorcererwindadvanced', 3, 1, false);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('spyagentnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('spyagentadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('spyspynovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('spyspyadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('spythugnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('spythugadvanced', 3, 1, false);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerblacksmithnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerblacksmithadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerbreedernovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerbreederadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerdruidnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerdruidadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerfarmernovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerfarmeradvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerfishermannovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerfishermanadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerjoblessnovice', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerjoblessadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerlumberjacknovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerlumberjackadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workermerchantnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workermerchantadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerminernovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workermineradvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerofficialnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerofficialadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerpriestnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerpriestadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workersteelworkernovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workersteelworkeradvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerstonemasonnovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerstonemasonadvanced', 3, 1, false);
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerteachernovice', 3, 1, true );
INSERT INTO properties(key, id_property, value_discriminator, value_boolean) VALUES('workerteacheradvanced', 3, 1, false);

-- Property id: ID_PROPERTY_HUMAN_PRODUCTION.
-- Human class: ID_HUMAN_CLASS_SOLDIER.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('soldierarchernovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('soldierarcheradvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('soldierhorsemannovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('soldierhorsemanadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('soldierinfantrymannovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('soldierinfantrymanadvanced', 4, 2,  0);

-- Human class: ID_HUMAN_CLASS_SORCERER.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererearthnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererearthadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererfirenovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererfireadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererwaternovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererwateradvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererwindnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('sorcerersorcererwindadvanced', 4, 2,  0);

-- Human class: ID_HUMAN_CLASS_SPY.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('spyagentnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('spyagentadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('spyspynovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('spyspyadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('spythugnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('spythugadvanced', 4, 2,  0);

-- Human class: ID_HUMAN_CLASS_WORKER.
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerblacksmithnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerblacksmithadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerbreedernovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerbreederadvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerdruidnovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerdruidadvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerfarmernovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerfarmeradvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerfishermannovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerfishermanadvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerjoblessnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerjoblessadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerlumberjacknovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerlumberjackadvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workermerchantnovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workermerchantadvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerminernovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workermineradvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerofficialnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerofficialadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerpriestnovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerpriestadvanced', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workersteelworkernovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workersteelworkeradvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerstonemasonnovice', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerstonemasonadvanced', 4, 2, 10);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerteachernovice', 4, 2,  0);
INSERT INTO properties(key, id_property, value_discriminator, value_integer) VALUES('workerteacheradvanced', 4, 2,  0);

COMMIT;
