//
//  Gacha.h
//  Gamedock
//
//  Copyright © 2017 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GachaContent : NSObject

@property (assign, nonatomic) int amount;
@property (assign, nonatomic) int id;
@property (strong, nonatomic) NSString *type;
@property (assign, nonatomic) int weight;
@property (assign, nonatomic) int position;
@property (strong, nonatomic) NSString *imageUrl;
@property (strong, nonatomic) NSDictionary *properties;

-(id)initWithDictionary:(NSDictionary*)data;

-(NSDictionary*)toJSONObject;

@end
