//
//  UpdatedMissionData.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UpdatedMissionData : NSObject

@property(nonatomic, strong) NSMutableArray* containerProgressList; // ArrayList<ContainerProgress>
@property(nonatomic, strong) NSMutableArray* missionProgressList; // ArrayList<MissionProgress>

-(NSMutableDictionary*)toUnityJSONObject;

@end
