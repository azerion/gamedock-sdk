//
//  GamedockDelegate.h
//  GamedockSDK
//
//  Created by Andrey Ildyakov on 16/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

@class ImageContext;
@class TieredEventProgress;

@protocol GamedockDelegate

@optional

// Initialization flow completed
-(void)initializationCompleted;

////Ads Events
//-(void)adsInitialized; // Ads component fully initialized
//-(void)adAvailable:(nonnull NSString*)type; // An ad is available
//-(void)adNotAvailable:(nonnull NSString*)type; // An ad is unavailable or did fail to load
//-(void)adStart:(nonnull NSString*)type; // An ad has started
//-(void)adFinished:(nonnull NSString*)type reason:(nonnull NSString*)reason reward:(nonnull NSString*)reward network:(nonnull NSString*)network; // An ad has finished (dismissed or an reward was granted)
//-(void)openParentalGate; // The ad requires a parental gate check to continue, present the parental gate in this method and call the closedParentalGate method to pass the result back to the GamedockSDK.
//More Apps Events
- (void)noMoreAppsAvailable:(nonnull NSString*)type;
- (void)moreAppsAvailable:(nonnull NSString*)type;
- (void)didDismissMoreApps:(nonnull NSString*)type network:(nonnull NSString*)network;
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

// Azerion Connect
-(void)azerionLoginSuccessful:(nonnull NSString*)data;
-(void)azerionLoginFailed:(nonnull NSString*)data;

-(void)azerionLogoutSuccessful:(nonnull NSDictionary*)data;
-(void)azerionLogoutFailed:(nonnull NSDictionary*)data;

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
-(void)attPermissionStatus:(int)status;
-(void)privValueChangeForced:(int)priv;

//Localization
///Callback if localization is available (contains also the locale in case the default locale is returned)
-(void)onLocalizationAvailable:(NSString*)locale isDefaultLocale:(BOOL)isDefaultLocale;
-(void)onLocalizationNotAvailable;
-(void)onLocalizationError:(NSString*)error;

@end
