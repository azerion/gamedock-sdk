//
//  InitializationOptions.h
//  GamedockSDK
//
//  Created by Sebastian Vasile on 12/11/2019.
//  Copyright © 2019 Spil Games. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Gamedock.h"

@interface InitializationOptionsBuilder : NSObject
@property (nonatomic) BOOL withAgeGate;
@property (nonatomic) BOOL autoProcessAgeGate;
@property (nonatomic) BOOL ageGateShouldBlock;
@property (nonatomic) int ageGateRequiredAge;
@property (nonatomic) BOOL withPrivacyPolicy;
@property (nonatomic) BOOL autoProcessPrivacyPolicy;
@property (nonatomic) BOOL isCoppaEnabled;
@property (nonatomic, copy) NSDictionary *externalIds;

@property (nonatomic) BOOL enableStaging;
@property (nonatomic, copy) NSString *pluginName;
@property (nonatomic, copy) NSString *pluginVersion;
@end

@interface InitializationOptions : NSObject
@property (nonatomic, readonly) BOOL withAgeGate;
@property (nonatomic, readonly) BOOL autoProcessAgeGate;
@property (nonatomic, readonly) BOOL ageGateShouldBlock;
@property (nonatomic, readonly) int ageGateRequiredAge;
@property (nonatomic, readonly) BOOL withPrivacyPolicy;
@property (nonatomic, readonly) BOOL autoProcessPrivacyPolicy;
@property (nonatomic, readonly) BOOL isCoppaEnabled;
@property (nonatomic, copy, readonly) NSDictionary *externalIds;

@property (nonatomic, readonly) BOOL enableStaging;
@property (nonatomic, copy, readonly) NSString *pluginName;
@property (nonatomic, copy, readonly) NSString *pluginVersion;

- (instancetype)init;
- (instancetype)initWithBuilder:(InitializationOptionsBuilder *)builder;
+ (instancetype)makeWithBuilder:(void (^)(InitializationOptionsBuilder *))updateBlock;
- (instancetype)update:(void (^)(InitializationOptionsBuilder *))updateBlock;
@end


