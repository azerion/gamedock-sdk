//
//  Gamedock.h
//  Gamedock
//
//  Copyright © 2015 Azerion. All rights reserved.
//

#import <Gamedock/Bundle.h>
#import <Gamedock/BundleItem.h>
#import <Gamedock/BundlePrice.h>
#import <Gamedock/Currency.h>
#import <Gamedock/GachaContent.h>
#import <Gamedock/GameAsset.h>
#import <Gamedock/GameData.h>
#import <Gamedock/GameDataController.h>
#import <Gamedock/ImageEntry.h>
#import <Gamedock/Inventory.h>
#import <Gamedock/Item.h>
#import <Gamedock/JsonUtil.h>
#import <Gamedock/NSString+Extensions.h>
#import <Gamedock/NSUserDefaults-AESEncryptor.h>
#import <Gamedock/Package.h>
#import <Gamedock/PackageItem.h>
#import <Gamedock/PDKeychainBindings.h>
#import <Gamedock/PDKeychainBindingsController.h>
#import <Gamedock/PerkItem.h>
#import <Gamedock/PlayerCurrency.h>
#import <Gamedock/PlayerDataController.h>
#import <Gamedock/PlayerItem.h>
#import <Gamedock/Promotion.h>
#import <Gamedock/PromotionEntity.h>
#import <Gamedock/ShopEntry.h>
#import <Gamedock/ShopTab.h>
#import <Gamedock/GamedockActionHandler.h>
#import <Gamedock/GamedockEventTracker.h>
#import <Gamedock/GamedockPackageHandler.h>
#import <Gamedock/GamedockMissionsHandler.h>
#import <Gamedock/GamedockUserHandler.h>
#import <Gamedock/UniquePlayerItem.h>
#import <Gamedock/UserProfile.h>
#import <Gamedock/Util.h>
#import <Gamedock/Wallet.h>
#import <Gamedock/Container.h>
#import <Gamedock/Mission.h>
#import <Gamedock/UpdatedMissionData.h>
#import <Gamedock/ErrorContext.h>
#import <Gamedock/InitializationOptions.h>
#import <Gamedock/UserDataTransaction.h>
#import "HookBridge.h"
#import "GAI.h"

#define GAMEDOCK_SDK_VERSION @"4.0.0"

@class Gamedock;
@class InitializationOptions;
@class UserDataTransaction;
@class ImageContext;
@class TieredEventProgress;

@protocol GamedockDelegate

@optional

// Initialization flow completed
-(void)initializationCompleted;

//Ads Events
-(void)adsInitialized; // Ads component fully initialized
-(void)adAvailable:(nonnull NSString*)type; // An ad is available
-(void)adNotAvailable:(nonnull NSString*)type; // An ad is unavailable or did fail to load
-(void)adStart:(nonnull NSString*)type; // An ad has started
-(void)adFinished:(nonnull NSString*)type reason:(nonnull NSString*)reason reward:(nonnull NSString*)reward network:(nonnull NSString*)network; // An ad has finished (dismissed or an reward was granted)
-(void)openParentalGate; // The ad requires a parental gate check to continue, present the parental gate in this method and call the closedParentalGate method to pass the result back to the GamedockSDK.

// Notification events
-(void)grantReward:(nonnull NSDictionary*)data;

// Splash screen events
-(void)splashScreenOpen;
-(void)splashScreenAvailable:(nonnull NSString*)type;
-(void)splashScreenNotAvailable;
-(void)splashScreenClosed;
-(void)splashScreenOpenShop;
-(void)splashScreenError:(nonnull NSString*)message;
-(void)splashScreenData:(nonnull NSString*)payload;

// Daily bonus screen events
-(void)dailyBonusOpen;
-(void)dailyBonusAvailable:(nonnull NSString*)type; // New "" | "assetBundle"
-(void)dailyBonusNotAvailable;
-(void)dailyBonusClosed;
-(void)dailyBonusReward:(nonnull NSDictionary*)data;
-(void)dailyBonusError:(nonnull NSString*)message;

// Webview events
-(void)iapRequestPurchase:(nonnull NSString*)skuId withCampaignName:(nullable NSString*)campaignName;

// Config events
-(void)configUpdated;
-(void)configError:(nonnull NSString*)error;

// Missions events
-(void)missionConfigurationAvailable:(nonnull NSString*)containers withMissions:(nonnull NSString*)missions;
-(void)missionConfigurationNotAvailable;
-(void)missionConfigurationError:(nonnull NSString*)error;
-(void)missionDataUpdated:(nullable NSString*)reason withUpdatedMissionData:(nonnull UpdatedMissionData*)updatedMissionData withContainers:(nonnull NSString*)containers withMissions:(nonnull NSString*)missions;

// Package & promotion events
-(void)packagesAvailable:(nonnull NSString*)packagesJSON;
-(void)packagesNotAvailable;
-(void)promotionsAvailable:(nonnull NSString*)promotionsJSON;
-(void)promotionsNotAvailable;
-(void)onBoughtPromotion:(int)id amount:(int)amountPurchased maxPurchase:(int)maxPurchase;

// Game data events
-(void)gamedockGameDataAvailable:(nonnull NSString*)gameDataJSON;
-(void)gamedockGameDataError:(nonnull NSString*)message;

// Player data events
-(void)playerDataUpdated:(nonnull NSString*)reason updatedData:(nonnull NSString*)updatedData wallet:(nonnull NSString*)wallet inventory:(nonnull NSString*)inventory;
-(void)playerDataEmptyGacha;
-(void)playerDataNewUniqueItem:(nonnull UniquePlayerItem*)newUniquePlayerItem bundleId:(int)bundleId gachaId:(int)gachaId gachaPosition:(int)gachaPosition tierId:(int)tierId reason:(nonnull NSString*)reason;

