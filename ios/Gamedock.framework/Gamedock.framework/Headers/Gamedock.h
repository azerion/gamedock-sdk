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
#import <Gamedock/UserDataCustomCallback.h>
#import <Gamedock/Util.h>
#import <Gamedock/Wallet.h>
#import <Gamedock/Container.h>
#import <Gamedock/Mission.h>
#import <Gamedock/UpdatedMissionData.h>
#import <Gamedock/ErrorContext.h>
#import <Gamedock/InitializationOptions.h>
#import <Gamedock/UserDataTransaction.h>
#import <Gamedock/EnvironmentDetector.h>
#import "HookBridge.h"
#import "GAI.h"
#import <Gamedock/GamedockDelegate.h>

#define GAMEDOCK_SDK_VERSION @"5.0.0"

@class Gamedock;
@class InitializationOptions;
@class UserDataTransaction;
@class TieredEventProgress;


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
@property (nonatomic, retain, nullable) NSArray *whitelistedEvents;
@property (nonatomic, assign) EnvironmentType buildType;
@property (nonatomic, assign) BOOL isUnpublished;
@property (nonatomic, retain, nullable) NSMutableDictionary *featuresVersionIds;
@property (nonatomic, assign) BOOL disableAutoPushNotificationRegistration;
@property (nonatomic, retain) NSURL *urlSchemeDeeplinkToHandleAfterInit;
@property (nonatomic, retain) NSURL *universalDeeplinkToHandleAfterInit;

+(nonnull Gamedock*)sharedInstance;

#pragma mark General

/**
 * Helper method to log a message to the console
 * Especially useful when building a wrapped games (e.g. Unity) where the log messages are sometimes stripped out.
 * This method gives the opportunity to log the message at the native layer instead.
 * @param The message to log
 */
+(void)log:(nonnull NSString*)message;

/// Method to check if the feature is enabled
/// @param featureName
+(BOOL)isFeatureEnabled:(nonnull NSString*)featureName;

/// Method to set the version of the feature
/// @param featureName name
/// @param versionId version
+(void)setFeatureVersionId:(nonnull NSString*)featureName withVersionId:(NSNumber*)versionId;

/// Method to get the version of the feature
/// @param featureName name
+(NSNumber*)getFeaturesVersionId:(nonnull NSString*)featureName;

/// Method to check if the event is enabled
/// @param eventName
+(BOOL)isEventEnabled:(NSString *)eventName;

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

/**
 * Get the device id
 */
+(nonnull NSString*)getDeviceId;

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

/**
 * Shows a simple dialog, useful while debugging
 */
+(void)showDialog:(NSString*)title withMessage:(NSString*)message withOkButton:(NSString*)okButtonText handler:(void (^ __nullable)(UIAlertAction *action))handler;

@end
