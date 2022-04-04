//
//  Gamedock+Dev.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Dev)

/**
 * Set a custom user id for a specified service.
 * @param userId The social user id to use
 * @param providerId The id of the service (e.g. facebook)
 */
+(void)setExternalUserId:(nonnull NSString*)userId forProviderId:(nonnull NSString*)providerId;

///**
// * NOTE: Those methods are exposed just for ad testing, they should not be referenced in the final implementation, params:
// * adProvider: admob|dfp
// * adType: interstitial|rewardVideo|moreApps
// * parentalGate: not implemented yet (always false)
// */
//
//+(void)devRequestAd:(nonnull NSString*)provider withAdType:(nonnull NSString*)adType withParentalGate:(BOOL)parentalGate withLocation:(nonnull NSString*)location;
//
///// Method to a raw providers data
//+(nullable NSString*)getRawAdProvidersData;

@end

NS_ASSUME_NONNULL_END
