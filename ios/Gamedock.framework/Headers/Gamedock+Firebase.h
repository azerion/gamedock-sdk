//
//  Gamedock+Firebase.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Firebase)

+(NSString*)getFirebaseInstanceId;

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

+(void)recordFirebaseCustomeException:(nonnull NSString*)name withReason:(nonnull NSString*)reason withStackTrace:(nonnull NSString*)stackTrace;

@end

NS_ASSUME_NONNULL_END
