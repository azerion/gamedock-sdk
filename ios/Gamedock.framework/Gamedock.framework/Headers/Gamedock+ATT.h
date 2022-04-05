//
//  Gamedock+ATT.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (ATT)

/// Helper function to register for app transparency tracking
+(void)requestATTPermission;

/// Helper functions to register for app transparency tracking
+(void)showAppSettings;
@end

NS_ASSUME_NONNULL_END
