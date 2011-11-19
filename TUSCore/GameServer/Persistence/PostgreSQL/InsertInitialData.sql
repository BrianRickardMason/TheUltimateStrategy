BEGIN;

-- Users.
INSERT INTO users(login, password, moderator) VALUES('modbot', 'modbotpass', true);

-- Achievements.
INSERT INTO achievements_available(achievement_name) VALUES ('survived22');
INSERT INTO achievements_available(achievement_name) VALUES ('survived44');
INSERT INTO achievements_available(achievement_name) VALUES ('survived88');

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

COMMIT;
