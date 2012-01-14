
#ifndef _USERREQUESTBUILDER_HPP_
#define _USERREQUESTBUILDER_HPP_

#include <memory>

#include "RequestBuilder.hpp"
#include "ICommand.hpp"

namespace TUSLanguage {

// TODO coherent coding style
    
/**
 * @brief Simple wrapper to make the use of request builder more convenient.
 * 
 * The class simply wraps the request from provided command builder, 
 * and fills in the common/constant parameters like username, password etc.
 */
class UserRequestBuilder {
public:
    /**
     * Handle to the UserRequestBuilder
     *
     * @remark Because of the state dependant request building there shoud
     * exist only one user of the object.
     */
    typedef std::auto_ptr<UserRequestBuilder> Handle;

    // TODO get "official" value
    static const std::string SETTLEMENT_CLASS_ID;
    
    UserRequestBuilder(RequestBuilder::Handle aRequestBuilder)
    :   mReqBuilder(aRequestBuilder) {
    }

    const RequestBuilder::Handle getRequestBuilder() const {
        return mReqBuilder;
    }
    
    UserRequestBuilder& setCredenials(
        const std::string& aUsername,
        const std::string& aPassword
    ) {
        mUsername = aUsername;
        mPassword = aPassword;
        return *this;
    }

    UserRequestBuilder& setHolder(
        const std::string& aClass,
        const std::string& aName
    ) {
        mIdHolderClass = aClass;
        mIdHolderName = aName;
        return *this;
    }

    UserRequestBuilder& setSettlement(
        const std::string& aName
    ) {
        mIdHolderClass = SETTLEMENT_CLASS_ID;
        mIdHolderName = aName;
        return *this;
    }
    
    UserRequestBuilder& setWorld(
        const std::string& aWorldName
    ) {
        mWorld = aWorldName;
        return *this;
    }
    
    /**
     * @brief Builds EchoRequest.
     *
     * @return EchoRequest.
     */
    ICommand::Handle buildEchoRequest() const;

    /**
     * @brief Builds ErrorRequest.
     *
     * @return ErrorRequest.
     */
    ICommand::Handle buildErrorRequest() const;

