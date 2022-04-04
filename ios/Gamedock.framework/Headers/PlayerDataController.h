//
//  PlayerDataController.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Gamedock/MissionData.h>
#import <Gamedock/UserDataCustomCallback.h>
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
@class UserDataCustomCallback;

static NSString* const FEATURE_NAME_UD_P = @"userData";

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

-(NSMutableDictionary*)updateWallet:(int)currencyId withDelta:(int)delta withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;
-(NSMutableDictionary*)updateInventoryWithItem:(int)itemId withAmount:(int)amount withAction:(NSString*)action withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;
-(void)updateInventoryWithBundle:(int)bundleId withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId withPerkItems:(NSArray*)perkItems buy:(bool)buy withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

-(NSDictionary*)updateCurrencyReward:(UserProfile*)userProfile withCurrencyId:(int)currencyId withCurrencyAmount:(int)currencyAmount withPromotion:(Promotion*)promotion withPerkItems:(NSMutableArray*)perkItems;
-(NSDictionary*)updateItemReward:(UserProfile*)userProfile withItemId:(int)itemId withItemAmount:(int)itemAmount withPromotion:(Promotion*)promotion withPerkItems:(NSMutableArray*)perkItems;

-(NSMutableDictionary*)openGacha:(int)itemId withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withPerkItems:(NSArray*)perkItems isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

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
-(NSMutableDictionary*)addUniqueItemToInventory:(NSString*)uniquePlayerItemJSON withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;
-(NSMutableDictionary*)updateUniqueItemFromInventory:(NSString*)uniquePlayerItemJSON withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;
-(NSMutableDictionary*)removeUniqueItemFromInventory:(NSString*)uniquePlayerItemJSON withReason:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

@end