// User data events
-(void)otherUsersGameStateLoaded:(nonnull NSDictionary*)data forProvider:(nonnull NSString*)provider; // Data: <NSString* userId, NSString* data>

// Image cache
-(void)imageLoadSuccess:(nonnull NSString*)localPath imageContext:(nonnull ImageContext*)imageContext;
-(void)imageLoadFailed:(nonnull ImageContext*)imageContext withError:(nonnull NSString*)error;
-(void)imagePreloadingCompleted;

// IAP validation
-(void)iapValid:(nonnull NSString*)skuId;
-(void)iapInvalid:(nonnull NSString*)skuId withMessage:(nonnull NSString*)message;

// Token claiming
-(void)rewardTokenReceived:(nonnull NSString*)token rewardData:(nonnull NSArray*)rewardJsonObject withRewardType:(nonnull NSString*)rewardType;
-(void)rewardTokenClaimed:(nonnull NSString*)rewardType reward:(nonnull NSArray*)reward;
-(void)rewardTokenClaimFailed:(nonnull NSString*)rewardType error:(nonnull NSString*)error;

// Server time
-(void)serverTimeRequestSuccess:(nonnull NSString*)unixTimestamp;
-(void)serverTimeRequestFailed:(nonnull NSString*)error;


// Login
-(void)onLoginSuccessful:(BOOL)resetData withSocialProvider:(nullable NSString*)socialProvider withSocialId:(nullable NSString*)socialId isGuest:(BOOL)isGuest;
-(void)onLoginFailed:(nonnull NSString*)error;
-(void)onLogoutSuccessful;
-(void)onLogoutFailed:(nonnull NSString*)error;
-(void)onAuthError:(nonnull NSString*)error;
-(void)onRequestLogin;
-(void)userIdChangeRequest:(nonnull NSString*)targetUid;
-(void)userIdChangeCompleted;

// Userdata syncing
-(void)userDataAvailable:(nonnull NSString*)wallet withInventory:(nonnull NSString*) intentory withContainers:(nonnull NSString*)containers withMissions:(nonnull NSString*)missions;
-(void)userDataError:(nonnull NSString*)error withContext:(nonnull ErrorContext*)errorContext;
-(void)userDataError:(nonnull NSString*)error;
-(void)userDataMergeConflict:(nonnull NSString*)localData remoteData:(nonnull NSString*)remoteData;
-(void)userDataMergeSuccessful:(nonnull NSString*)wallet withInventory:(nonnull NSString*) intentory withContainers:(nonnull NSString*)containers withMissions:(nonnull NSString*)missions;
-(void)userDataMergeFailed:(nonnull NSString*)mergeData mergeType:(nonnull NSString*)mergeType;
-(void)userDataHandleMerge:(nonnull NSString*)mergeType; // Called when a merge conflict option button was pressed
-(void)userDataSyncError;
-(void)userDatalockError;

// GDPR
-(void)privacyPolicyStatus:(BOOL)accepted;

// Age gate
-(void)ageGateStatus:(BOOL)passed withAge:(nonnull NSString*)age withCheckPrivacyPolicy:(BOOL)checkPrivacyPolicy;

// Tiered events
-(void)tieredEventsAvailable;
-(void)tieredEventsNotAvailable;
-(void)tieredEventUpdated:(nonnull TieredEventProgress*)tieredEventProgress;
-(void)tieredEventProgressOpen;
-(void)tieredEventProgressClosed;
-(void)tieredEventsError:(nonnull NSString*)error;

// Asset bundles
-(void)assetBundlesAvailable:(nonnull NSString*)assetBundlesJSON;
-(void)assetBundlesNotAvailable;

// Firebase
-(void)firebaseRemoteConfigUpdated;

// Game version update available
-(void)gameVersionStatus:(nonnull NSString*)status;

//ATTracking
-(void)attStatus:(int)status;
-(void)privValueChangeForced:(int)priv;

@end

@interface Gamedock : NSObject {
    
}

@property (nonatomic, assign, nullable) id  delegate;
@property (nonatomic, assign) BOOL initialized;
@property (nonatomic, assign) BOOL sdkFeaturesInitialized;
@property (nonatomic, assign) BOOL privacyPolicyEnabled;
@property (nonatomic, assign) BOOL coppaEnabled;
@property (nonatomic, assign) BOOL usingUnity;
@property (nonatomic, retain) NSDictionary * _Nullable privacySettingsToSendAfterInit;
@property (nonatomic, strong, nullable) InitializationOptions *initializationOptions;
@property (nonatomic, retain, nullable) NSArray *features;
@property (nonatomic, retain, nullable) NSMutableDictionary *featuresVersionIds;

+(nonnull Gamedock*)sharedInstance;

#pragma mark General

/**
* Initiates the SDK
* @param initializationOptions
*/
+(void)startWithInitOptions:(nonnull InitializationOptions*)initializationOptions;

/**
 * Initiates the SDK
 * @param Optional, options holds a dictionary with options like "isUnity"
 * @param externalIds, used to set a diexternalIds
 */
+(void)startWithOptions:(nullable NSDictionary*)options withExternalIds:(nullable NSDictionary*)externalIds;

+(nullable InitializationOptions*)getInitOptions;

/**
 * Helper method to log a message to the console
 * Especially useful when building a wrapped games (e.g. Unity) where the log messages are sometimes stripped out.
 * This method gives the oppertunity to log the message at the native layer instead.
 * @param The message to log
 */
+(void)log:(nonnull NSString*)message;

/**
 * Method used to send the initializeSDK event and handle feature enabling/disabling responses.
 */
+(void)initializeSDK;

/**
 * Method used to initialize the components of the SDK.
 */
+(void)initializeComponents;

+(BOOL)isFeatureEnabled:(nonnull NSString*)featureName;

