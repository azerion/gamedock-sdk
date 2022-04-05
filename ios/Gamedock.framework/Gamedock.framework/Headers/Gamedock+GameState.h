//
//  Gamedock+GameState.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (GameState)
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

@end

NS_ASSUME_NONNULL_END
