//
//  Inventory.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlayerItem.h"
#import "UniquePlayerItem.h"

@interface Inventory : NSObject

@property (strong, nonatomic) NSMutableArray *items; // PlayerItem
@property (strong, nonatomic) NSMutableArray *uniqueItems; // UniquePlayerItem

@property (nonatomic) long long offset;
@property (strong, nonatomic) NSString* logic;

-(id)init;
-(id)initWithDictionary:(NSDictionary*)data;

-(NSDictionary*)toJSONObject;
-(NSString*)toJSONString;

-(NSArray*)getItemsJSONArray;
-(NSArray*)getUniqueItemsJSONArray;

-(void)addUniqueItem:(UniquePlayerItem*)uniqueItem;
-(void)removeUniqueItem:(UniquePlayerItem*)uniqueItem;

-(void)updateItem:(PlayerItem*)item;
-(void)updateUniqueItem:(UniquePlayerItem*)uniqueItem;

-(NSArray*)getUpdatedItems:(bool)includeContent;
-(NSArray*)getUpdatedUniqueItems:(bool)includeContent;

-(PlayerItem*)getItem:(int)id;
-(UniquePlayerItem*)getUniqueItem:(NSString*)uniqueId;

-(BOOL)hasUniqueItem:(int)itemId;

-(void)reset;

-(void)resetDeltas;

@end
