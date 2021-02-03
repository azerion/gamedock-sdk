//
//  UIApplication+EnvironmentDetector.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 02/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, EnvironmentType) {
    UIApplicationReleaseUnknown,
    UIApplicationReleaseSim,
    UIApplicationReleaseDev,
    UIApplicationReleaseAdHoc,
    UIApplicationReleaseAppStore,
    UIApplicationReleaseEnterprise,
};

@interface UIApplication (EnvironmentDetector)

-(EnvironmentType) releaseMode;

@end
