//
//  Util.h
//  Gamedock
//
//  Copyright © 2016 Azerion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface Util : NSObject

+(UIColor*)colorFromHexString:(NSString *)hexString;

+(BOOL)date:(NSDate*)date isBetweenDate:(NSDate*)beginDate andDate:(NSDate*)endDate;
+(NSDate*)parseDate:(NSString*)string;

+(NSString*)urlEncode:(NSString*)input;
+(NSString*)urlDecode:(NSString*)input;

+(NSString*)sha256:(NSString *)input;
+(NSString*)createSHA512:(NSString *)input;
+(NSString*)createBase64EncodedSHA512:(NSString *)input withBundleId:(NSString *)bundleId withUserId:(NSString *)userId;
+(BOOL)verifyServerSHA:(NSString *)payload withPh:(NSString *)ph;

+(UIViewController*)topMostController;
+(UIViewController*)absoluteTopMostController;

+(NSString*)getDeviceModel;

@end
