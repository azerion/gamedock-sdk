//
//  Gamedock+GameConfig.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (GameConfig)

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
@end

NS_ASSUME_NONNULL_END