    /**
     * @brief Builds CreateLandRequest.
     *
     * @param a_land_name  The name of the land.
     *
     * @return CreateLandRequest
     */
    ICommand::Handle buildCreateLandRequest(
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds DeleteLandRequest.
     *
     * @param a_land_name The name of the land.
     *
     * @return DeleteLandRequest
     */
    ICommand::Handle buildDeleteLandRequest(
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds GetLandRequest.
     *
     * @param a_land_name The name of the land.
     *
     * @return GetLandRequest
     */
    ICommand::Handle buildGetLandRequest(
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds GetLandsRequest.
     *
     * @return GetLandsRequest
     */
    ICommand::Handle buildGetLandsRequest() const;

    /**
     * @brief Builds CreateSettlementRequest.
     *
     * @param a_land_name       The name of the land.
     * @param a_settlement_name The name of the settlement.
     * 
     * @remark The method is not constant, because it updates the current
     * holder data with provided name and settlement class id.
     *
     * When const method is needed @see getRequestBuilder
     * 
     * @return CreateSettlementRequest
     */
    ICommand::Handle buildCreateSettlementRequest(
        std::string const a_land_name,
        std::string const a_settlement_name
    );

    /**
     * @brief Builds DeleteSettlementRequest.
     *
     * @param a_settlement_name The name of the settlement.
     *
     * @return DeleteSettlementRequest
     */
    ICommand::Handle buildDeleteSettlementRequest(
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Builds GetSettlementRequest.
     *
     * @param a_settlement_name The name of the settlement.
     *
     * @return GetSettlementRequest
     */
    ICommand::Handle buildGetSettlementRequest(
        std::string const a_settlement_name
    ) const;

    /**
     * @brief Builds GetSettlementsRequest.
     *
     * @param a_land_name The name of the land.
     *
     * @return GetSettlementsRequest
     */
    ICommand::Handle buildGetSettlementsRequest(
        std::string const a_land_name
    ) const;

    /**
     * @brief Builds BuildBuildingRequest.
     *
     * @param a_building_key    The key of the building.
     * @param a_volume          The volume of the building.
     *
     * @return BuildBuildingRequest
     */
    ICommand::Handle buildBuildBuildingRequest(
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds DestroyBuildingRequest.
     *
     * @param a_building_key    The key of the building.
     * @param a_volume          The volume of the building.
     *
     * @return DestroyBuildingRequest
     */
    ICommand::Handle buildDestroyBuildingRequest(
        std::string const a_building_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds GetBuildingRequest.
     *
     * @param a_building_key    The key of the building.
     *
     * @return GetBuildingRequest
     */
    ICommand::Handle buildGetBuildingRequest(
        std::string const a_building_key
    ) const;

    /**
     * @brief Builds GetBuildingsRequest.
     *
     *
     * @return GetBuildingsRequest
     */
    ICommand::Handle buildGetBuildingsRequest() const;

    /**
     * @brief Builds DismissHumanRequest.
     *
     * @param a_human_key       The key of the human.
     * @param a_volume          The volume of the human.
     *
     * @return DismissHumanRequest
     */
    ICommand::Handle buildDismissHumanRequest(
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds EngageHumanRequest.
     *
     * @param a_human_key       The key of the human.
     * @param a_volume          The volume of the human.
     *
     * @return EngageHumanRequest
     */
    ICommand::Handle buildEngageHumanRequest(
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds GetHumanRequest.
     *
     * @param a_human_key       The key of the human.
     *
     * @return GetHumanRequest
     */
    ICommand::Handle buildGetHumanRequest(
        std::string const a_human_key
    ) const;

    /**
     * @brief Builds GetHumansRequest.
     *
     *
     * @return GetHumansRequest
     */
    ICommand::Handle buildGetHumansRequest() const;

    /**
     * @brief Builds GetResourceRequest.
     *
     * @param a_resource_key    The key of the resource.
     *
     * @return GetResourceRequest
     */
    ICommand::Handle buildGetResourceRequest(
        std::string const a_resource_key
    ) const;

    /**
     * @brief Builds GetResourcesRequest.
     *
     *
     * @return GetResourcesRequest
     */
    ICommand::Handle buildGetResourcesRequest() const;

    /**
     * @brief Builds CreateUserRequest.
     *
     * @param a_login    The login of the user.
     * @param a_password The password of the user.
     *
     * @remark The method is not constant, because it updates the current
     * user data with provided login and password.
     *
     * When const method is needed @see getRequestBuilder
     * 
     * @return CreateUserRequest
     */
    ICommand::Handle buildCreateUserRequest(
        std::string const a_login,
        std::string const a_password
    ) ;

    /**
     * @brief Builds CreateWorldRequest.
     *
     * @param a_world_name The name of the world.
     *
     * @remark The method is not constant, because it updates the current
     * world data with provided names.
     *
     * When const method is needed @see getRequestBuilder
     *
     * @return CreateWorldRequest
     */
    ICommand::Handle buildCreateWorldRequest(
        std::string const a_world_name
    );

    /**
     * @brief Builds CreateEpochRequest.
     *
     * @param a_epoch_name The name of the epoch.
     *
     * @return CreateEpochRequest
     */
    ICommand::Handle buildCreateEpochRequest(
        std::string const a_epoch_name
    ) const;

    /**
     * @brief Builds DeleteEpochRequest.
     *
     * @return DeleteEpochRequest
     */
    ICommand::Handle buildDeleteEpochRequest() const;

    /**
     * @brief Builds ActivateEpochRequest.
     *
     * @return ActivateEpochRequest
     */
    ICommand::Handle buildActivateEpochRequest() const;

    /**
     * @brief Builds DeactivateEpochRequest.
     *
     * @return DeactivateEpochRequest
     */
    ICommand::Handle buildDeactivateEpochRequest() const;

    /**
     * @brief Builds FinishEpochRequest.
     *
     * @return FinishEpochRequest
     */
    ICommand::Handle buildFinishEpochRequest() const;

    /**
     * @brief Builds TickEpochRequest.
     *
     * @return TickEpochRequest
     */
    ICommand::Handle buildTickEpochRequest() const;

    /**
     * @brief Builds GetEpochRequest.
     *
     * @return GetEpochRequest
     */
    ICommand::Handle buildGetEpochRequest() const;

    /**
     * @brief Builds TransportHumanRequest.
     *
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_human_key                   The key of the human.
     * @param a_volume                      The volume of the human.
     *
     * @return TransportHumanRequest
     */
    ICommand::Handle buildTransportHumanRequest(
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_human_key,
        std::string const a_volume
    ) const;

    /**
     * @brief Builds TransportResourceRequest.
     *
     * @param a_settlement_name_source      The name of the source settlement.
     * @param a_settlement_name_destination The name of the destination settlement.
     * @param a_resource_key                The key of the resource.
     * @param a_volume                      The volume of the resource.
     *
     * @return TransportResourceRequest
     */
    ICommand::Handle buildTransportResourceRequest(
        std::string const a_settlement_name_source,
        std::string const a_settlement_name_destination,
        std::string const a_resource_key,
        std::string const a_volume
    ) const;
    
private:
    /**
     * RequestBuilder implementation being wrapped
     */
    RequestBuilder::Handle mReqBuilder;
    
    // User state
    
    /**
     * Name of the current user
     */
    std::string mUsername;
    /**
     * Password for the current user
     */
    std::string mPassword;
    
    // Holder state
    
    /**
     * Class of the current holder
     */
    std::string mIdHolderClass;
    /**
     * Name of the current holder
     */
    std::string mIdHolderName;

    // World state

    /**
     * Name of the current world
     */
    std::string mWorld;
protected:
    void checkWorld() const {
        if(mWorld.empty()) {
            throw std::runtime_error("world has not been set yet");
        }
    }

    void checkCredentials() const {
        if(mUsername.empty()) {
            throw std::runtime_error("username has not been set yet");
        }
    }

    void checkHolder() const {
        if( mIdHolderClass.empty() || mIdHolderName.empty()) {
            throw std::runtime_error("holder has not been set yet");
        }
    }
};

} // namespace TUSLanguage

#endif
