//
//  Gamedock+PushNotifications.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (PushNotifications)

/**
 * Disable the automated registration message for push notifications
 * Should be called before [Gamedock start]
 */
+(void)disableAutomaticRegisterForPushNotifications;

/**
 * Helper function to register for push notifications
 */
+(void)registerPushNotifications;
@end

NS_ASSUME_NONNULL_END
