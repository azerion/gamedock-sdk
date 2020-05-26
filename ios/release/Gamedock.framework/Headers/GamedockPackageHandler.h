//
//  GamedockPackageHandler.h
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Promotion.h"
#import "Package.h"
#import "ShopEntry.h"

static NSString* const FEATURE_NAME_VG = @"virtualGoods";
static NSString* const FEATURE_NAME_PROMO = @"promotions";

@interface GamedockPackageHandler : NSObject

@property (strong, nonatomic) NSMutableArray *loadedPackages;
@property (strong, nonatomic) NSMutableArray *loadedPromotions;

+(GamedockPackageHandler*)sharedInstance;

-(void)processPackagesResponse:(NSArray*) packagesData;
-(void)savePackages;
-(NSArray*)getAllPackages;
-(NSArray*)getAllPackagesObject;
-(NSDictionary*)getPackageByPackageID:(NSString*)packageId;
-(Package*)getPackageByPackageIDObject:(NSString*)packageId;
-(NSDictionary*)getPackageByID:(int)id;
-(Package*)getPackageByIDObject:(int)id;

-(void)requestPromotions;
-(void)savePromotions;
-(NSArray*)getAllPromotions;
-(NSArray*)getAllPromotionsObject;
-(NSDictionary*)getBundlePromotion:(int)bundleId;
-(Promotion*)getBundlePromotionObject:(int)bundleId;
-(NSDictionary*)getPackagePromotion:(NSString*)packageId;
-(Promotion*)getPackagePromotionObject:(NSString*)packageId;
-(void)trackBoughtPromotion:(Promotion*)promotion;
-(void)showPromotionScreen:(int)promotionId;
-(BOOL)hasActiveTabPromotion:(int)tabId;
-(BOOL)hasActiveEntryPromotion:(ShopEntry*)shopEntry;
-(BOOL)hasPackagePromotion:(NSString*)packageId;

-(NSArray*)getImageUrls;

@end
