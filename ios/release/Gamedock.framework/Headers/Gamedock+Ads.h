//
//  Gamedock+Ads.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Ads)

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
@end

NS_ASSUME_NONNULL_END
