//
//  PerkItem.h
//  Gamedock
//
//  Copyright © 2018 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PerkPriceReduction.h"
#import "PerkAddition.h"
#import "PerkGachaWeight.h"

@interface PerkItem : NSObject

@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSArray *priceReductions;
@property (strong, nonatomic) NSArray *additions;
@property (strong, nonatomic) NSArray *gachaWeights;

-(void)addPrice:(PerkPriceReduction *)perkPriceReduction;
-(void)removePrice:(PerkPriceReduction *)perkPriceReduction;

-(void)addAddition:(PerkAddition *)perkAddition;
-(void)removeAddition:(PerkAddition *)perkAddition;

-(void)addGachaWeight:(PerkGachaWeight *)perkGachaWeight;
-(void)removeGachaWeight:(PerkGachaWeight *)perkGachaWeight;

+(PerkItem*)fromJson:(NSString *)jsonString;
-(NSDictionary*)toJson;

@end
