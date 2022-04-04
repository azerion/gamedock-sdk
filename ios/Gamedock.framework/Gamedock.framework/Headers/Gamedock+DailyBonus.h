//
//  Gamedock+DailyBonus.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (DailyBonus)

/**
 * Request the daily bonus screen
 */
+(void)requestDailyBonus;

/**
 * Shows the daily bonus screen
 */
+(void)showDailyBonus;

/**
 * Returns the current loaded daily bonus config
 */
+(nonnull NSString*)getDailyBonusConfig;

/**
 * Collects the current daily bonus data
 */
+(void)collectDailyBonus;
@end

NS_ASSUME_NONNULL_END