+(void)setFeatureVersionId:(nonnull NSString*)featureName withVersionId:(NSNumber*)versionId;

+(NSNumber*)getFeaturesVersionId:(nonnull NSString*)featureName;
/**
 * Method to set a custom bundle id, useful during debugging.
 * @param The custom bundle id to use
 */
+(void)setCustomBundleId:(nonnull NSString*)bundleId;

/**
 * Get the Gamedock user id
 * @returns The Gamedock user id
 */
+(nullable NSString*)getGamedockUserId;

+(NSString*)getFirebaseInstanceId;

+(void)recordFirebaseCustomeException:(nonnull NSString*)name withReason:(nonnull NSString*)reason withStackTrace:(nonnull NSString*)stackTrace;

/**
 * Get the registered push notification token
 * @returns The registered push notification token
 */
+(nullable NSString*)getPushToken;

/**
 * Set a plugin name and version for the current session.
 * @param pluginName The plugin name
 * @param pluginVersion The plugin version
 */
+(void)setPluginInformation:(nonnull NSString*)pluginName pluginVersion:(nonnull NSString*)pluginVersion;

/**
 * Set the fps value to record via the hearthbeat event
 * @param fpsValue The fps value to record
 */
+(void)recordFPSValue:(double)fpsValue;

/**
 * Set an id for an external partner
 * @param externalPartner The external partner
 * @param externalId The id of the external
 */
+(void)addExternalPartner:(nonnull NSString*)externalPartner withExternalId:(nonnull NSString*)externalId;

/**
 * Remove an id for an external partner
 * @param externalPartner The external partner
 */
+(void)removeExternalPartner:(nonnull NSString*)externalPartner;

/**
 * Request the server timestamp
 */
+(void)requestServerTime;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Shows a simple dialog, useful while debugging
 */
+(void)showDialog:(NSString*)title withMessage:(NSString*)message withOkButton:(NSString*)okButtonText handler:(void (^ __nullable)(UIAlertAction *action))handler;

#pragma clang diagnostic pop

#pragma mark App flow

/**
 * Check if the privacy policy popup was completed by the user.
 * Present the popup if it was never completed by the user.
 */
+(void)checkPrivacyPolicy:(BOOL)isUnity coppaEnabled:(BOOL)coppaEnabled externalIds:(nullable NSDictionary*)externalIds;

/**
 * Opens the privacy policy settings screen
 */
+(void)showPrivacyPolicySettings;

/*
 * Checks the age gate setting and if needed presents the age gate screen
 */
+(void)checkAgeGate:(BOOL)shouldBlock withRequiredAged:(int)requiredAge;

/*
 * Method used to configure the GDPR settings in the SDK manually.
 */
+(void)setGDPRSettings:(BOOL)personalisedAds withPersonalisedContent:(BOOL)personalisedContent;

/*
 * Method used to retrieve the GDPR settings.
 */
+(nonnull NSMutableDictionary*)getGDPRSetting;

/**
 * Saves the priv value and updates the 3rd party libraries accordingly.
 * @param priv The new priv value to use
 */
+(void)savePrivValue:(GamedockPrivacyStatus)priv;

/**
 * Returns the priv value
 */
+(GamedockPrivacyStatus)getPrivValue;

/**
 * Forwarding Delegate method to let the Gamedock framework know when the app was launched
 * @param application Delegate application to be passed
 * @param launchOptions Dictionary with launch options
 */
