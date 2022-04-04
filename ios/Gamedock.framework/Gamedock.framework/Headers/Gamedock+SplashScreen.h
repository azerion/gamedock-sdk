//
//  Gamedock+SplashScreen.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (SplashScreen)

/**
 * Request a splash screen
 * @param type   The type of splashscreen to request
 */
+(void)requestSplashScreen:(nullable NSString*)type;

/**
 * Show a prepared splash screen
 */
+(void)showSplashScreen;
@end

NS_ASSUME_NONNULL_END
