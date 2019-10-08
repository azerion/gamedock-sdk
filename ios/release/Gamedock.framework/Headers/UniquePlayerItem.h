//
//  UniquePlayerItem.h
//  Gamedock
//
//  Copyright © 2018 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@protocol UniquePlayerItem
@end

@interface UniquePlayerItem : Item

@property (nonatomic, retain) NSString *uniqueId;
@property (retain, nonatomic) NSDictionary *uniqueProperties;
@property (nonatomic) int amount;
@property (nonatomic) int delta;
@property (nonatomic, retain) NSString *status; // UPDATE, NONE(only in requestUserData), CREATE(not in mvp), REMOVE

-(id)init;
-(id)initWithItem:(Item*)item withUniqueItemId:(NSString*)uniqueId;
-(id)initWithDictionary:(NSDictionary*)dict;
-(NSDictionary*)toJSONObject:(bool)includeContent;

@end
