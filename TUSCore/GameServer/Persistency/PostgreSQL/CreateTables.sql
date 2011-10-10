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

    UNIQUE(world_name)
);

DROP TABLE IF EXISTS lands CASCADE;
CREATE TABLE lands
(
    login      VARCHAR(44) NOT NULL CHECK(login <> '') REFERENCES users(login) ON DELETE CASCADE,
    world_name VARCHAR(44) NOT NULL CHECK(world_name <> '') REFERENCES worlds(world_name) ON DELETE CASCADE,
    land_name  VARCHAR(44) PRIMARY KEY NOT NULL CHECK(land_name <> ''),

    granted BOOLEAN DEFAULT FALSE
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
    holder_name       VARCHAR(44) NOT NULL CHECK(holder_name <> '') REFERENCES settlements(settlement_name) ON DELETE CASCADE,
    id_building_class SMALLINT NOT NULL CHECK(id_building_class IN (1, 2, 3, 4)), -- TODO: Mapping to source code needed.
    id_building       SMALLINT NOT NULL CHECK(id_building > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    volume            INTEGER NOT NULL CHECK(volume > 0),

    UNIQUE(holder_name, id_building_class, id_building)
);

DROP TABLE IF EXISTS humans_settlement CASCADE;
CREATE TABLE humans_settlement
(
    holder_name    VARCHAR(44) NOT NULL CHECK(holder_name <> '') REFERENCES settlements(settlement_name) ON DELETE CASCADE,
    id_human_class SMALLINT NOT NULL CHECK(id_human_class IN (1, 2, 3, 4)), -- TODO: Mapping to source code needed.
    id_human       SMALLINT NOT NULL CHECK(id_human > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    experience     SMALLINT NOT NULL CHECK(experience IN (1, 2)), -- TODO: Mapping to source code needed.
    volume         INTEGER NOT NULL CHECK(volume > 0),

    UNIQUE(holder_name, id_human_class, id_human, experience)
);

DROP TABLE IF EXISTS resources_settlement CASCADE;
CREATE TABLE resources_settlement
(
    holder_name VARCHAR(44) NOT NULL CHECK(holder_name <> '') REFERENCES settlements(settlement_name) ON DELETE CASCADE,
    id_resource SMALLINT NOT NULL CHECK(id_resource IN (1, 2, 3, 4, 5, 6, 7)), -- TODO: Mapping to source code needed.
    volume      INTEGER NOT NULL CHECK(volume > 0),

    UNIQUE(holder_name, id_resource)
);

DROP TABLE IF EXISTS costs CASCADE;
CREATE TABLE costs
(
    key_hash     INTEGER NOT NULL CHECK(key_hash > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    id_cost_type SMALLINT NOT NULL CHECK(id_cost_type > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    id_resource  SMALLINT NOT NULL CHECK(id_resource IN (1, 2, 3, 4, 5, 6, 7)), -- TODO: Mapping to source code needed.
    volume       SMALLINT NOT NULL CHECK(volume > 0),

    UNIQUE(key_hash, id_cost_type, id_resource)
);

DROP TABLE IF EXISTS properties CASCADE;
CREATE TABLE properties
(
    key_hash            INTEGER NOT NULL CHECK(key_hash > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    id_property         SMALLINT NOT NULL CHECK(id_property > 0), -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    value_discriminator SMALLINT NOT NULL CHECK(value_discriminator IN (1, 2, 3)), -- TODO: Mapping to source code needed.
    value_boolean       BOOLEAN DEFAULT NULL, -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    value_integer       SMALLINT DEFAULT NULL, -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.
    value_string        VARCHAR(44) DEFAULT NULL, -- TODO: Needed more specific constraint. TODO: Mapping to source code needed.

    UNIQUE(key_hash, id_property)
);
