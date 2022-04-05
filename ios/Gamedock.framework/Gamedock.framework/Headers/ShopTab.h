//
//  ShopTab.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ShopEntry.h"
#import "ImageEntry.h"

@interface ShopTab : NSObject

@property (nonatomic, assign) int position;
@property (nonatomic, strong) NSString* name;
@property (strong, nonatomic) NSDictionary *properties;
@property (nonatomic, strong) NSMutableArray *entries; // ShopEntry
@property (nonatomic, strong) NSMutableArray *imageEntries; // ImageEntry
@property (nonatomic, assign) BOOL hasActivePromotions;

-(id)initWithDictionary:(NSDictionary*)data;

-(void)updateHasPromotions;

-(NSDictionary*)toJSONObject;

-(NSString*)getImageUrl:(NSString*)name;

@end