+(void)application:(nullable UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

/**
 * Forwarding Delegate method to let the Gamedock framework know when the app went to the background
 * @param application Delegate application to be passed
 */
+(void)applicationDidEnterBackground:(nullable UIApplication *)application;

/**
 * Forwarding Delegate method to let the Gamedock framework know when the app became active again after running in background
 * @param application Delegate application to be passed
 */
+(void)applicationDidBecomeActive:(nullable UIApplication *)application;

/**
 * Handle remote notification packages
 * @param Application     Reference to the UIApplication object
 * @param userInfo        Reference to the push notification payload
 */
+(void)application:(nullable UIApplication *)application didReceiveRemoteNotification:(nullable NSDictionary *)userInfo;

/**
 * Forwarding Delegate method to let the Gamedock framework handle deeplinks
 * @param Application          Reference to the UIApplication object
 * @param openURL              The deeplink url
 * @param sourceApplication    The app name which triggered the deeplink
 * @param annotation           The anotation of the deeplink
 */
+(BOOL)application:(nullable UIApplication *)application openURL:(nullable NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(nullable id)annotation;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Forwarding Delegate method to let the Gamedock framework handle deeplinks
 * @param Application          Reference to the UIApplication object
 * @param continueUserActivity The user activity object
 * @param restorationHandler   The restoration handler
 */
+(BOOL)application:(nullable UIApplication *)application continueUserActivity:(nullable NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray *))restorationHandler;

#pragma clang diagnostic pop

#pragma mark Deeplinks

/**
 * Used to handle firebase/adjust deeplinks, could also be used to process any other 3rd party deeplink url by the Gamedock SDK
 * @param url           The url to process
 */
+(void)handleDeeplink:(nullable NSURL*)url;

#pragma mark Event tracking

/**
 * Track a milstone achieved event
 * @param name          The name of the milestone
 */
+(void)trackMilestoneAchievedEvent:(nonnull NSString*)name;

/**
 * Track a level start
 * @param level         The name of the level
 * @param customCreated Indictating if the level was custom created
 * @param creatorId     The id of the creator of the level
 */
+(void)trackLevelStartEvent:(nonnull NSString*)level customCreated:(bool)customCreated creatorId:(nonnull NSString*)creatorId;

/**
 * Track a level complete
 * @param level         The name of the level
 * @param score         The final score the player achieves at the end of the level
 * @param stars         The # of stars (or any other rating system) the player achieves at the end of the level
 * @param turns         The # of moves/turns taken to complete the level
 * @param customCreated Indictating if the level was custom created
 * @param creatorId     The id of the creator of the level
 */
+(void)trackLevelCompleteEvent:(nonnull NSString*)level score:(double)score stars:(int)stars turns:(int)turns customCreated:(bool)customCreated creatorId:(nonnull NSString*)creatorId;

/**
 * Track a level fail
 * @param level         The name of the level
 * @param score         The final score the player achieves at the end of the level
 * @param stars         The # of stars (or any other rating system) the player achieves at the end of the level
 * @param turns         The # of moves/turns taken to complete the level
 * @param customCreated Indictating if the level was custom created
 * @param creatorId     The id of the creator of the level
 */
+(void)trackLevelFailedEvent:(nonnull NSString*)level score:(double)score stars:(int)stars turns:(int)turns customCreated:(bool)customCreated creatorId:(nonnull NSString*)creatorId;

/**
 * Track a level up
 * @param level         The name of the level
 * @param score         The final score the player achieves at the end of the level
 * @param objectId      The level up object identifier
 * @param skillId       The skill id
 */
+(void)trackLevelUpEvent:(nonnull NSString*)level objectId:(nonnull NSString*)objectId skillId:(nonnull NSString*)skillId;

/**
 * Track an item equip
 * @param equippedItem  The id of the equipped item
 * @param equippedTo    The id of were the item will be equipped to
 */
+(void)trackEquipEvent:(nonnull NSString*)equippedItem equippedTo:(nonnull NSString*)equippedTo;

/**
 * Track an item upgrade
 * @param upgradeId     The id of the upgraded item
 * @param level         The level in which the upgrade happened
 * @param reason        The upgrade reason
 * @param iteration     The upgrade iteration
 */
+(void)trackUpgradeEvent:(nonnull NSString*)upgradeId level:(nonnull NSString*)level reason:(nonnull NSString*)reason iteration:(int)iteration;

/**
 * Track a level create event
 * @param levelId       The id of the created level
 * @param creatorId     The id of the level creator
 */
+(void)trackLevelCreateEvent:(nonnull NSString*)levelId creatorId:(nonnull NSString*)creatorId;

/**
 * Track a download event
 * @param levelId       The id of the downloaded level
 * @param creatorId     The id of the level creator
 * @param rating        The level rating
 */
+(void)trackLevelDownloadEvent:(nonnull NSString*)levelId creatorId:(nonnull NSString*)creatorId rating:(int)rating;

/**
 * Track a level rate event
 * @param levelId       The id of the rated level
 * @param creatorId     The id of the level creator
 * @param rating        The level rating
 */
+(void)trackLevelRateEvent:(nonnull NSString*)levelId creatorId:(nonnull NSString*)creatorId rating:(int)rating;

/**
 * Track the start of an endless level
 */
+(void)trackEndlessModeStartEvent;

/**
 * Track the end of an endless mode level
 * @param level         The distance completed in the endless level
 */
+(void)trackEndlessModeEndEvent:(int)distance;

/**
 * Track a player dies event
 * @param level         The name of the level in which the player dies
 */
+(void)trackPlayerDiesEvent:(nonnull NSString*)level;

/**
 * Track a wallet/inventory update
 * @param reason        The reason for which the wallet or the inventory has been updated
 * @param location      The location where the event occurred (ex.: Shop Screen, End of the level Screen)
 * @param currencyList  A list containing the currency objects that have been changed with the event.
 * @param itemsList     A list containing the item objects that have been changed with the event.
 */
+(void)trackWalletInventoryEvent:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails location:(nullable NSString*)location currencyList:(nullable NSString*)currencyList itemList:(nullable NSString*)itemsList;

/**
 * Track a successful iap
 * @param skuId             The product identifier of the item that was purchased
 * @param transactionId     The transaction identifier of the item that was purchased (also called orderId)
 * @param purchaseDate      The date and time that the item was purchased
 * @param reasonDetails     The reason details for this iap
 */
+(void)trackIAPPurchasedEvent:(nonnull NSString*)skuId transactionId:(nonnull NSString*)transactionId purchaseDate:(nonnull NSString*)purchaseDate withReasonDetails:(nonnull NSString*)reasonDetails;

/**
 * Track a restored iap
 * @param skuId                 The product identifier of the item that was purchased
 * @param originalTransactionId For a transaction that restores a previous transaction, the transaction identifier of the original transaction.
 *                              Otherwise, identical to the transaction identifier
 * @param originalPurchaseDate  For a transaction that restores a previous transaction, the date of the original transaction
 */
+(void)trackIAPRestoredEvent:(nonnull NSString*)skuId originalTransactionId:(nonnull NSString*)originalTransactionId originalPurchaseDate:(nonnull NSString*)originalPurchaseDate;

/**
 * Track a failed iap
 * @param skuId     The product identifier of the item that was purchased
 * @param error     Error description or error code
 */
+(void)trackIAPFailedEvent:(nonnull NSString*)skuId error:(nonnull NSString*)error;

/**
 * Track the completion of a tutorial
 */
+(void)trackTutorialCompleteEvent;

/**
 * Track a skipped tutorial
 * Track the skipping of a tutorial
 */
+(void)trackTutorialSkippedEvent;

/**
 * Track a register
 * @param platform      The platform for which the registration occurred (ex.: Facebook)
 */
+(void)trackRegisterEvent:(nonnull NSString*)platform;

/**
 * Track a share
 * @param platform      The platform for which the share occurred (ex.: Facebook)
 */
+(void)trackShareEvent:(nonnull NSString*)platform;

/**
 * Track an invite
 * @param platform      The platform for which the invite occurred (ex.: Facebook)
 */
+(void)trackInviteEvent:(nonnull NSString*)platform;

/**
 * Track a basic named event
 * @param name         The name of the event. Replace spaces with an underscore
 */
+(void) trackEvent:(nonnull NSString*)name;

/**
 * Track a named events with a key / value object
 * @param name The name of the event. Replace spaces with an underscore
 * @param params A key value dictionary holding the params
 */
+(void) trackEvent:(nonnull NSString*)name withParameters:(nullable NSDictionary *)params;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Track a basic named event with a response
 * @param name  The name of the event. Replace spaces with an underscore
 * @param block A block with response param that will be executed when the server sends a reponse on the tracked event
 */
+(void) trackEvent:(nonnull NSString*)name onResponse:(void (^)(id response))block;

/**
 * Track a named event params and a response
 * @param name   The name of the event. Replace spaces with an underscore
 * @param params A key value dictionary holding the params
 * @param block  A block with response param that will be executed when the server sends a reponse on the tracked event
 */
+(void) trackEvent:(nonnull NSString*)name withParameters:(nonnull NSDictionary *)params onResponse:(void (^)(id response))block;

/**
 * Track an error event
 * @param type    The error type (e.g. "adjust")
 * @param action  The error action (e.g. "intall")
 * @param message The error message (e.g. "no connection")
 */
+(void) trackErrorWithType:(NSString*)type withAction:(NSString*)action withMessage:(NSString*)message;

#pragma clang diagnostic pop

#pragma mark Send message

/**
 * Unity message sender
 * @param messageName     Name of the message, should match the function in unity
 * @param objectName      The name of the Gamedock object where the script is attached to. In most cases "GamedockSDK"
 * @param data            An object which can be serialized to json
 */
+(void)sendMessageToUnity:(nonnull NSString*)messageName withData:(nonnull id)data;

/**
 * Unity message sender
 * @param messageName     Name of the message, should match the function in unity
 * @param objectName      The name of the Gamedock object where the script is attached to. In most cases "GamedockSDK"
 * @param parameterString A json string holding the data to send
 */
+(void)sendMessageToUnity:(nonnull NSString*)messageName withString:(nonnull NSString*)parameterString;

#pragma mark Push notifications

/**
 * Disable the automated registration message for push notifications
 * Should be called before [Gamedock start]
 */
+(void)disableAutomaticRegisterForPushNotifications;

/**
 * Helper function to register for push notifications
 */
+(void)registerPushNotifications;

#pragma mark ATTracking

/**
 * Helper functions to register for app transparency tracking
 */
+(void)registerATTracking;

+(void)showAppSettings;
/**
 * Helper function to forward the app delegate listener on the deviceToken
 */
+(void)didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData*)deviceToken;

