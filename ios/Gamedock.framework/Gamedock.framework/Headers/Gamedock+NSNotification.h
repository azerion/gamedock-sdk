//
//  Gamedock+NSNotification.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (NSNotification)

/// Method to handle inner notifications
/// @param notification NSNotification value
-(void)gamedockNotificationHandler:(NSNotification *)notification;

@end

NS_ASSUME_NONNULL_END
