//
//  ImageEntry.h
//  Gamedock
//
//  Copyright © 2017 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ImageEntry : NSObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* imageUrl;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSDictionary*)toJSONObject;

@end
