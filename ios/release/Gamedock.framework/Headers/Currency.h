//
//  Currency.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Currency : NSObject

@property (assign, nonatomic) int id;
@property (strong, nonatomic) NSString *name;
@property (assign, nonatomic) int type;
@property (assign, nonatomic) int initialValue;
@property (strong, nonatomic) NSString *imageUrl;
@property (strong, nonatomic) NSString *displayName;
@property (strong, nonatomic) NSString *displayDescription;
@property (assign, nonatomic) int limit;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSMutableDictionary*)toJSONObject:(bool)includeContent;

@end
