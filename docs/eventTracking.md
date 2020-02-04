# Event Tracking

The Gamedock platform provides you with dedicated insight into how your users are experiencing your games. This is enabled through powerful event tracking.

These are events that are expected in every game. A set of default events are provided in the Gamedock SDK and are discussed later in this chapter. While this provides insight into generic user behavior (such as the number of concurrent and unique users), it does not perform in-depth analysis. Moreover, it does not offer the possibility to create game-specific reports.

For this reason, event tracking is extended through the Gamedock's custom-built analytics solution. The Gamedock Event Tracker provides for deeper insight into the unique aspects of your game through highly customizable reports.

To facilitate this insight, Gamedock needs to know the events that require tracking. This will differ depending on the nature and design of your game. All required event-tracking information should be discussed and agreed between the game’s designers and the Gamedock Account Manager.

> No changes or additions should be made to the specified event-tracking calls without prior discussion and approval from your Gamedock Account Manager.

Default events are events that are expected in every game and can be applied to most games. The Gamedock SDK contains a helper object for each of these.

<!-- tabs:start -->

#### ** Unity **

The standard structure of an event is the following: 

**GamedockTracking.{EventName}({RequiredParametersValues}).Add{OptionalParameters}({OptionalParametersValues}).Track();** 

Some example are described below:

~~~C#
//All tracking events have dedicated objects with required values constructors
//All optional parameters have dedicated methods
//Any optional parameter is added after the constructor of the event method using the .AddX method
//In order to send the event you must call .Track() at the end of the method invocation

//Only to be used if the game doesn't use the Wallet & Inventory features
GamedockTracking.WalletInventoryEvent(reason, location)
    .AddWallet(currencyList)
    .AddInventory(inventoryList)
    .AddReasonDetails(reasonDetails)
    .AddTransactionId(transactionId) //If IAP
    .Track();

//Example of a Level Start Event
//The structure of this example applies to all other type of events
GamedockTracking.LevelStart(level)
    .AddDifficulty(difficulty)
    .AddScore(score)
    ... <- Any other optional parameters that might be required. Each parameter has a dedicated method
    .Track();
    
//Example of a IAP Purchased Event
//The structure of this example applies to all other type of events
GamedockTracking.IAPPurchased(skuId, transactionId)
    .AddReason(reason)
    .AddLocation(location)
    .AddToken(token) //Only needed for Android
    .Track();
~~~

Simply call the corresponding method at the required point in your game, and the SDK will send the event to the Gamedock back-end. It is important that the expected parameters for your game are carefully checked. These must be correct for the successful completion of the QA process. Descriptions of all methods and parameters are included in the provided SDK code.


#### ** Android **



#### ** iOS **



#### ** AIR **

For AIR, Gamedock provides a number of standard event-tracking methods:

~~~C#
Gamedock.GetInstance().TrackMilestoneAchievedEvent("name");
Gamedock.GetInstance().TrackLevelStartEvent("levelName", "difficulty", false, "creatorId");
Gamedock.GetInstance().TrackLevelCompleteEvent("levelName", "difficulty", 1, 1, null, 1, 1, false, "creatorId");
Gamedock.GetInstance().TrackLevelFailedEvent("levelName", "difficulty", 1, "0", 1, 1, 1, "reason", false, "creatorId");
Gamedock.GetInstance().TrackLevelUpEvent("level", "objectId", "skillId");
Gamedock.GetInstance().TrackEquipEvent("equippedItem", "equippedTo", "unequippedFrom");
Gamedock.GetInstance().TrackUpgradeEvent("upgradeId", "level", "reason", 1);
Gamedock.GetInstance().TrackLevelCreateEvent("levelId", "creatorId");
Gamedock.GetInstance().TrackLevelDownloadedEvent("levelId", "creatorId", 1);
Gamedock.GetInstance().TrackLevelRateEvent("levelId", "creatorId", 1);
Gamedock.GetInstance().TrackEndlessModeStartEvent("levelName");
Gamedock.GetInstance().TrackEndlessModeEndEvent(1);
Gamedock.GetInstance().TrackPlayerDiesEvent("levelName");
Gamedock.GetInstance().TrackWalletInventoryEvent("reason", "location", new Vector.<TrackingCurrency>(), new Vector.<TrackingItem>(), "reasonDetails", "transactionId");
Gamedock.GetInstance().TrackIAPPurchasedEvent("skuId", "transactionId", "token");
Gamedock.GetInstance().TrackIAPRestoredEvent("skuId", "originalTransactionId", "originalPurchaseDate");
Gamedock.GetInstance().TrackIAPFailedEvent("error", "skuId");
Gamedock.GetInstance().TrackTutorialCompleteEvent();
Gamedock.GetInstance().TrackTutorialSkippedEvent();
Gamedock.GetInstance().TrackRegisterEvent("platform");
Gamedock.GetInstance().TrackShareEvent("platform");
Gamedock.GetInstance().TrackInviteEvent("platform");
Gamedock.GetInstance().TrackLevelAppeared("level", "difficulty");
Gamedock.GetInstance().TrackLevelDiscarded("level", "difficulty");
Gamedock.GetInstance().TrackErrorShown("reason");
Gamedock.GetInstance().TrackTimeElapLoad(1, "pointInGame", "startPoint");
Gamedock.GetInstance().TrackTimeoutDetected(1, "pointInGame");
Gamedock.GetInstance().TrackObjectStateChanged("changedObject", "status", "reason", "changedProperties");
~~~

Ask your Azerion representative if any events should be implemented. Call the corresponding function at the required point in your game, and the SDK will send the event to the Gamedock back-end. It is important that the events and parameters for your game are white-listed via the Gamedock Console, or they will not be forwarded to BI for reporting purposes. Besides reporting purposes, events can also be configured via Gamedock console to function as triggers, to show splash screens or ads at the desired moment in-game.

#### ** Cordova **

In order to track an event, use the following code:

~~~JavaScript
//Using predefined tracking methods examples (recommended way unless the event you are tracking is not in the list)
gamedockSDK.tracking.LevelComplete("Level1").addX().track();
gamedockSDK.tracking.MilestoneAchieved("First Cordova App").addX().track();

//Direct way
 gamedockSDK.trackEvent(eventName, {key: value});
 
 //Examples
 gamedockSDK.trackEvent('levelComplete', {'level': 'Level 1'});
 gamedockSDK.trackEvent('milestoneAchieved', {'name': 'First Cordova App'});
~~~

<!-- tabs:end -->
