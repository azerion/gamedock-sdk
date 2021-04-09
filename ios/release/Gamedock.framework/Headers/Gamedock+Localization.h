//
//  Gamedock+Localization.h
//  Gamedock
//
//  Created by Andrey Ildyakov on 18/02/2021.
//  Copyright © 2021 Spil Games. All rights reserved.
//

#import <Gamedock/Gamedock.h>

NS_ASSUME_NONNULL_BEGIN

@interface Gamedock (Localization)

///Request translation for specific locale
+(void)requestLocalization:(NSString*)locale fallbackToDefaultLocale:(BOOL)fallbackToDefaultLocale;

///Methods used to retrive a localization key
+(NSString*)getLocalization:(NSString*)localizationKey defaultValue:(NSString*)defaultValue;
+(NSString*)getLocalization:(NSString*)localizationKey defaultValue:(NSString*)defaultValue args:(NSArray<NSString*>*)args;
+(NSString*)getLocalization:(NSString*)localizationKey defaultValue:(NSString*)defaultValue argumentsDictionary:(NSDictionary*)argumentsDictionary;

@end

NS_ASSUME_NONNULL_END
