
#include "UserRequestBuilder.hpp"

namespace Language {

const std::string UserRequestBuilder::SETTLEMENT_CLASS_ID = "1";

ICommand::Handle UserRequestBuilder::buildActivateEpochRequest() const {
    checkCredentials();
    checkWorld();
    return mReqBuilder->buildActivateEpochRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildBuildBuildingRequest (
    const std::string a_building_key, const std::string a_volume ) const {
    return mReqBuilder->buildBuildBuildingRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_building_key, a_volume
    );
}

ICommand::Handle UserRequestBuilder::buildCreateEpochRequest (
    const std::string a_epoch_name ) const {
    checkCredentials();
    checkWorld();
    return mReqBuilder->buildCreateEpochRequest(
        mUsername, mPassword,
        mWorld,
        a_epoch_name
    );
}

ICommand::Handle UserRequestBuilder::buildCreateLandRequest ( const std::string a_land_name ) const {
    return mReqBuilder->buildCreateLandRequest(
        mUsername, mPassword,
        mWorld,
        a_land_name
    );
}

ICommand::Handle UserRequestBuilder::buildCreateSettlementRequest (
    const std::string a_land_name, const std::string a_settlement_name ) {

    setSettlement(a_settlement_name);

    mReqBuilder->buildCreateSettlementRequest(
        mUsername, mPassword,
        a_land_name, a_settlement_name
    );
}

ICommand::Handle UserRequestBuilder::buildCreateUserRequest(
    std::string a_login, std::string a_password) {
        setCredenials(a_login, a_password);
    return mReqBuilder->buildCreateUserRequest(
        mUsername, mPassword
    );
}

ICommand::Handle UserRequestBuilder::buildCreateWorldRequest ( const std::string a_world_name )
{
    setWorld(a_world_name);
    return mReqBuilder->buildCreateWorldRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildDeactivateEpochRequest() const
{
    return mReqBuilder->buildDeactivateEpochRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildDeleteEpochRequest() const
{
    return mReqBuilder->buildDeleteEpochRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildDeleteLandRequest ( const std::string a_land_name ) const
{
    return mReqBuilder->buildDeleteLandRequest(
        mUsername, mPassword,
        a_land_name
    );
}

ICommand::Handle UserRequestBuilder::buildDeleteSettlementRequest ( const std::string a_settlement_name ) const
{
    return mReqBuilder->buildDeleteSettlementRequest(
        mUsername, mPassword,
        a_settlement_name
    );
}

ICommand::Handle UserRequestBuilder::buildDestroyBuildingRequest ( const std::string a_building_key, const std::string a_volume ) const
{
    return mReqBuilder->buildDestroyBuildingRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_building_key, a_volume
    );
}

ICommand::Handle UserRequestBuilder::buildDismissHumanRequest ( const std::string a_human_key, const std::string a_volume ) const
{
    return mReqBuilder->buildDismissHumanRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_human_key, a_volume
    );
}

ICommand::Handle UserRequestBuilder::buildEchoRequest() const
{
    return mReqBuilder->buildEchoRequest();
}

ICommand::Handle UserRequestBuilder::buildEngageHumanRequest ( const std::string a_human_key, const std::string a_volume ) const
{
    return mReqBuilder->buildEngageHumanRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_human_key, a_volume
    );
}

ICommand::Handle UserRequestBuilder::buildErrorRequest() const
{
    return mReqBuilder->buildErrorRequest();
}

ICommand::Handle UserRequestBuilder::buildFinishEpochRequest() const
{
    return mReqBuilder->buildFinishEpochRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildGetBuildingRequest ( const std::string a_building_key ) const
{
    return mReqBuilder->buildGetBuildingRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_building_key
    );
}

ICommand::Handle UserRequestBuilder::buildGetBuildingsRequest() const
{
    return mReqBuilder->buildGetBuildingsRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName
    );
}

ICommand::Handle UserRequestBuilder::buildGetEpochRequest() const
{
    return mReqBuilder->buildGetEpochRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildGetHumanRequest ( const std::string a_human_key ) const
{
    return mReqBuilder->buildGetHumanRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_human_key
    );
}

ICommand::Handle UserRequestBuilder::buildGetHumansRequest() const
{
    return mReqBuilder->buildGetHumansRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName
    );
}

ICommand::Handle UserRequestBuilder::buildGetLandRequest ( const std::string a_land_name ) const
{
    return mReqBuilder->buildGetLandRequest(
        mUsername, mPassword,
        a_land_name
    );
}

ICommand::Handle UserRequestBuilder::buildGetLandsRequest() const
{
    return mReqBuilder->buildGetLandsRequest(
        mUsername, mPassword
    );
}

ICommand::Handle UserRequestBuilder::buildGetResourceRequest ( const std::string a_resource_key ) const
{
    return mReqBuilder->buildGetResourceRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName,
        a_resource_key
    );
}

ICommand::Handle UserRequestBuilder::buildGetResourcesRequest() const
{
    return mReqBuilder->buildGetResourcesRequest(
        mUsername, mPassword,
        mIdHolderClass, mIdHolderName
    );
}

ICommand::Handle UserRequestBuilder::buildGetSettlementRequest ( const std::string a_settlement_name ) const
{
    return mReqBuilder->buildGetSettlementRequest(
        mUsername, mPassword,
        a_settlement_name
    );
}

ICommand::Handle UserRequestBuilder::buildGetSettlementsRequest ( const std::string a_land_name ) const
{
    return mReqBuilder->buildGetSettlementsRequest(
        mUsername, mPassword,
        a_land_name
    );
}

ICommand::Handle UserRequestBuilder::buildTickEpochRequest() const
{
    return mReqBuilder->buildTickEpochRequest(
        mUsername, mPassword,
        mWorld
    );
}

ICommand::Handle UserRequestBuilder::buildTransportHumanRequest (
    const std::string a_settlement_name_source, const std::string a_settlement_name_destination,
    const std::string a_human_key, const std::string a_volume ) const
{
    return mReqBuilder->buildTransportHumanRequest(
        mUsername, mPassword,
        a_settlement_name_source, a_settlement_name_destination,
        a_human_key, a_volume
    );
}

ICommand::Handle UserRequestBuilder::buildTransportResourceRequest (
    const std::string a_settlement_name_source, const std::string a_settlement_name_destination,
    const std::string a_resource_key, const std::string a_volume ) const
{
    return mReqBuilder->buildTransportResourceRequest(
        mUsername, mPassword,
        a_settlement_name_source, a_settlement_name_destination,
        a_resource_key, a_volume
    );
}

}
