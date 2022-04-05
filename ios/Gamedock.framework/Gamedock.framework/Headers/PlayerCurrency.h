//
//  PlayerCurrency.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Currency.h"

@interface PlayerCurrency : Currency

@property (nonatomic) int currentBalance;
@property (nonatomic) int delta;
@property (nonatomic) int overflow;

-(id)init;
-(id)initWithCurrency:(Currency*)currency;
-(id)initWithDictionary:(NSDictionary*)dict;

-(NSDictionary*)toJSONObject:(bool)includeContent;

@end
