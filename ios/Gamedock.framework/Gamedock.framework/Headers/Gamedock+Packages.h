//
//  Gamedock+Packages.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Packages)
/**
 * Get the latest stored store packages.
 * @return NSArray object representation from the stored store packages
 */
+(nullable NSArray*)getAllPackages;

+(nullable NSString*)getAllPackagesJSON;

/**
 * Get a specific package from the store
 * @param packageId. Must be NSString.
 * @return returns the store package, or nil if not found
 */
+(nullable NSDictionary*)getPackageByPackageID:(nonnull NSString*)packageId;
    
/**
 * Get a specific package from the store
 * @param id. Must be int.
 * @return returns the store package, or nil if not found
 */
+(nullable NSDictionary*)getPackageByID:(int)id;

/**
 * Get the latest stored store promotions.
 * @return NSArray object representation from the stored store promotions
 */
+(nullable NSArray*)getAllPromotions;
+(nullable NSString*)getAllPromotionsJSON;
/**
 * Get the promotion for a bundle
 * @param id    Id of the bundle. Type must be int.
 * @return returns a promotion for the package id
 */
+(nullable NSDictionary*)getBundlePromotion:(int)bundleId;

/**
 * Get the promotion for a package
 * @param id    Id of the package. Type must be NSString.
 * @return returns a promotions for the bundle id
 */
+(nullable NSDictionary*)getPackagePromotion:(nonnull NSString*)packageId;

/**
 * Refresh the mission data
 */
+(void)requestMissionConfiguration;

/**
 * Refresh the promotion data
 */
+(void)requestPromotions;

+(nonnull NSMutableArray*)getContainersConfiguration;
+(nonnull NSString*)getContainersConfigurationJSON;

+(nullable Container*)getMissionContainer:(nonnull NSString*)containerId;

+(nonnull NSMutableArray*)getMissionsConfiguration:(nullable NSString*)containerId;

+(nonnull NSMutableArray*)getMissionsConfigurationWithPrerequisites:(nonnull NSMutableArray*)missionPrerequisites;

+(nonnull NSMutableArray*)getMissionsConfigurationWithUnlocks:(nonnull NSMutableArray*)missionUnlocks;

+(nullable NSMutableArray*)getAllMissionConfigurations;
+(nonnull NSString*)getAllMissionConfigurationsJSON;

+(nullable Mission*)getMissionConfiguration:(nonnull NSString*)missionId;

/**
 * Show the promotion screen
 * @param promotionId the promotion id to show the screen for
 */
+(void)showPromotionScreen:(int)promotionId;

/**
 * Check for an active promotion
 * @param tabId the tab to check
 * returns if there is a promotion
 */
+(BOOL)hasActiveTabPromotion:(int)tabId;

/**
 * Check for an active promotion
 * @param shop entry the entry to check
 * returns if there is a promotion
 */
+(BOOL)hasActiveEntryPromotion:(nonnull ShopEntry*)shopEntry;

/**
 * Check for an active promotion
 * @param packageId the tab to check
 * returns if there is a promotion
 */
+(BOOL)hasPackagePromotion:(nonnull NSString*)packageId;
@end

NS_ASSUME_NONNULL_END
