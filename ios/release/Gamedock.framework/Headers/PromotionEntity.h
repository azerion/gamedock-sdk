//
//  PromotionEntity.h
//  Gamedock
//
//  Copyright © 2018 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PromotionEntity : NSObject

@property (assign, nonatomic) int id;
@property (strong, nonatomic) NSString *type; // ITEM|CURRENCY|PACKAGE|BUNDLE
@property (assign, nonatomic) int amount;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSMutableDictionary*)toJSONObject;

@end