#pragma mark Token claiming

/**
 * Used to claim the reward token from the backend
 * @param token      The token to claim
 * @param rewardType The reward type to which the token belongs
 */
+(void)claimToken:(nonnull NSString*)token withRewardType:(nonnull NSString*)rewardType;

#pragma mark Config

/**
 * Request the game config
 */
+(void)requestGameConfig;

/**
 * Get the latest stored game configuration, typically a synchronized json object coming from the server.
 * @return NSDictionary object representation from the stored game configuration
 */
+(nullable NSDictionary*)getConfig:(BOOL)withSdkConfig;

/**
 * Get a specific value from a particular key from the game configuration
 * @param Name of the key. Type must be NSString.
 * @return returns the object from a key, only first hiergy
 */
+(nullable id)getConfigValue:(nonnull NSString*)keyString;

#pragma mark Subscription Validation

+(void)validateSubscription:(nonnull NSString*)skuId withTransactionId:(nonnull NSString*)transactionId withToken:(nonnull NSString*)token;

#pragma mark Packages

/**
 * Get the latest stored store packages.
 * @return NSArray object representation from the stored store packages
 */
+(nullable NSArray*)getAllPackages;

+(nullable NSString*)getAllPackagesJSON;

/**
 * Get a specific package from the store
 * @param packageId. Must be NSString.
 * @return returns the store package, or nil if not found
 */
+(nullable NSDictionary*)getPackageByPackageID:(nonnull NSString*)packageId;
    
/**
 * Get a specific package from the store
 * @param id. Must be int.
 * @return returns the store package, or nil if not found
 */
+(nullable NSDictionary*)getPackageByID:(int)id;

/**
 * Get the latest stored store promotions.
 * @return NSArray object representation from the stored store promotions
 */
+(nullable NSArray*)getAllPromotions;
+(nullable NSString*)getAllPromotionsJSON;
/**
 * Get the promotion for a bundle
 * @param id    Id of the bundle. Type must be int.
 * @return returns a promotion for the package id
 */
+(nullable NSDictionary*)getBundlePromotion:(int)bundleId;

/**
 * Get the promotion for a package
 * @param id    Id of the package. Type must be NSString.
 * @return returns a promotions for the bundle id
 */
+(nullable NSDictionary*)getPackagePromotion:(nonnull NSString*)packageId;

/**
 * Refresh the mission data
 */
+(void)requestMissionConfiguration;

/**
 * Refresh the promotion data
 */
+(void)requestPromotions;

+(nonnull NSMutableArray*)getContainersConfiguration;
+(nonnull NSString*)getContainersConfigurationJSON;

+(nullable Container*)getMissionContainer:(nonnull NSString*)containerId;

+(nonnull NSMutableArray*)getMissionsConfiguration:(nullable NSString*)containerId;

+(nonnull NSMutableArray*)getMissionsConfigurationWithPrerequisites:(nonnull NSMutableArray*)missionPrerequisites;

+(nonnull NSMutableArray*)getMissionsConfigurationWithUnlocks:(nonnull NSMutableArray*)missionUnlocks;

