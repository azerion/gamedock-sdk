//
//  ErrorContext.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ErrorContext : NSObject

@property (nonatomic, retain) NSString* methodCalled;
@property (nonatomic, retain) NSString* reason;
@property (nonatomic, retain) NSMutableDictionary* data; // JSON object

@end
