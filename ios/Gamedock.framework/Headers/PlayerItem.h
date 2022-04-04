//
//  PlayerItem.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@protocol PlayerItem
@end

@interface PlayerItem : Item

@property (nonatomic) int amount;
@property (nonatomic) int delta;
@property (nonatomic) int overflow;

-(id)init;
-(id)initWithItem:(Item*)item;
-(id)initWithDictionary:(NSDictionary*)dict;

-(NSDictionary*)toJSONObject:(bool)includeContent;

@end