+(nullable NSMutableArray*)getAllMissionConfigurations;
+(nonnull NSString*)getAllMissionConfigurationsJSON;

+(nullable Mission*)getMissionConfiguration:(nonnull NSString*)missionId;

/**
 * Show the promotion screen
 * @param promotionId the promotion id to show the screen for
 */
+(void)showPromotionScreen:(int)promotionId;

/**
 * Check for an active promotion
 * @param tabId the tab to check
 * returns if there is a promotion
 */
+(BOOL)hasActiveTabPromotion:(int)tabId;

/**
 * Check for an active promotion
 * @param shop entry the entry to check
 * returns if there is a promotion
 */
+(BOOL)hasActiveEntryPromotion:(nonnull ShopEntry*)shopEntry;

/**
 * Check for an active promotion
 * @param packageId the tab to check
 * returns if there is a promotion
 */
+(BOOL)hasPackagePromotion:(nonnull NSString*)packageId;

#pragma mark Ads

/**
 * Requests the more apps screen
 */
+(void)requestMoreApps;

/**
 * Show the more apps screen
 */
+(void)showMoreApps;

/**
 * Request a reward video
 * @param rewardType    The expected reward type (optional)
 * @param location      The location the reward video was requested from (optional)
 */
+(void)requestRewardVideo:(nullable NSString*)rewardType withLocation:(nullable NSString*)location;

/**
 * Show the last requested reward video
 * @param rewardType    The expected reward type (optional)
 * @param location      The location the reward video was requested from (optional)
 */
+(void)playRewardVideo:(nullable NSString*)rewardType withLocation:(nullable NSString*)location;

/**
 * Helper method to determine if the ad provider is initialized
 */
+(BOOL)isAdProviderInitialized:(nonnull NSString*)identifier;

/**
 * Show a toast when a reward is unlocked
 */
+(void)showToastOnVideoReward:(BOOL)enabled;

/**
 * Call to inform the SDK that the parental gate was (not) passes
 */
+(void)closedParentalGate:(BOOL)pass;

/**
 * Request a banner ad
 * Position: top/bottom
 * Format: banner format
 */
+(void)requestBannerAd:(nonnull NSString*)position format:(nonnull NSString*)format;

/**
 * Requests an interstitial ad
 */
+(void)requestInterstitial;

/**
 * Shows an interstitial ad
 */
+(void)showInterstitialAd:(nullable NSString*)adProvider;

/**
 * Shows a banner ad
 */
+(void)showBannerAd;

/**
 * Hides a banner ad
 */
+(void)hideBannerAd;

/**
  * Checks if an ad of adType is available
 */
+(BOOL)isAdAvailable:(nullable NSString*)adType;

/**
 * Sets a testing device for ad networks and in certain cases enables test mode (depending on the mediation)
 */
+(void)setAdTestDevice:(nonnull NSString*)deviceId;

#pragma mark UserData & GameData

/**
 * Request the player data
 */
+(void)updatePlayerData;

/**
 * Request the game data
 */
+(void)requestGameData;

/**
 * Returns the entire user profile as json
 */
+(nullable NSString*)getUserProfile;

/**
 * Returns the wallet data as an object
 */
+(nullable Wallet*)getWalletData;

/**
 * Returns the wallet data as json
 */
+(nullable NSString*)getWallet;

/**
 * Returns the configured game data as json
 */
+(nullable NSString*)getGamedockGameData;

/**
 * Returns the inventory data as an object
 */
+(nullable Inventory*)getInventoryData;

/**
 * Returns the inventory data as json
 */
+(nullable NSString*)getInventory;

+(UserDataTransaction*)beginUserDataTransaction;

/**
 * Returns the shop data as json
 */
//+(nullable NSString*)getShop;

/**
 * Returns the shop promotions data as json
 */
//+(nullable NSString*)getShopPromotions;

/**
 * Add currency to the wallet
 * @param currencyId    Id of the currency
 * @param amount        Amount to add
 * @param reason        The add reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)addCurrencyToWallet:(int)currencyId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction;

/**
 * Subtract currency from the wallet
 * @param currencyId    Id of the currency
 * @param amount        Amount to subtract
 * @param reason        The subtract reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)subtractCurrencyFromWallet:(int)currencyId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction;

/**
 * Add item to the inventory
 * @param itemId        Id of the item
 * @param amount        Amount to add
 * @param reason        The add reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)addItemToInventory:(int)itemId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction;

/**
 * Subtract item to from the inventory
 * @param itemId        Id of the item
 * @param amount        Amount to subtract
 * @param reason        The subtract reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)subtractItemFromInventory:(int)itemId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction;

/**
 * Uses the bundle and will add the items to the inventory and subtract the currency from the wallet
 * @param bundleId      Id of the bundle
 * @param reason        The bundle reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 * @param transactionId A json blob containing a PerkItem object
 */
+(void)buyBundle:(int)bundleId withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId withPerkItems:(nullable NSArray*)perkItems;

/**
 * Open the gacha and add the content to the inventory
 * @param itemId        The id of the gacha
 * @param reason        The bundle reason
 * @param reasonDetails The bundle reasonDetails
 * @param location      The location where the event happened, for example level1
 */
+(NSMutableDictionary* _Nullable)openGacha:(int)itemId withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withPerkItems:(nullable NSArray*)perkItems isTransaction:(BOOL)isTransaction;

/**
 * Get all the shop tabs
 * Returns an array with ShopTab objects
 */
+(nonnull NSMutableArray*)getShopTabs;

/**
 * Get a bundle by bundle id
 * @param bundleId      Id of the bundle
 * Returns a bundle matching the provided bundle id
 */
+(nullable Bundle*)getBundle:(int)bundleId;

