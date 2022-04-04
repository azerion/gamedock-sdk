//
//  Gamedock+LifeCycle.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>


NS_ASSUME_NONNULL_BEGIN



@interface Gamedock (LifeCycle)
/**
 * Forwarding Delegate method to let the Gamedock framework know when the app was launched
 * @param application Delegate application to be passed
 * @param launchOptions Dictionary with launch options
 */
+(void)application:(nullable UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;
/**
 * Forwarding Delegate method to let the Gamedock framework know when the app went to the background
 * @param application Delegate application to be passed
 */
+(void)applicationDidEnterBackground:(nullable UIApplication *)application;

/**
 * Forwarding Delegate method to let the Gamedock framework know when the app became active again after running in background
 * @param application Delegate application to be passed
 */
+(void)applicationDidBecomeActive:(nullable UIApplication *)application;

/**
 * Handle remote notification packages
 * @param Application     Reference to the UIApplication object
 * @param userInfo        Reference to the push notification payload
 */
+(void)application:(nullable UIApplication *)application didReceiveRemoteNotification:(nullable NSDictionary *)userInfo;
+(void)application:(nullable UIApplication *)application didReceiveRemoteNotification:(nullable NSDictionary *)userInfo fetchCompletionHandler:(void(^)(UIBackgroundFetchResult))completionHandler;
/**
 * Forwarding Delegate method to let the Gamedock framework handle deeplinks
 * @param Application          Reference to the UIApplication object
 * @param openURL              The deeplink url
 * @param sourceApplication    The app name which triggered the deeplink
 * @param annotation           The anotation of the deeplink
 */
+(BOOL)application:(nullable UIApplication *)application openURL:(nullable NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(nullable id)annotation;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Forwarding Delegate method to let the Gamedock framework handle deeplinks
 * @param Application          Reference to the UIApplication object
 * @param continueUserActivity The user activity object
 * @param restorationHandler   The restoration handler
 */
+(BOOL)application:(nullable UIApplication *)application continueUserActivity:(nullable NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray *))restorationHandler;
/**
 * Helper function to forward the app delegate listener on the deviceToken
 */
+(void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;

@end

NS_ASSUME_NONNULL_END
