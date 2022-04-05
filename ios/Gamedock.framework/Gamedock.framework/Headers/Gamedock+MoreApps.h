//
//  Gamedock+MoreApps.h
//  Gamedock
//
//  Created by Nagib Bin Azad on 10/13/21.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

@interface Gamedock (MoreApps)

/**
 * Requests the more apps screen
 */
+(void)requestMoreApps;

/**
 * Show the more apps screen
 */
+(void)showMoreApps;

/**
 * Call to inform the SDK that the parental gate was (not) passes
 */
+(void)closedParentalGate:(BOOL)pass;

@end
