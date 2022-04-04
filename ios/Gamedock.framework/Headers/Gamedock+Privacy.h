//
//  Gamedock+Privacy.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Privacy)
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
@end

NS_ASSUME_NONNULL_END
