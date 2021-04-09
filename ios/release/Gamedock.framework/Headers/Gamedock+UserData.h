//
//  Gamedock+UserData.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (UserData)

/**
 * Request the player data
 */
+(void)updatePlayerData;

/**
 * Request the game data
 */
+(void)requestGameData;

/**
 * Returns the entire user profile as json
 */
+(nullable NSString*)getUserProfile;

/**
 * Returns the wallet data as an object
 */
+(nullable Wallet*)getWalletData;

/**
 * Returns the wallet data as json
 */
+(nullable NSString*)getWallet;

/**
 * Returns the configured game data as json
 */
+(nullable NSString*)getGamedockGameData;

/**
 * Returns the inventory data as an object
 */
+(nullable Inventory*)getInventoryData;

/**
 * Returns the inventory data as json
 */
+(nullable NSString*)getInventory;

+(UserDataTransaction*)beginUserDataTransaction;

/**
 * Returns the shop data as json
 */
//+(nullable NSString*)getShop;

/**
 * Returns the shop promotions data as json
 */
//+(nullable NSString*)getShopPromotions;

/**
 * Add currency to the wallet
 * @param currencyId    Id of the currency
 * @param amount        Amount to add
 * @param reason        The add reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)addCurrencyToWallet:(int)currencyId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Subtract currency from the wallet
 * @param currencyId    Id of the currency
 * @param amount        Amount to subtract
 * @param reason        The subtract reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)subtractCurrencyFromWallet:(int)currencyId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Add item to the inventory
 * @param itemId        Id of the item
 * @param amount        Amount to add
 * @param reason        The add reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)addItemToInventory:(int)itemId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Subtract item to from the inventory
 * @param itemId        Id of the item
 * @param amount        Amount to subtract
 * @param reason        The subtract reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 */
+(NSMutableDictionary* _Nullable)subtractItemFromInventory:(int)itemId withAmount:(int)amount withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Uses the bundle and will add the items to the inventory and subtract the currency from the wallet
 * @param bundleId      Id of the bundle
 * @param reason        The bundle reason
 * @param location      The location where the event happened, for example level1
 * @param transactionId The transaction id used
 * @param transactionId A json blob containing a PerkItem object
 */
+(void)buyBundle:(int)bundleId withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId withPerkItems:(nullable NSArray*)perkItems withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Open the gacha and add the content to the inventory
 * @param itemId        The id of the gacha
 * @param reason        The bundle reason
 * @param reasonDetails The bundle reasonDetails
 * @param location      The location where the event happened, for example level1
 */
+(NSMutableDictionary* _Nullable)openGacha:(int)itemId withReason:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withPerkItems:(nullable NSArray*)perkItems isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Get all the shop tabs
 * Returns an array with ShopTab objects
 */
+(nonnull NSMutableArray*)getShopTabs;

/**
 * Get a bundle by bundle id
 * @param bundleId      Id of the bundle
 * Returns a bundle matching the provided bundle id
 */
+(nullable Bundle*)getBundle:(int)bundleId;

/**
 * Get an item by id
 * @param itemId        Id of the item
 * Returns an item matching the provided item id
 */
+(nullable PlayerItem*)getItem:(int)itemId;

/**
 * Get an unique item by id
 * @param uniqueId        Id of the unique item
 * Returns an unique item matching the provided unique item id
 */
+(nullable UniquePlayerItem*)getUniqueItem:(nonnull NSString*)uniqueId;

/**
 * Get a currency by the provided currency id
 * @param currencyId    Id of the currency
 * Returns a currency matching the provided currency id
 */
+(nullable PlayerCurrency*)getCurrency:(int)currencyId;

/**
 * Resets all the player data
 */
+(void)resetPlayerData;

/**
 * Resets all the mission data
 */
+(void)resetMissionData;

/**s
 * Resets the inventory data
 */
+(void)resetInventory;

/**
 * Resets the wallet data
 */
+(void)resetWallet;

/**
 * Limits the max allowed currency amount
 */
+(void)setCurrencyLimit:(int)currencyId withLimit:(int)limit;

/**
 * Limits the max allowed item amount
 */
+(void)setItemLimit:(int)itemId withLimit:(int)limit;

+(nonnull NSMutableArray*)getUserAllContainerProgress;
+(nonnull NSString*)getUserAllContainerProgressJSON:(nullable NSMutableArray*)containerProgressList;

+(nonnull NSMutableArray*)getUserAllMissionProgress;
+(nonnull NSString*)getUserAllMissionProgressJSON:(nullable NSMutableArray*)missionProgressList;

+(void)updateContainerProgress:(nonnull NSMutableArray*)containerProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)updateMissionProgress:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)updateContainerAndMissionProgress:(nonnull NSMutableArray*)containerProgressList withMissionProgress:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)claimContainersReward:(nonnull NSMutableArray*)containerProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

+(void)claimMissionsReward:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

/**
 * Create a new unique item with a unique id
 */
+(nonnull UniquePlayerItem*)createUniqueItem:(int)itemId withUniqueId:(nonnull NSString*)uniqueId;

/**
 * Add an unique item to the inventory
 */
+(NSMutableDictionary* _Nullable)addUniqueItemToInventory:(nonnull NSString*)uniquePlayerItemJSON withReason:(nonnull NSString*)reason withReasonDetails:(nonnull NSString*)reasonDetails withLocation:(nonnull NSString*)location withTransactionId:(nonnull NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Update an unique item to the inventory
 */
+(NSMutableDictionary* _Nullable)updateUniqueItemFromInventory:(nonnull NSString*)uniquePlayerItemJSON withReason:(nonnull NSString*)reason withReasonDetails:(nonnull NSString*)reasonDetails withLocation:(nonnull NSString*)location withTransactionId:(nonnull NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

/**
 * Removes an unique item to the inventory
 */
+(NSMutableDictionary* _Nullable)removeUniqueItemFromInventory:(nonnull NSString*)uniquePlayerItemJSON withReason:(nonnull NSString*)reason withReasonDetails:(nonnull NSString*)reasonDetails withLocation:(nonnull NSString*)location withTransactionId:(nonnull NSString*)transactionId isTransaction:(BOOL)isTransaction withCallback:(nullable UserDataCustomCallback*)customUserDataCallback;

#pragma mark data syncing



/**
 * Request the current userdata, which includes the wallet, inventory and private gamestate
 */
+(void)requestUserData;

/**
 * Used to merge resolve a merge conflict in the current userdata which is triggered by mergeConflict:remoteData: delegate
 * @param mergedUserData The result of the merge
 */
+(void)mergeUserData:(nonnull NSString*)mergedUserData mergeType:(nonnull NSString*)mergeType;

/**
 * Show the default merge error dialog
 */
+(void)showMergeConflictDialog:(nonnull NSString*)title message:(nonnull NSString*)message localButtonText:(nonnull NSString*)localButtonText remoteButtonText:(nonnull NSString*)remoteButtonText mergeButtonText:(nonnull NSString*)mergeButtonText;

/**
 * Show the default merge error dialog
 */
+(void)showSyncErrorDialog:(nonnull NSString*)title message:(nonnull NSString*)message mergeButtonText:(nonnull NSString*)mergeButtonText;

/**
 * Show the default user data merge failed dialog
 */
+(void)showUserDataMergeFailedDialog:(nonnull NSString*)title withMessage:(nonnull NSString*)message retryButtonText:(nonnull NSString*)retryButton mergeData:(nonnull NSString*)mergeData mergeType:(nonnull NSString*)mergeType;

@end

NS_ASSUME_NONNULL_END
