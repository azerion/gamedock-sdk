//
//  GDUserDefaultsKeys.h
//  GamedockSDK
//
//  Created by Andrey Ildyakov on 24/09/2020.
//  Copyright © 2020 Spil Games. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const struct GDUserDefaultsKeysReadable
{
    //group name
    __unsafe_unretained NSString *groupName;
    
    __unsafe_unretained NSString *localization;
    __unsafe_unretained NSString *defaultLocalization;
    __unsafe_unretained NSString *privacySettingsWereOpened;
    __unsafe_unretained NSString *gamedockDebugmode;
    __unsafe_unretained NSString *gamedockUsingstaging;
    __unsafe_unretained NSString *gamedockPassword;
    __unsafe_unretained NSString *bundleIdentifier;
    __unsafe_unretained NSString *spilAgegateAge;
    __unsafe_unretained NSString *assetBundles;
    __unsafe_unretained NSString *config;
    __unsafe_unretained NSString *latestSessionUpdateDate;
    __unsafe_unretained NSString *sessionDuration;
    __unsafe_unretained NSString *totalTimeOpen;
    __unsafe_unretained NSString *sessionId;
    __unsafe_unretained NSString *pushkey;
    __unsafe_unretained NSString *priv;
    __unsafe_unretained NSString *appInstalled;
    __unsafe_unretained NSString *appVersion;
    __unsafe_unretained NSString *nextEventId;
    __unsafe_unretained NSString *nextSendId;
    __unsafe_unretained NSString *gamedockGameData;
    __unsafe_unretained NSString *spilgamesMissionsV1;
    __unsafe_unretained NSString *packagesV2;
    __unsafe_unretained NSString *promotionsV2;
    __unsafe_unretained NSString *totalNetworkSentUsage;
    __unsafe_unretained NSString *totalNetworkReceiveUsage;
    __unsafe_unretained NSString *playerDataInitialized;
    __unsafe_unretained NSString *spilUserProfile;
    __unsafe_unretained NSString *spilGdprFinished;
    __unsafe_unretained NSString *spilUserToken;
    __unsafe_unretained NSString *externalUserProvider;
    __unsafe_unretained NSString *externalUserId;
    __unsafe_unretained NSString *deviceVersions;
    __unsafe_unretained NSString *userid;
    __unsafe_unretained NSString *privateGameStateData;
    __unsafe_unretained NSString *publicGameStateData;
    __unsafe_unretained NSString *packages;
    __unsafe_unretained NSString *promotions;
    __unsafe_unretained NSString *ignoreSlotPrivateGamestate;
    __unsafe_unretained NSString *ignoreSlotPublicGamestate;
    __unsafe_unretained NSString *initialValuesSend;
    __unsafe_unretained NSString *gamedockMissionsV1;
    __unsafe_unretained NSString *metadata;
    __unsafe_unretained NSString *externalIds;
    __unsafe_unretained NSString *spilgamesVersion;
    __unsafe_unretained NSString *featuresInfo;
    __unsafe_unretained NSString *featuresVersionIds;
    __unsafe_unretained NSString *gamedockResetUid;
    __unsafe_unretained NSString *debugModeEnabled;
    __unsafe_unretained NSString *stgEnabled;
    __unsafe_unretained NSString *gamedockUid;
    __unsafe_unretained NSString *gamedockAppVersion;
    __unsafe_unretained NSString *gamedockApiVersion;
} GDUserDefaultsKey;

