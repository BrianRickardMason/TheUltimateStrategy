DROP TABLE IF EXISTS users CASCADE;
CREATE TABLE users
(
    login     VARCHAR(44) PRIMARY KEY NOT NULL CHECK(login <> ''),
    password  VARCHAR(44) NOT NULL CHECK(password <> ''),
    moderator BOOLEAN DEFAULT FALSE
);

DROP TABLE IF EXISTS worlds CASCADE;
CREATE TABLE worlds
(
    world_name VARCHAR(44) PRIMARY KEY NOT NULL CHECK(world_name <> '')
);

DROP TABLE IF EXISTS epochs CASCADE;
CREATE TABLE epochs
(
    epoch_name VARCHAR(44) PRIMARY KEY NOT NULL CHECK(epoch_name <> ''),
    world_name VARCHAR(44) NOT NULL CHECK(world_name <> '') REFERENCES worlds(world_name) ON DELETE CASCADE,
    active     BOOLEAN DEFAULT FALSE,
    finished   BOOLEAN DEFAULT FALSE,
    ticks      INTEGER NOT NULL DEFAULT 0 CHECK(ticks >= 0),

    UNIQUE(world_name) -- TODO: Unique (world_name, finished == false)
);

DROP TABLE IF EXISTS achievements_available CASCADE;
CREATE TABLE achievements_available
(
    achievement_name VARCHAR(44) PRIMARY KEY NOT NULL CHECK(achievement_name <> '')
);

DROP TABLE IF EXISTS achievements CASCADE;
CREATE TABLE achievements
(
    epoch_name       VARCHAR(44) NOT NULL CHECK(epoch_name <> '')       REFERENCES epochs(epoch_name)                       ON DELETE CASCADE,
    login            VARCHAR(44) NOT NULL CHECK(login <> '')            REFERENCES users(login)                             ON DELETE CASCADE,
    achievement_name VARCHAR(44) NOT NULL CHECK(achievement_name <> '') REFERENCES achievements_available(achievement_name) ON DELETE CASCADE,

    UNIQUE(epoch_name, login, achievement_name)
);

DROP TABLE IF EXISTS lands CASCADE;
CREATE TABLE lands
(
    login      VARCHAR(44) NOT NULL CHECK(login <> '') REFERENCES users(login) ON DELETE CASCADE,
    world_name VARCHAR(44) NOT NULL CHECK(world_name <> '') REFERENCES worlds(world_name) ON DELETE CASCADE,
    land_name  VARCHAR(44) PRIMARY KEY NOT NULL CHECK(land_name <> ''),
    turns      INTEGER NOT NULL DEFAULT 0 CHECK(turns >= 0),
    granted    BOOLEAN DEFAULT FALSE,

    UNIQUE(login)
);

DROP TABLE IF EXISTS settlements CASCADE;
CREATE TABLE settlements
(
    land_name       VARCHAR(44) NOT NULL CHECK(land_name <> '') REFERENCES lands(land_name) ON DELETE CASCADE,
    settlement_name VARCHAR(44) PRIMARY KEY NOT NULL CHECK(settlement_name <> '')
);

DROP TABLE IF EXISTS buildings_settlement CASCADE;
CREATE TABLE buildings_settlement
(
    holder_name  VARCHAR(44) NOT NULL CHECK(holder_name <> '') REFERENCES settlements(settlement_name) ON DELETE CASCADE,
    building_key VARCHAR(44) NOT NULL CHECK(building_key <> ''),
    volume       INTEGER NOT NULL CHECK(volume > 0),

    UNIQUE(holder_name, building_key)
);

DROP TABLE IF EXISTS humans_settlement CASCADE;
CREATE TABLE humans_settlement
(
    holder_name VARCHAR(44) NOT NULL CHECK(holder_name <> '') REFERENCES settlements(settlement_name) ON DELETE CASCADE,
    human_key   VARCHAR(44) NOT NULL CHECK(human_key <> ''),
    volume      INTEGER NOT NULL CHECK(volume > 0),

    UNIQUE(holder_name, human_key)
);

DROP TABLE IF EXISTS resources_settlement CASCADE;
CREATE TABLE resources_settlement
(
    holder_name  VARCHAR(44) NOT NULL CHECK(holder_name <> '') REFERENCES settlements(settlement_name) ON DELETE CASCADE,
    resource_key VARCHAR(44) NOT NULL CHECK(resource_key <> ''),
    volume       INTEGER NOT NULL CHECK(volume > 0),

    UNIQUE(holder_name, resource_key)
);

DROP TABLE IF EXISTS costs CASCADE;
CREATE TABLE costs
(
    key          VARCHAR(44) NOT NULL CHECK(key <> ''),
    id_cost_type SMALLINT NOT NULL CHECK(id_cost_type > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    resource_key VARCHAR(44) NOT NULL CHECK(resource_key <> ''),
    volume       SMALLINT NOT NULL CHECK(volume > 0),

    UNIQUE(key, id_cost_type, resource_key)
);
