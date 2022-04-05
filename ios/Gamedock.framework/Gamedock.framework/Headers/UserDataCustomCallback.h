//
//  UserDataCustomCallback.h
//  Gamedock
//
//  Created by Sebastian Vasile on 08/03/2021.
//  Copyright © 2021 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Gamedock.h"
#import "UniquePlayerItem.h"
#import "PlayerDataController.h"
#import <Gamedock/GamedockError.h>
#import "JsonUtil.h"

@interface UserDataCustomCallback : NSObject

@property (strong, nonatomic) NSString *callbackId;

@property (nonatomic, copy) void (^playerDataCallback)(NSString *reason, NSString *updatedData, NSString *wallet, NSString *inventory);
@property (nonatomic, copy) void (^userDataError)(NSString *error);
@property (nonatomic, copy) void (^playerDataNewUniqueItem)(UniquePlayerItem *newUniquePlayerItem, int bundleId, int gachaId, int gachaPosition, int tierId, NSString *reason);

-(instancetype)init:(void(^)(NSString *reason, NSString *updatedData, NSString *wallet, NSString *inventory))playerDataCallback withUserDataError:(void(^)(NSString *error))userDataError withPlayerDataNewUniqueItem:(void(^)(UniquePlayerItem *newUniquePlayerItem, int bundleId, int gachaId, int gachaPosition, int tierId, NSString *reason))playerDataNewUniqueItem;

-(void)firePlayerData:(nonnull NSString*)reason withUpdatedData:(nonnull NSMutableDictionary*)updatedData;
-(void)fireUserDataError:(nonnull NSString*)error;
-(void)firePlayerDataNewUniqueItem:(nonnull UniquePlayerItem*)newUniquePlayerItem withBundleId:(int)bundleId withGachaId:(int)gachaId withGachaPosition:(int)gachaPosition withTierId:(int)tierId withReason:(nonnull NSString*)reason withData:(NSMutableDictionary*)data;

@end