/**
 * Get an item by id
 * @param itemId        Id of the item
 * Returns an item matching the provided item id
 */
+(nullable PlayerItem*)getItem:(int)itemId;

/**
 * Get an unique item by id
 * @param uniqueId        Id of the unique item
 * Returns an unique item matching the provided unique item id
 */
+(nullable UniquePlayerItem*)getUniqueItem:(nonnull NSString*)uniqueId;

/**
 * Get a currency by the provided currency id
 * @param currencyId    Id of the currency
 * Returns a currency matching the provided currency id
 */
+(nullable PlayerCurrency*)getCurrency:(int)currencyId;

/**
 * Resets all the player data
 */
+(void)resetPlayerData;

/**
 * Resets all the mission data
 */
+(void)resetMissionData;

/**s
 * Resets the inventory data
 */
+(void)resetInventory;

/**
 * Resets the wallet data
 */
+(void)resetWallet;

/**
 * Limits the max allowed currency amount
 */
+(void)setCurrencyLimit:(int)currencyId withLimit:(int)limit;

/**
 * Limits the max allowed item amount
 */
+(void)setItemLimit:(int)itemId withLimit:(int)limit;

+(nonnull NSMutableArray*)getUserAllContainerProgress;
+(nonnull NSString*)getUserAllContainerProgressJSON:(nullable NSMutableArray*)containerProgressList;

+(nonnull NSMutableArray*)getUserAllMissionProgress;
+(nonnull NSString*)getUserAllMissionProgressJSON:(nullable NSMutableArray*)missionProgressList;

+(void)updateContainerProgress:(nonnull NSMutableArray*)containerProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)updateMissionProgress:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)updateContainerAndMissionProgress:(nonnull NSMutableArray*)containerProgressList withMissionProgress:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)claimContainersReward:(nonnull NSMutableArray*)containerProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)claimMissionsReward:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

/**
 * Create a new unique item with a unique id
 */
+(nonnull UniquePlayerItem*)createUniqueItem:(int)itemId withUniqueId:(nonnull NSString*)uniqueId;

/**
 * Add an unique item to the inventory
 */
+(NSMutableDictionary* _Nullable)addUniqueItemToInventory:(nonnull NSString*)uniquePlayerItemJSON withReason:(nonnull NSString*)reason withReasonDetails:(nonnull NSString*)reasonDetails withLocation:(nonnull NSString*)location withTransactionId:(nonnull NSString*)transactionId isTransaction:(BOOL)isTransaction;

/**
 * Update an unique item to the inventory
 */
+(NSMutableDictionary* _Nullable)updateUniqueItemFromInventory:(nonnull NSString*)uniquePlayerItemJSON withReason:(nonnull NSString*)reason withReasonDetails:(nonnull NSString*)reasonDetails withLocation:(nonnull NSString*)location withTransactionId:(nonnull NSString*)transactionId isTransaction:(BOOL)isTransaction;

/**
 * Removes an unique item to the inventory
 */
+(NSMutableDictionary* _Nullable)removeUniqueItemFromInventory:(nonnull NSString*)uniquePlayerItemJSON withReason:(nonnull NSString*)reason withReasonDetails:(nonnull NSString*)reasonDetails withLocation:(nonnull NSString*)location withTransactionId:(nonnull NSString*)transactionId isTransaction:(BOOL)isTransaction;

#pragma mark Customer support

/**
 * Shows the help center webview version
 * @param url   The url to open
 */
+(void)showHelpCenterWebview:(nonnull NSString*)url withTags:(nonnull NSString*)tags;

#pragma mark Daily bonus

/**
 * Request the daily bonus screen
 */
+(void)requestDailyBonus;

/**
 * Shows the daily bonus screen
 */
+(void)showDailyBonus;

/**
 * Returns the current loaded daily bonus config
 */
+(nonnull NSString*)getDailyBonusConfig;

/**
 * Collects the current daily bonus data
 */
+(void)collectDailyBonus;

#pragma mark Splashscreens

/**
 * Request a splash screen
 * @param type   The type of splashscreen to request
 */
+(void)requestSplashScreen:(nullable NSString*)type;

/**
 * Show a prepared splash screen
 */
+(void)showSplashScreen;

#pragma mark User data

/**
 * Get the custom user id
 */
+(nullable NSString*)getExternalUserId;

/**
 * Get the custom provider id
 */
+(nullable NSString*)getExternalUserProvider;

/**
 * Set private game state data.
 * @param privateData The private data to store
 */
+(void)setPrivateGameState:(nonnull NSString*)privateData;

/**
 * Get private game state data.
 */
+(nullable NSString*)getPrivateGameState;

/**
 * Set public game state data.
 * @param publicData The public data to store
 */
+(void)setPublicGameState:(nonnull NSString*)publicData;

/**
 * Get public game state data.
 */
+(nullable NSString*)getPublicGameState;

/**
 * Get the public game state data of other users, based on the user id of a custom provider.
 * @param provider The provider to request the data from
 * @param userIds The user ids
 */
+(void)getOtherUsersGameState:(nonnull NSString*)provider userIds:(nonnull NSArray*)userIds;

#pragma image cache

/**
 * Converts a web url to local file path
 * @param url The image url
 * Return the local image path, returns nil if their is no local file path for the url
 */
+(nullable NSString*)getImagePathForUrl:(nonnull NSString*)url;

/**
 * Requests an image based on the url provided
 * @param url The URL to load
 * @param idx The id this image belongs to (optional)
 * @param imageType The image type of this image (optional)
 */
+(void)requestImage:(nonnull NSString*)url withId:(int)idx withImageType:(nullable NSString*)imageType;

/**
 * Removes all images from the disk cache
 */
+(void)clearDiskCache;

/**
 * Automatically preloads all images for all items and bundles
 */
