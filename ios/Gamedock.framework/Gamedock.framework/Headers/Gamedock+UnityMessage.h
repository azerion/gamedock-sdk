//
//  Gamedock+UnityMessage.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 17/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (UnityMessage)

#pragma clang diagnostic pop

/**
 * Unity message sender
 * @param messageName     Name of the message, should match the function in unity
 * @param objectName      The name of the Gamedock object where the script is attached to. In most cases "GamedockSDK"
 * @param data            An object which can be serialized to json
 */
+(void)sendMessageToUnity:(nonnull NSString*)messageName withData:(nonnull id)data;

/**
 * Unity message sender
 * @param messageName     Name of the message, should match the function in unity
 * @param objectName      The name of the Gamedock object where the script is attached to. In most cases "GamedockSDK"
 * @param parameterString A json string holding the data to send
 */
+(void)sendMessageToUnity:(nonnull NSString*)messageName withString:(nonnull NSString*)parameterString;

@end

NS_ASSUME_NONNULL_END
