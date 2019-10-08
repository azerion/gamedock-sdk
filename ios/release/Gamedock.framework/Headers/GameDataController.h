//
//  GameDataController.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GameData;
@class Item;
@class Bundle;
@class Currency;

@interface GameDataController : NSObject

@property (nonatomic, retain) GameData *cachedGameData;

+(GameDataController*)sharedInstance;

-(void)requestGameData;
-(void)processGameData:(NSDictionary*)data;
-(GameData*)getGameData;

-(Item*)getItem:(int)itemId;
-(Currency*)getCurrency:(int)currency;
-(Bundle*)getBundle:(int)bundleId;

-(NSString*)getShop;
//-(NSString*)getShopPromotions;
//-(ShopPromotion*)getPromotion:(int)bundleId;

-(void)updateGameData:(GameData*)gameData;

-(NSString*)loadGameDataFromAssets;

-(NSArray*)getImageUrls;

-(NSMutableArray*)getShopTabs;

-(void)setCurrencyLimit:(int)currencyId withLimit:(int)limit;
-(void)setItemLimit:(int)itemId withLimit:(int)limit;

@end
