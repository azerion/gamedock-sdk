//
//  GamedockMissionsHandler.h
//  Gamedock
//
//  Copyright © 2019 Azerion. All rights reserved.
//

#import <Gamedock/MissionsConfiguration.h>
#import <Gamedock/MissionData.h>
#import <Gamedock/MissionProgress.h>
#import <Gamedock/ContainerProgress.h>
#import <Foundation/Foundation.h>
#import <Gamedock/Mission.h>
#import <Gamedock/Container.h>
#import <Gamedock/UserProfile.h>

enum Status {
    NULL_,
    INACTIVE,
    PENDING_ACTIVATION,
    IN_PROGRESS,
    PENDING_COLLECTION,
    COMPLETED
};

@interface GamedockMissionsHandler : NSObject

@property (strong, nonatomic, nullable) NSMutableArray* receivedMissionContainers; // Array<MissionConfiguration>
@property (strong, nonatomic, nullable) NSMutableArray* receivedMissions; // Array<Mission>
@property (strong, nonatomic, nullable) MissionsConfiguration* missionConfiguration;

@property (assign, nonatomic) bool loadFailedFired;

+(nonnull GamedockMissionsHandler*)sharedInstance;

+(enum Status)statusFromNSString:(nonnull NSString*)status;
+(nonnull NSString*)statusToUnityString:(enum Status)formatType;
+(nonnull NSString*)statusToNSString:(enum Status)formatType;

// Mission configurations

-(void)requestMissionConfiguration;

//ArrayList<MissionContainer>
-(nonnull NSMutableArray*)getContainersConfiguration;

-(nullable Container*)getContainerConfiguration:(nonnull NSString*)containerId;

//ArrayList<Mission>
-(nonnull NSMutableArray*)getMissionsConfiguration:(nullable NSString*)containerId;

//ArrayList<Mission> getMissionsConfigurationWithPrerequisites(ArrayList<String> missionPrerequisites);
-(nonnull NSMutableArray*)getMissionsConfigurationWithPrerequisites:(nullable NSMutableArray*)missionPrerequisites;

//ArrayList<Mission> getMissionsConfigurationWithUnlocks(ArrayList<String> missionUnlocks);
-(nonnull NSMutableArray*)getMissionsConfigurationWithUnlocks:(nullable NSMutableArray*)missionUnlocks;

-(nullable NSMutableArray*)getAllMissionConfigurations;

-(nullable Mission*)getMissionConfiguration:(nonnull NSString*)missionId;

-(void)processMissionConfig;

-(nullable MissionsConfiguration*)getMissionConfiguration;

-(nullable NSString*)getMissionConfigurationJSON;

-(void)updateMissionConfiguration:(nonnull MissionsConfiguration*)missionConfiguration;

-(nullable NSString*)loadMissionConfigFromAssets;

-(void)resetMissionConfiguration;

// Mission data

-(void)processMissionData:(nullable MissionData*)missionData;

//ArrayList<ContainerProgress>
-(nonnull NSMutableArray*)getUserAllContainerProgress:(enum Status)containerStatus;

-(nullable ContainerProgress*)getContainerProgress:(nonnull NSString*)containerId;

-(void)updateContainerProgress:(nonnull UserProfile*)userData withContainerProgress:(nonnull ContainerProgress*)containerProgress;

-(void)updateContainerProgress:(nullable NSMutableArray*)containerProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

//ArrayList<MissionProgress>
-(nonnull NSMutableArray*)getUserAllMissionProgress:(enum Status)containerStatus;

-(nullable MissionProgress*)getMissionProgress:(nonnull NSString*)missionId;

-(void)updateMissionProgress:(nonnull UserProfile*)userData withMissionProgress:(nonnull MissionProgress*)missionProgress;

-(void)updateMissionProgress:(nullable NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

-(void)updateContainerAndMissionProgress:(nonnull NSMutableArray*)containerProgressList withMissionProgress:(nonnull NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

-(void)claimContainersReward:(nullable NSMutableArray*)containerProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

-(void)claimMissionsReward:(nullable NSMutableArray*)missionProgressList withReason:(nullable NSString*)reason withReasonDetails:(nullable NSString*)reasonDetails withLocation:(nullable NSString*)location withTransactionId:(nullable NSString*)transactionId;

-(void)resetMissionDataProgress;

@end
