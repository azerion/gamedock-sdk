//
//  Gamedock+Token.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Token)

/**
 * Used to claim the reward token from the backend
 * @param token      The token to claim
 * @param rewardType The reward type to which the token belongs
 */
+(void)claimToken:(nonnull NSString*)token withRewardType:(nonnull NSString*)rewardType;
@end

NS_ASSUME_NONNULL_END
