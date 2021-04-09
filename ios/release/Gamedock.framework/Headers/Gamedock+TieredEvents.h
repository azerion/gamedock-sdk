//
//  Gamedock+TieredEvents.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (TieredEvents)

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
@end

NS_ASSUME_NONNULL_END
