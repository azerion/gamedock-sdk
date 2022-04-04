//
//  Gamedock+AssetBundles.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (AssetBundles)

/**
 * Show the default user data merge failed dialog
 */
+(void)requestAssetBundles;

/**
 * Get the loaded asset bundles as json list
 */
+(nonnull NSArray*)getAssetBundles;
@end

NS_ASSUME_NONNULL_END