+(void)preloadItemAndBundleImages;

#pragma tiered events

/**
 * Request the current tiered events
 */
+(void)requestTieredEvents;

/**
 * Get all the loaded tiered events
 */
+(nonnull NSArray*)getAllTieredEvents;

/**
 * Get all the loaded tiered events, as objects
 */
+(nonnull NSArray*)getAllTieredEventsData;

/**
 * Get the progress of the requested tiered event
 */
+(nonnull NSDictionary*)getTieredEventProgress:(int)tieredEventId;

/**
 * Get the progress of the requested tiered event, as objects
 */
+(nonnull TieredEventProgress*)getTieredEventProgressData:(int)tieredEventId;

/**
 * Show the progress of the requested tiered event
 */
+(void)showTieredEventProgress:(int)tieredEventId;

/**
 * Claim tier reward
 */
+(void)claimTierReward:(int)tieredEventId withTierId:(int)tierId;

#pragma user login

/**
 * Used to login, will automatically call setExternalUserId
 * @param externalUserId The social user id to use
 * @param externalProviderId The id of the service (e.g. facebook)
 * @param externalToken The auth token provided by the external provider
 */
+(void)loginWithExternalUserId:(nonnull NSString*)externalUserId externalProviderId:(nonnull NSString*)externalProviderId externalToken:(nonnull NSString*)externalToken socialValidationData:(nonnull NSDictionary*)socialValidationData;

/**
 * Returns the current login status
 */
+(BOOL)isLoggedIn;

/**
 * Logout the user
 */
+(void)logout:(BOOL)global;

/**
 * Logout the user and let him continue as guest
 */
+(void)userPlayAsGuest;

/**
 * Will reset the gameconfig, packages/promotions, gamedata, playerdata & gamestate
 */
+(void)resetData;

/**
 * Call when the game is ready to change the uid requested by Gamedock Backend 
 */
+(void)confirmUserIdChange;

/**
 * Show the default auth error dialog
 */
+(void)showAuthorizedDialog:(nonnull NSString*)title message:(nonnull NSString*)message loginButtonText:(nonnull NSString*)loginButtonText guestButtonText:(nonnull NSString*)guestButtonText;

#pragma mark data syncing

/**
 * Get the device id
 */
+(nonnull NSString*)getDeviceId;

/**
 * Request the current userdata, which includes the wallet, inventory and private gamestate
 */
+(void)requestUserData;

/**
 * Used to merge resolve a merge conflict in the current userdata which is triggered by mergeConflict:remoteData: delegate
 * @param mergedUserData The result of the merge
 */
+(void)mergeUserData:(nonnull NSString*)mergedUserData mergeType:(nonnull NSString*)mergeType;

/**
 * Show the default merge error dialog
 */
+(void)showMergeConflictDialog:(nonnull NSString*)title message:(nonnull NSString*)message localButtonText:(nonnull NSString*)localButtonText remoteButtonText:(nonnull NSString*)remoteButtonText mergeButtonText:(nonnull NSString*)mergeButtonText;

/**
 * Show the default merge error dialog
 */
+(void)showSyncErrorDialog:(nonnull NSString*)title message:(nonnull NSString*)message mergeButtonText:(nonnull NSString*)mergeButtonText;

/**
 * Show the default user data merge failed dialog
 */
+(void)showUserDataMergeFailedDialog:(nonnull NSString*)title withMessage:(nonnull NSString*)message retryButtonText:(nonnull NSString*)retryButton mergeData:(nonnull NSString*)mergeData mergeType:(nonnull NSString*)mergeType;

#pragma mark Asset bundles

/**
 * Show the default user data merge failed dialog
 */
+(void)requestAssetBundles;

/**
 * Get the loaded asset bundles as json list
 */
+(nonnull NSArray*)getAssetBundles;

#pragma mark Firebase

/**
 * Requests the firebase config
 */
+(void)requestFirebaseRemoteConfig:(long)cacheExpirationTime;

/**
 * Sets the default firebase config values
 */
+(void)setFirebaseRemoteConfigDefaults:(nonnull NSDictionary*)defaultValues;

/**
 * Get a bool value from the firebase config
 */
+(BOOL)getBooleanFirebaseRemoteConfig:(nonnull NSString*)key namespaceValue:(nonnull NSString*)namespaceValue;

/**
 * Get a double value from the firebase config
 */
+(double)getDoubleFirebaseRemoteConfig:(nonnull NSString*)key namespaceValue:(nonnull NSString*)namespaceValue;

/**
 * Get a long value from the firebase config
 */
+(long)getLongFirebaseRemoteConfig:(nonnull NSString*)key namespaceValue:(nonnull NSString*)namespaceValue;

/**
 * Get a string value from the firebase config
 */
+(nonnull NSString*)getStringFirebaseRemoteConfig:(nonnull NSString*)key namespaceValue:(nonnull NSString*)namespaceValue;

#pragma mark Store

/**
  * Mehtod used to show the Apple App Rate popup
 */
+(void)showAppRatePopup;

#pragma test methods (dev)

/**
 * Set a custom user id for a specified service.
 * @param userId The social user id to use
 * @param providerId The id of the service (e.g. facebook)
 */
+(void)setExternalUserId:(nonnull NSString*)userId forProviderId:(nonnull NSString*)providerId;

/**
 * NOTE: Those methods are exposed just for ad testing, they should not be referenced in the final implementation, params:
 * adProvider: admob|dfp
 * adType: interstitial|rewardVideo|moreApps
 * parentalGate: not implemented yet (always false)
 */

+(void)devRequestAd:(nonnull NSString*)provider withAdType:(nonnull NSString*)adType withParentalGate:(BOOL)parentalGate withLocation:(nonnull NSString*)location;
+(nullable NSString*)getRawAdProvidersData;

@end
