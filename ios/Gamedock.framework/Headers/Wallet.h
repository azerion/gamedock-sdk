//
//  Wallet.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlayerCurrency.h"
#import "Bundle.h"
#import "PerkItem.h"

@interface Wallet : NSObject

@property (strong, nonatomic) NSMutableArray *currencies; // PlayerCurrency
@property (nonatomic) long long offset;
@property (strong, nonatomic) NSString* logic;

-(id)init;
-(id)initWithDictionary:(NSDictionary*)data;

-(NSDictionary*)toJSONObject;
-(NSString*)toJSONString;

-(NSArray*)getCurrenciesJSONArray;

-(PlayerCurrency*)getCurrency:(int)id;

-(NSArray*)getUpdatedCurrencies:(bool)includeContent;

-(BOOL)hasEnoughCurrencyForBundle:(Bundle*)bundle withPerkItems:(NSArray*)perkItems;

-(void)reset;

-(void)resetDeltas;

@end
