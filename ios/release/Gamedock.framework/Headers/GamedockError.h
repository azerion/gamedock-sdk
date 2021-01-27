//
//  GamedockError.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GamedockError : NSObject

@property (nonatomic, assign) int id;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *message;

-(id)initWithId:(int)_id name:(NSString*)_name message:(NSString*)_message;

-(NSDictionary*)toJSONObject;
-(NSString*)toJson;

+(GamedockError*)LoadFailed:(NSString*)message;
+(GamedockError*)ItemNotFound:(NSString*)message;
+(GamedockError*)CurrencyNotFound:(NSString*)message;
+(GamedockError*)BundleNotFound:(NSString*)message;
+(GamedockError*)WalletNotFound:(NSString*)message;
+(GamedockError*)InventoryNotFound:(NSString*)message;
+(GamedockError*)NotEnoughCurrency:(NSString*)message;
+(GamedockError*)ItemAmountToLow:(NSString*)message;
+(GamedockError*)CurrencyOperationFailed:(NSString*)message;
+(GamedockError*)ItemOperationFailed:(NSString*)message;
+(GamedockError*)BundleOperationFailed:(NSString*)message;

+(GamedockError*)PublicGameStateOperationFailed:(NSString*)message;
+(GamedockError*)GameStateOtherUsersServerError:(NSString*)message;

+(GamedockError*)DailyBonusServerError;
+(GamedockError*)DailyBonusLoadError;

+(GamedockError*)SplashScreenLoadError;

+(GamedockError*)FileCacheError:(NSString*)message;

+(GamedockError*)RewardTokenClaimError:(NSString*)message;

+(GamedockError*)ConfigServerError;

+(GamedockError*)GameDataServerError;

+(GamedockError*)IAPServerError;

+(GamedockError*)ServerTimeRequestError;

+(GamedockError*)LiveEventServerError;
+(GamedockError*)LiveEventInvalid;
+(GamedockError*)LiveEventMissingNextStage;
+(GamedockError*)LiveEventLoadError;

+(GamedockError*)GachaNotFoundError;
+(GamedockError*)GachaOperationError;
+(GamedockError*)NotEnoughGachaBoxes;

+(GamedockError*)InvalidGamedockTokenError;
+(GamedockError*)RequiresLoginError;
+(GamedockError*)InvalidSocialTokenError;
+(GamedockError*)UserAlreadyLinkedError;
+(GamedockError*)SocialIdAlreadyLinkedError;
+(GamedockError*)SocialLoginServerError;
+(GamedockError*)UserDataServerError;

+(GamedockError*)ConfigResetError;
+(GamedockError*)GameDataResetError;
+(GamedockError*)UserDataResetError;

+(GamedockError*)TieredEventShowProgressError;
+(GamedockError*)TieredEventUpdateProgressError;
+(GamedockError*)TieredEventClaimTierError;

+(GamedockError*)UniqueItemAddError;

+(GamedockError*)MissionConfigurationServerError;
+(GamedockError*)ContainerOperation;
+(GamedockError*)MissionOperation;
+(GamedockError*)OperationTooFrequent;

+(GamedockError*)TransactionOperation;

+(GamedockError*)LocalizationError;
+(GamedockError*)ConnectionError;

@end
