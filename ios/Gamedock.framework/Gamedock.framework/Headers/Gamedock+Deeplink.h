//
//  Gamedock+Deeplink.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Deeplink)
/**
 * Used to handle firebase/adjust deeplinks, could also be used to process any other 3rd party deeplink url by the Gamedock SDK
 * @param url           The url to process
 */
+(void)handleDeeplink:(nullable NSURL*)url;
+(void)handleUrlSchemeDeeplink:(NSURL*)url;
+(void)handleUniversalDeeplink:(NSURL*)url;
@end

NS_ASSUME_NONNULL_END
