//
//  NSString+Extensions.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Extensions)

- (NSString *)urlencode;
- (NSString *)urldecode;
+ (NSString *)base64StringFromData:(NSData *)inputData;

@end
