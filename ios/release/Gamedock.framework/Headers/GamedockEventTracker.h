//
//  GamedockEventTracker.h
//  Gamedock
//
//  Copyright (c) 2015 Azerion. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GamedockEventTracker : NSObject

// --- Properties ---

@property (atomic) BOOL hasNetworkConnection;
@property (nonatomic) BOOL isUnity;
@property (nonatomic) BOOL privacyPolicyEnabled;
@property (nonatomic, retain) NSString *adjustId;

// --- Singleton ---

+(GamedockEventTracker*)sharedInstance;

// --- Init ---

-(void)startUsingUnity:(BOOL)pUnityEnabled privacyPolicyEnabled:(BOOL)pPrivacyPolicyEnabled;

// --- Meta data --

-(void)setCustomBundleId:(NSString*)bundleId;
-(void)setPluginInformation:(NSString*)pluginNameParam pluginVersion:(NSString*)pluginVersionParam;
-(void)setPushKey:(NSString*)pushKey;
-(void)setPrivValue:(int)privValue;

-(NSString*)getBundleId;
-(NSString*)getSessionId;
-(NSString*)getEndPointPath;
-(NSString*)getPushKey;
-(BOOL)getIsUnity;
-(BOOL)debugModeEnabled;
-(BOOL)stagingEnabled;
-(double)getClientTime;
-(int)getTimezoneOffset;
-(NSString*)getDeviceModel;
-(NSString*)getAppVersion;
-(NSString*)getPrivValue;
-(BOOL)isReservedEvent:(NSString*)name;
// --- Event tracking ---

-(void)trackEvent:(NSString*)name;
-(void)trackEvent:(NSString*)name withParameters:(NSDictionary *)parameters;
-(void)trackEvent:(NSString*)name onResponse:(void (^)(id response))block;
-(void)trackEvent:(NSString*)name withParameters:(NSDictionary *)parameters onResponse:(void (^)(id response))block;

// --- Queueing ---

-(void)scheduleNextQueuedEvent:(BOOL)wasQueued hasConnection:(BOOL)hasConnection;

// --- Subdomain checks ---

-(void)checkForNewSubdomain;

// --- App flow ---

-(void)applicationDidEnterBackground:(UIApplication *)application;
-(void)applicationDidBecomeActive:(UIApplication *)application;

@end
