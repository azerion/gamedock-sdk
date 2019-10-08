//
//  ContainerProgress.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ContainerProgress : NSObject

@property(nonatomic, strong) NSString* containerId;
@property(nonatomic, strong) NSString* status;
@property(assign, nonatomic) long lastCompleted;

-(id)initWithDictionary:(NSDictionary*)dict;

-(ContainerProgress*)Clone;

-(NSMutableDictionary*)toBackEndJSONObject;
-(NSMutableDictionary*)toUnityJSONObject;

@end
