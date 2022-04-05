//
//  EnvironmentDetector.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 28/12/2020.
//  Copyright © 2020 Spil Games. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIApplication+EnvironmentDetector.h"

NS_ASSUME_NONNULL_BEGIN

@interface EnvironmentDetector : NSObject
+ (EnvironmentType)getBuildType;
+ (NSString*)getStringFrom:(EnvironmentType)type;
@end

NS_ASSUME_NONNULL_END
