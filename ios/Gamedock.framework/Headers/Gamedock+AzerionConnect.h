//
//  Gamedock+AzerionConnect.h
//  Gamedock
//
//  Created by Muhammed Cihan Bülbül on 4.11.2021.
//  Copyright © 2021 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (AzerionConnect)

+(void)loginAzerionConnect:(NSString *)provider;
+(void)logoutAzerionConnect;
+(void)getUserInfo;
+(void)openAzerionDashboard;

@end

NS_ASSUME_NONNULL_END
