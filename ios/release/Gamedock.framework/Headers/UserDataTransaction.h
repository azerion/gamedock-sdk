//
//  UserDataTransaction.h
//  Gamedock
//
//  Created by Sebastian Vasile on 26/03/2020.
//  Copyright © 2020 Spil Games. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Gamedock.h"
#import "UniquePlayerItem.h"
#import "PlayerDataController.h"
#import <Gamedock/GamedockError.h>
#import "JsonUtil.h"

@interface UserDataTransaction : NSObject

@property (strong, nonatomic) NSMutableArray *transactions; // Transactions

-(instancetype)init;
-(void)addCurrency:(int)currencyId withAmount:(int)amount;
-(void)subtractCurrency:(int)currencyId withAmount:(int)amount;
-(void)addItem:(int)itemId withAmount:(int)amount;
-(void)subtractItem:(int)itemId withAmount:(int)amount;
-(void)openGacha:(int)gachaId;
-(void)addUniqueItem:(UniquePlayerItem*)uniquePlayerItem;
-(void)removeUniqueItem:(UniquePlayerItem*)uniquePlayerItem;
-(void)updateUniqueItem:(UniquePlayerItem*)uniquePlayerItem;
-(void)submit:(NSString*)reason withReasonDetails:(NSString*)reasonDetails withLocation:(NSString*)location withTransactionId:(NSString*)transactionId;
-(BOOL)validateTransactions:(NSMutableArray*)transactions;
-(void)updateTransactionData:(NSMutableDictionary*)currentData withNewData:(NSMutableDictionary*)newData;
@end

@interface Transaction : NSObject

@property (nonatomic, copy) NSString *source;
@property (nonatomic, copy) NSString *operation;
@property (nonatomic, copy) NSString *type;
@property (nonatomic) int entityId;
@property (nonatomic) int amount;
@property (strong, nonatomic) UniquePlayerItem* uniquePlayerItem;

-(instancetype)initWithValues:(NSString*)source withOperation:(NSString*)operation withType:(NSString*)type withEntityId:(int)entityId withAmount:(int)amount withUniquePlayerItem:(UniquePlayerItem*)uniquePlayerItem;
-(instancetype)initWithDictionary:(NSDictionary*)dictionary;

@end
