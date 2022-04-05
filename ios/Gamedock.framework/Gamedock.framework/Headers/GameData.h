//
//  GameData.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"
#import "Currency.h"
#import "Bundle.h"
#import "ShopTab.h"

@interface GameData : NSObject

@property (strong, nonatomic) NSMutableArray *items; // Item
@property (strong, nonatomic) NSMutableArray *currencies; // Currency
@property (strong, nonatomic) NSMutableArray *bundles; // Bundle
@property (strong, nonatomic) NSMutableArray *shop; // ShopTab

-(id)initWithDictionary:(NSDictionary*)data;

-(NSMutableDictionary*)toJSONObject;

-(NSString*)toJSONString;

-(NSString*)getShopJSONString;

-(Item*)getItem:(int)itemId;
-(Currency*)getCurrency:(int)currencyId;

@end
