//
//  Gamedock+Events.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Events)

#pragma clang diagnostic pop
/**
 * Track a milstone achieved event
 * @param name          The name of the milestone
 */
+(void)trackMilestoneAchievedEvent:(nonnull NSString*)name;

/**
 * Track a level start
 * @param level         The name of the level
 * @param customCreated Indictating if the level was custom created
 * @param creatorId     The id of the creator of the level
 */
+(void)trackLevelStartEvent:(nonnull NSString*)level customCreated:(bool)customCreated creatorId:(nonnull NSString*)creatorId;

/**
 * Track a level complete
 * @param level         The name of the level
 * @param score         The final score the player achieves at the end of the level
 * @param stars         The # of stars (or any other rating system) the player achieves at the end of the level
 * @param turns         The # of moves/turns taken to complete the level
 * @param customCreated Indictating if the level was custom created
 * @param creatorId     The id of the creator of the level
 */
+(void)trackLevelCompleteEvent:(nonnull NSString*)level score:(double)score stars:(int)stars turns:(int)turns customCreated:(bool)customCreated creatorId:(nonnull NSString*)creatorId;

/**
 * Track a level fail
 * @param level         The name of the level
 * @param score         The final score the player achieves at the end of the level
 * @param stars         The # of stars (or any other rating system) the player achieves at the end of the level
 * @param turns         The # of moves/turns taken to complete the level
 * @param customCreated Indictating if the level was custom created
 * @param creatorId     The id of the creator of the level
 */
+(void)trackLevelFailedEvent:(nonnull NSString*)level score:(double)score stars:(int)stars turns:(int)turns customCreated:(bool)customCreated creatorId:(nonnull NSString*)creatorId;

/**
 * Track a level up
 * @param level         The name of the level
 * @param score         The final score the player achieves at the end of the level
 * @param objectId      The level up object identifier
 * @param skillId       The skill id
 */
+(void)trackLevelUpEvent:(nonnull NSString*)level objectId:(nonnull NSString*)objectId skillId:(nonnull NSString*)skillId;

/**
 * Track an item equip
 * @param equippedItem  The id of the equipped item
 * @param equippedTo    The id of were the item will be equipped to
 */
+(void)trackEquipEvent:(nonnull NSString*)equippedItem equippedTo:(nonnull NSString*)equippedTo;

/**
 * Track an item upgrade
 * @param upgradeId     The id of the upgraded item
 * @param level         The level in which the upgrade happened
 * @param reason        The upgrade reason
 * @param iteration     The upgrade iteration
 */
+(void)trackUpgradeEvent:(nonnull NSString*)upgradeId level:(nonnull NSString*)level reason:(nonnull NSString*)reason iteration:(int)iteration;

/**
 * Track a level create event
 * @param levelId       The id of the created level
 * @param creatorId     The id of the level creator
 */
+(void)trackLevelCreateEvent:(nonnull NSString*)levelId creatorId:(nonnull NSString*)creatorId;

/**
 * Track a download event
 * @param levelId       The id of the downloaded level
 * @param creatorId     The id of the level creator
 * @param rating        The level rating
 */
+(void)trackLevelDownloadEvent:(nonnull NSString*)levelId creatorId:(nonnull NSString*)creatorId rating:(int)rating;

/**
 * Track a level rate event
 * @param levelId       The id of the rated level
 * @param creatorId     The id of the level creator
 * @param rating        The level rating
 */
+(void)trackLevelRateEvent:(nonnull NSString*)levelId creatorId:(nonnull NSString*)creatorId rating:(int)rating;

/**
 * Track the start of an endless level
 */
+(void)trackEndlessModeStartEvent;

/**
 * Track the end of an endless mode level
 * @param level         The distance completed in the endless level
 */
+(void)trackEndlessModeEndEvent:(int)distance;

/**
 * Track a player dies event
 * @param level         The name of the level in which the player dies
 */
+(void)trackPlayerDiesEvent:(nonnull NSString*)level;

