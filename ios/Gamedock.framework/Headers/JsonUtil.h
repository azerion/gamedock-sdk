//
//  JsonUtil.h
//  Gamedock
//
//  Util class to convert foundation objects to and from json.
//  It does not support serialization.
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JsonUtil : NSObject

+(id)convertStringToObject:(NSString*) jsonString;
+(NSString*)convertObjectToJson:(id) object;
+(NSString*)convertObjectToReadableJson:(id) object;

@end
