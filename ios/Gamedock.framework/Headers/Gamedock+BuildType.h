//
//  Gamedock+BuildType.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (BuildType)

/// Method to get the type of the build
+ (EnvironmentType)getBuildType;

@end

NS_ASSUME_NONNULL_END
