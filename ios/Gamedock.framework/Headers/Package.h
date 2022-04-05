//
//  Package.h
//  Gamedock
//
//  Copyright © 2018 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Package : NSObject

@property (assign, nonatomic) int id;
@property (strong, nonatomic) NSDictionary *properties;
@property (strong, nonatomic) NSString *packageId;
@property (strong, nonatomic) NSString *discountLabel;
@property (strong, nonatomic) NSMutableArray *items; // Array of PackageItem's
    
-(id)initWithDictionary:(NSDictionary*)dict;
    
-(NSMutableDictionary*)toJSONObject;
    
@end
