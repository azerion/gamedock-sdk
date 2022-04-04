//
//  GamedockEventTracker.h
//  Gamedock
//
//  Copyright (c) 2015 Azerion. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(int, GamedockPrivacyStatus) {
    GamedockPrivacyStatusDoesntExist = -1,
    GamedockPrivacyStatusWithoutContentWithoutAds,
    GamedockPrivacyStatusWithContentWithoutAds,
    GamedockPrivacyStatusWithoutContentWithAds,
    GamedockPrivacyStatusWithContentWithAds
};

@interface GamedockEventTracker : NSObject

// --- Properties ---

@property (atomic) BOOL hasNetworkConnection;
@property (nonatomic) BOOL isUnity;
@property (nonatomic) BOOL privacyPolicyEnabled;
@property (atomic,assign) BOOL isStaging;

// --- Singleton ---

+(GamedockEventTracker*)sharedInstance;

// --- Init ---

-(void)startUsingUnity:(BOOL)pUnityEnabled privacyPolicyEnabled:(BOOL)pPrivacyPolicyEnabled;

// --- Meta data --

-(void)setCustomBundleId:(NSString*)bundleId;
-(void)setPluginInformation:(NSString*)pluginNameParam pluginVersion:(NSString*)pluginVersionParam;
-(void)setPushKey:(NSString*)pushKey;
-(void)setPrivValue:(GamedockPrivacyStatus)privValue;
-(void)setPrivValueWithContentValue:(bool)contentValue adsValue:(bool)adsValue completion:(void (^)(GamedockPrivacyStatus))completion;

-(NSString*)getBundleId;
-(NSString*)getBuildType;
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
-(GamedockPrivacyStatus)getPrivValue;
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

-(void)refreshEndPointPath;
-(void)setProductionEnvironment;
-(void)setStagingEnvironment;


@end
