//
//  MissionsConfiguration.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MissionsConfiguration : NSObject

@property(nonatomic, strong) NSMutableArray* containers; // Array<MissionContainer>

@property(nonatomic, strong) NSMutableArray* missions; // Array<Mission>

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSString*)Build:(MissionsConfiguration*)gameData;

-(NSMutableDictionary*)toJSONObject;

@end
