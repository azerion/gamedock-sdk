//
//  BundleItem.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlayerItem.h"

@interface BundleItem : NSObject

@property (assign, nonatomic) int id;
@property (assign, nonatomic) int amount;
@property (retain, nonatomic) NSString *type;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSDictionary*)toJSONObject;

-(PlayerItem*)getItem;

@end
