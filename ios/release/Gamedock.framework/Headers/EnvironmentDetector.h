//
//  EnvironmentDetector.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 28/12/2020.
//  Copyright © 2020 Spil Games. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//Environment enum
typedef enum {
    development = 0,
    adhoc,
    distribution
} EnvironmentType;


@interface EnvironmentDetector : NSObject
+ (EnvironmentType)getBuildType;
+ (NSString*)getStringFrom:(EnvironmentType)type;
@end

NS_ASSUME_NONNULL_END
