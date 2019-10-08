//
//  MissionProgress.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MissionProgress : NSObject

@property(nonatomic, strong) NSString* missionId;
@property(nonatomic, strong) NSString* status;
@property(nonatomic, strong) NSMutableDictionary* progress;
@property(assign, nonatomic) long lastCompleted;

-(id)initWithDictionary:(NSDictionary*)dict;

-(MissionProgress*)Clone;

-(NSMutableDictionary*)toBackEndJSONObject;
-(NSMutableDictionary*)toUnityJSONObject;

@end
