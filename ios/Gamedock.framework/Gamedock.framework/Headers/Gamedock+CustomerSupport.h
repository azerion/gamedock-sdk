//
//  Gamedock+CustomerSupport.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (CustomerSupport)

/**
 * Shows the help center webview version
 * @param url   The url to open
 */
+(void)showHelpCenterWebview:(nonnull NSString*)url withTags:(nonnull NSString*)tags;

@end

NS_ASSUME_NONNULL_END
