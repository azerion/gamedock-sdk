//
//  Gamedock+Start.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 16/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

@interface Gamedock (Start)
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
 * Method used to send the initializeSDK event and handle feature enabling/disabling responses.
 */
+(void)initializeSDK;

/**
 * Method used to initialize the components of the SDK.
 */
+(void)initializeComponents;

@end