/**
 * Track a wallet/inventory update
 * @param reason        The reason for which the wallet or the inventory has been updated
 * @param location      The location where the event occurred (ex.: Shop Screen, End of the level Screen)
 * @param currencyList  A list containing the currency objects that have been changed with the event.
 * @param itemsList     A list containing the item objects that have been changed with the event.
 */
+(void)trackWalletInventoryEvent:(nonnull NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails location:(nullable NSString*)location currencyList:(nullable NSString*)currencyList itemList:(nullable NSString*)itemsList;

/**
 * Track a successful iap
 * @param skuId             The product identifier of the item that was purchased
 * @param transactionId     The transaction identifier of the item that was purchased (also called orderId)
 * @param purchaseDate      The date and time that the item was purchased
 * @param reasonDetails     The reason details for this iap
 */
+(void)trackIAPPurchasedEvent:(nonnull NSString*)skuId transactionId:(nonnull NSString*)transactionId purchaseDate:(nonnull NSString*)purchaseDate withReasonDetails:(nonnull NSString*)reasonDetails;

/**
 * Track a restored iap
 * @param skuId                 The product identifier of the item that was purchased
 * @param originalTransactionId For a transaction that restores a previous transaction, the transaction identifier of the original transaction.
 *                              Otherwise, identical to the transaction identifier
 * @param originalPurchaseDate  For a transaction that restores a previous transaction, the date of the original transaction
 */
+(void)trackIAPRestoredEvent:(nonnull NSString*)skuId originalTransactionId:(nonnull NSString*)originalTransactionId originalPurchaseDate:(nonnull NSString*)originalPurchaseDate;

/**
 * Track a failed iap
 * @param skuId     The product identifier of the item that was purchased
 * @param error     Error description or error code
 */
+(void)trackIAPFailedEvent:(nonnull NSString*)skuId error:(nonnull NSString*)error;

/**
 * Track the completion of a tutorial
 */
+(void)trackTutorialCompleteEvent;

/**
 * Track a skipped tutorial
 * Track the skipping of a tutorial
 */
+(void)trackTutorialSkippedEvent;

/**
 * Track a register
 * @param platform      The platform for which the registration occurred (ex.: Facebook)
 */
+(void)trackRegisterEvent:(nonnull NSString*)platform;

/**
 * Track a share
 * @param platform      The platform for which the share occurred (ex.: Facebook)
 */
+(void)trackShareEvent:(nonnull NSString*)platform;

/**
 * Track an invite
 * @param platform      The platform for which the invite occurred (ex.: Facebook)
 */
+(void)trackInviteEvent:(nonnull NSString*)platform;

/**
 * Track a basic named event
 * @param name         The name of the event. Replace spaces with an underscore
 */
+(void) trackEvent:(nonnull NSString*)name;

/**
 * Track a named events with a key / value object
 * @param name The name of the event. Replace spaces with an underscore
 * @param params A key value dictionary holding the params
 */
+(void) trackEvent:(nonnull NSString*)name withParameters:(nullable NSDictionary *)params;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Track a basic named event with a response
 * @param name  The name of the event. Replace spaces with an underscore
 * @param block A block with response param that will be executed when the server sends a reponse on the tracked event
 */
+(void) trackEvent:(nonnull NSString*)name onResponse:(void (^)(id response))block;

/**
 * Track a named event params and a response
 * @param name   The name of the event. Replace spaces with an underscore
 * @param params A key value dictionary holding the params
 * @param block  A block with response param that will be executed when the server sends a reponse on the tracked event
 */
+(void) trackEvent:(nonnull NSString*)name withParameters:(nonnull NSDictionary *)params onResponse:(void (^)(id response))block;

/**
 * Track an error event
 * @param type    The error type (e.g. "adjust")
 * @param action  The error action (e.g. "intall")
 * @param message The error message (e.g. "no connection")
 */
+(void) trackErrorWithType:(NSString*)type withAction:(NSString*)action withMessage:(NSString*)message;

@end

NS_ASSUME_NONNULL_END
