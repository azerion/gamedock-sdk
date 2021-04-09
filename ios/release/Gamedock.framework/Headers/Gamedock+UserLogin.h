//
//  Gamedock+UserLogin.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (UserLogin)

/**
 * Used to login, will automatically call setExternalUserId
 * @param externalUserId The social user id to use
 * @param externalProviderId The id of the service (e.g. facebook)
 * @param externalToken The auth token provided by the external provider
 */
+(void)loginWithExternalUserId:(nonnull NSString*)externalUserId externalProviderId:(nonnull NSString*)externalProviderId externalToken:(nonnull NSString*)externalToken socialValidationData:(nonnull NSDictionary*)socialValidationData;

/**
 * Returns the current login status
 */
+(BOOL)isLoggedIn;

/**
 * Logout the user
 */
+(void)logout:(BOOL)global;

/**
 * Logout the user and let him continue as guest
 */
+(void)userPlayAsGuest;

/**
 * Will reset the gameconfig, packages/promotions, gamedata, playerdata & gamestate
 */
+(void)resetData;

/**
 * Call when the game is ready to change the uid requested by Gamedock Backend
 */
+(void)confirmUserIdChange;

/**
 * Show the default auth error dialog
 */
+(void)showAuthorizedDialog:(nonnull NSString*)title message:(nonnull NSString*)message loginButtonText:(nonnull NSString*)loginButtonText guestButtonText:(nonnull NSString*)guestButtonText;

@end

NS_ASSUME_NONNULL_END
