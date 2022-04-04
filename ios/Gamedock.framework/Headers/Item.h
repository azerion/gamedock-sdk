//
//  Item.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GachaContent.h"

@interface Item : NSObject

@property (assign, nonatomic) int id;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSDictionary *properties;
@property (assign, nonatomic) int type;
@property (assign, nonatomic) int initialValue;
@property (strong, nonatomic) NSString *imageUrl;
@property (strong, nonatomic) NSString *displayName;
@property (strong, nonatomic) NSString *displayDescription;
@property (assign, nonatomic) int limit;
@property (strong, nonatomic) NSString *reportingName;
@property (assign, nonatomic) bool isUnique;

@property (assign, nonatomic) int isGacha;
@property (strong, nonatomic) NSMutableArray *gachaContent;

@property (assign, nonatomic) bool allowDuplicates;
@property (assign, nonatomic) bool shouldReroll;
@property (retain, nonatomic) GachaContent *duplicateReward;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSMutableDictionary*)toJSONObject:(bool)includeContent;

-(GachaContent*)getRandomGachaReward;
-(GachaContent*)getRandomGachaReward:(NSArray*)perkItems;

-(BOOL)isDuplicateGachaContentResult:(GachaContent*)gachaContent;

@end
