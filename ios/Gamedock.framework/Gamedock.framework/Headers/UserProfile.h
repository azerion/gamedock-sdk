//
//  UserProfile.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Gamedock/MissionData.h>
#import "Wallet.h"
#import "Inventory.h"

@interface UserProfile : NSObject

@property (strong, nonatomic) NSString *userID;
@property (strong, nonatomic) NSString *facebookID;
@property (strong, nonatomic) NSString *playGamesID;
@property (strong, nonatomic) NSString *username;
@property (strong, nonatomic) NSString *gender;
@property (strong, nonatomic) NSString *age;
@property (strong, nonatomic) NSString *country;

@property (strong, nonatomic) Wallet *wallet;
@property (strong, nonatomic) Inventory *inventory;
@property (strong, nonatomic) MissionData *missionData;

-(id)initWithDictionary:(NSDictionary*)dict;

-(NSDictionary*)toJSONObject;
-(NSString*)toJSONString;

@end
