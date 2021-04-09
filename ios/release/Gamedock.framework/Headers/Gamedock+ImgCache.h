//
//  Gamedock+ImgCache.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (ImgCache)

/**
 * Converts a web url to local file path
 * @param url The image url
 * Return the local image path, returns nil if their is no local file path for the url
 */
+(nullable NSString*)getImagePathForUrl:(nonnull NSString*)url;

/**
 * Requests an image based on the url provided
 * @param url The URL to load
 * @param idx The id this image belongs to (optional)
 * @param imageType The image type of this image (optional)
 */
+(void)requestImage:(nonnull NSString*)url withId:(int)idx withImageType:(nullable NSString*)imageType;

/**
 * Removes all images from the disk cache
 */
+(void)clearDiskCache;

/**
 * Automatically preloads all images for all items and bundles
 */
+(void)preloadItemAndBundleImages;

@end

NS_ASSUME_NONNULL_END
