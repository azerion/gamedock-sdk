//
//  GamedockUserHandler.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GamedockUserHandler : NSObject 

+(GamedockUserHandler*)sharedInstance;

// --- Properties ---

@property (nonatomic, assign) BOOL authConflicted;
@property (nonatomic, assign) int authErrorCode;
@property (nonatomic, retain) NSMutableDictionary *deviceVersions;
@property (nonatomic, retain) NSMutableDictionary *metadata;

// --- Gamedock user id ---

-(void)syncGamedockUserId;
-(NSString*)getGamedockUserId;
-(void)checkForSLOTUidChange;
-(void)confirmUserIdChange;

// --- Device id ---

-(NSString*)getDeviceId;

// --- Gamedock user token ---

-(NSString*)getGamedockUserToken;

// --- Reset ---

-(void)resetUID:(NSString*)uid;
-(void)resetGamedockUserToken:(NSString*)token;
-(void)resetProfile;

// --- Login ---

-(void)loginWithExternalUserId:(NSString*)externalUserId externalProviderId:(NSString*)externalProviderId externalToken:(NSString*)externalToken socialValidationData:(NSDictionary*)socialValidationData;
-(BOOL)isLoggedIn;
-(void)logout:(BOOL)global;
-(void)userPlayAsGuest;
-(void)resetData;
-(void)showOnAuthorizedDialog:(NSString*)title message:(NSString*)message loginButtonText:(NSString*)loginButtonText guestButtonText:(NSString*)guestButtonText;
-(void)showOnMergeDialog:(NSString*)title message:(NSString*)message localButtonText:(NSString*)localButtonText remoteButtonText:(NSString*)remoteButtonText mergeButtonText:(NSString*)mergeButtonText;
-(void)showOnSyncDialog:(NSString*)title message:(NSString*)message mergeButtonText:(NSString*)mergeButtonText;
-(void)showUserDataMergeFailedDialog:(NSString*)title withMessage:(NSString*)message retryButtonText:(NSString*)retryButton mergeData:(NSString*)mergeData mergeType:(NSString*)mergeType;

// --- Userdata ---

-(void)setPrivateGameState:(NSString*)privateData sendUpdate:(Boolean)sendUpdate;
-(NSString*)getPrivateGameState;
-(void)setPublicGameState:(NSString*)publicData sendUpdate:(Boolean)sendUpdate;
-(NSString*)getPublicGameState;
-(void)getOtherUsersGameState:(NSString*)provider userIds:(NSArray*)userIds;

// --- Userdata syncing ---

-(void)requestUserData;
-(void)mergeUserData:(NSString*)mergedUserData mergeType:(NSString*)mergeType;
-(void)increaseDeviceVersion;

// --- Auth errors ---

-(void)onAuthError:(int)pAuthErrorCode;

// --- External user id ---

-(void)setInitialExternalIds:(NSDictionary*)externalIds;
-(void)addId:(NSString*)userId forProviderId:(NSString*)providerId;
-(void)removeId:(NSString*)providerId;

-(void)setExternalUserId:(NSString*)userId forProviderId:(NSString*)providerId;
-(NSString*)getExternalUserId;
-(NSString*)getExternalUserProvider;

-(NSDictionary*)getExternalUserRequestData;
-(NSArray*)getExternalIdsRequestData;

// --- Updates ---

-(void)friendsGameStateLoaded:(NSDictionary*)gameStates provider:(NSString*)provider;

@end

