//
//  PackageItem.h
//  Gamedock
//
//  Copyright © 2018 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PackageItem : NSObject

@property (assign, nonatomic) int id;
@property (strong, nonatomic) NSString *type;
@property (assign, nonatomic) int value;
    
-(id)initWithDictionary:(NSDictionary*)dict;
    
-(NSMutableDictionary*)toJSONObject;
    
@end
