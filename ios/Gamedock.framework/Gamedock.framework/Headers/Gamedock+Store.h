//
//  Gamedock+Store.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Store)

#pragma mark Subscription Validation

+(void)validateSubscription:(nonnull NSString*)skuId withTransactionId:(nonnull NSString*)transactionId withToken:(nonnull NSString*)token;

#pragma mark Store

/**
  * Method used to show the Apple App Rate popup
 */
+(void)showAppRatePopup;

@end

NS_ASSUME_NONNULL_END
