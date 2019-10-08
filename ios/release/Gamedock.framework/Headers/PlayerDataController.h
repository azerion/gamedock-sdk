//
//  PlayerDataController.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Gamedock/MissionData.h>
#import "PerkItem.h"
#import "Promotion.h"

@class UserProfile;
@class PlayerCurrency;
@class Wallet;
@class Item;
@class Bundle;
@class Inventory;
@class PlayerItem;
@class UniquePlayerItem;

@interface PlayerDataController : NSObject

@property (nonatomic, retain) UserProfile *cachedUserProfile;

+(PlayerDataController*)sharedInstance;

-(void)updatePlayerData;

-(void)processPlayerData:(Wallet*)updatedWallet withInventory:(Inventory*)updatedInventory withMissionData:(MissionData*)receivedMissionData fromRequestUserData:(BOOL)fromRequestUserData;
-(void)alignOffsets:(Wallet*)updatedWallet withInventory:(Inventory*)updatedInventory;
-(void)setPlayerDataWithWallet:(Wallet*)updatedWallet withInventory:(Inventory*)updatedInventory withMissionData:(MissionData*)updatedMissionData;

-(UserProfile*)getUserProfile;

-(Wallet*)getWalletData;
-(NSString*)getWallet;

-(Inventory*)getInventoryData;
-(NSString*)getInventory;

-(void)updateWallet:(int)currencyId withDelta:(int)delta withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId;
-(void)updateInventoryWithItem:(int)itemId withAmount:(int)amount withAction:(NSString*)action withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId;
-(void)updateInventoryWithBundle:(int)bundleId withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId withPerkItems:(NSArray*)perkItems buy:(bool)buy;

-(NSDictionary*)updateCurrencyReward:(UserProfile*)userProfile withCurrencyId:(int)currencyId withCurrencyAmount:(int)currencyAmount withPromotion:(Promotion*)promotion withPerkItems:(NSMutableArray*)perkItems;
-(NSDictionary*)updateItemReward:(UserProfile*)userProfile withItemId:(int)itemId withItemAmount:(int)itemAmount withPromotion:(Promotion*)promotion withPerkItems:(NSMutableArray*)perkItems;

-(void)openGacha:(int)itemId withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withPerkItems:(NSArray*)perkItems;

-(void)updateUserProfile:(UserProfile*)userProfile;

-(void)sendUpdatePlayerDataEvent:(UserProfile*)userProfile withBundle:(Bundle*)bundle withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId withPerkItems:(NSArray*)perkItems withPromotion:(Promotion*)promotion;

-(NSString*)loadPlayerDataFromAssets;

-(void)resetPlayerData:(BOOL)sendEvent;
-(void)resetInventory;
-(void)resetWallet;

-(PlayerItem*)getItem:(int)itemId;
-(UniquePlayerItem*)getUniqueItem:(NSString*)uniqueId;
-(PlayerCurrency*)getCurrency:(int)currencyId;

-(BOOL)hasUniqueItem:(int)itemId;

-(void)setCurrencyLimit:(int)currencyId withLimit:(int)limit;
-(void)setItemLimit:(int)itemId withLimit:(int)limit;

-(UniquePlayerItem*)createUniqueItem:(int)itemId withUniqueId:(NSString*)uniqueId;
-(void)addUniqueItemToInventory:(NSString*)uniquePlayerItemJSON withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId;
-(void)updateUniqueItemFromInventory:(NSString*)uniquePlayerItemJSON withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId;
-(void)removeUniqueItemFromInventoryNative:(NSString*)uniquePlayerItemJSON withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId;

@end
