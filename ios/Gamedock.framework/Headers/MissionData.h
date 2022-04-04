//
//  MissionData.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MissionData : NSObject

@property(nonatomic, strong) NSMutableArray* containerProgressList; // ArrayList<ContainerProgress>
@property(nonatomic, strong) NSMutableArray* missionProgressList; // ArrayList<MissionProgress>
@property(assign, nonatomic) long lastOperationTime;

-(id)initWithDictionary:(NSDictionary*)dict;

-(MissionData*)Clone;

-(NSDictionary*)toJSONObject;

@end
