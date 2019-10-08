//
//  Mission.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Mission : NSObject

@property(nonatomic, strong) NSString* missionId;
@property(nonatomic, strong) NSString* containerId;
@property(nonatomic, strong) NSMutableArray* missionPrerequisites;
@property(nonatomic, strong) NSMutableArray* missionUnlocks;
@property(nonatomic, strong) NSMutableDictionary* gamePrerequisites;
@property(nonatomic, strong) NSMutableDictionary* gameUnlocks;
@property(nonatomic, strong) NSMutableArray* activationCost;
@property(nonatomic, strong) NSMutableArray* objectives;
@property(nonatomic, strong) NSMutableArray* rewards;
@property(nonatomic, strong) NSMutableDictionary* properties;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSMutableDictionary*)toJSONObject;

@end
