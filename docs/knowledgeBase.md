# Knowledge Base

> This page contains an overview of potential issues that you might encounter while building or running your game with the Gamedock SDK based on the engine that you use.

<!-- tabs:start -->

#### ** Unity **

* *Issue*: **After importing the Gamedock SDK, errors show up in Unity with duplicate class names/definitions.**

  *Answer*: This issue can occur if you game code project doesn't use namespace for it's classes. There are two ways to fix this: either modify your existing class definitions to use namespaces (recommended way as this can avoid issues with updates of the SDK as well as other SDK which might use similar terminology) or modify the classes/code in the SDK supplied code (this will have to be redone again with a new update).


* *Issue*: **When running the game in the Editor with Gamedock installed, I get a lot of "NullReferenceException" errors when showing the dummy ads, age gate or privacy policy views.**

  *Answer*: The issue can appear if you are using an older Unity version (2018.x) due to the fact that prefab structure was changed with 2019.x and Gamedock uses that version when exporting the SDK. In order to solve this issue please download the following folder and replace it in “Assets/Gamedock/Editor/“ : [Prefab missing script fix](https://splashscreens.cdn.spilcloud.com/files/1574351079_Prefabs.zip).


* *Issue*: **After I exported the game to build for iOS (using Xcode) I am getting messages similar to these ones: "duplicate symbol '_FBLPromiseRetryDefaultAttemptsCount'" or "duplicate symbol" related to Facebook (FBSDKCoreKit).**

  *Answer*: This can occur if you use your own implementation of Firebase instead of the one provided by the SDK or you implement the Facebook SDK. Some of the common dependency can be disabled via the Configuration/iOS menu for the Gamedock SDK. If the duplicated symbol relates to a framework not mentioned in the Configuration menu, you can remove importing of libraries in the "GamedockIOSBuildPostProcess" script located in "Gamedock/Editor/PostBuild".


* *Issue*: **After I implemented the advertisement solution from Gamedock, I always get AdNotAvailable when requesting banners/interstitials/rewarded videos.**

  *Answer*: There are several common mistakes that might be causing this issue. The first is that as of 3.9.x or above, it is required that you do any ad related requests/operations only after the callback OnAdsInitialized has been fired (you need to listen to this callback). Another mistake might be that the advertisement (AdMob) module has not been enabled in the Gamedock SDK->Configuration->Android/iOS window. The last could be that the advertisement configuration was not yet added for your game in the Gamedock Console. In this case contact your Game Producer/Gamedock Representative.


* *Issue*: **When starting the game first time with Gamedock, the Age Gate/Privacy Policy(GDPR) windows show up, but there is no text in the windows.**

  *Answer*: In general missing text in the Age Gate or Privacy Policy(GDPR) windows is related to either missing the "defaultGameConfig.json" in the build or not having setup properly the SDK Config in the Gamedock Console (and not retrieving it through the Gamedock SDK->Configurations->Create Default Configuration Files functionality). If you are using OBB files for Android, please make sure to read this documentation section: [https://azerion.github.io/gamedock-sdk/#/platformSpecificComponents?id=building-and-publishing](https://azerion.github.io/gamedock-sdk/#/platformSpecificComponents?id=building-and-publishing)


* *Issue*: **When trying to build for Android I get a lot of duplicate library (aar files) errors and the build fails.**

  *Answer*: The reason why you would get duplicate library (aar files) erros could be that you have both these libraries imported as files in the "Assets/Plugins/Android" folder as well as imported through the "mainTemplate.gradle" file. The first thing you can do to spot duplicates is to use the "Verify Android Setup" option from Gamedock. This can be found in the Gamedock SDK->Configuration->Android->Verify Android Setup. If no errors appear in the Editor Console, investigate manually the "Assets/Plugins/Android" folder an make sure you have as little ".aar" files as possible and instead import those dependencies through the "mainTemplate.gradle" file. If you are using the Play Resolver also make sure to disable automatic importing of ".aar" files when resolving dependencies.

#### ** AIR **

* *Issue*: **After I implemented the advertisement solution from Gamedock, I always get AdNotAvailable when requesting banners/interstitials/rewarded videos.**

  *Answer*: There are several common mistakes that might be causing this issue. The first is that as of 3.9.x or above, it is required that you do any ad related requests/operations only after the callback OnAdsInitialized has been fired (you need to listen to this callback). Another mistake could be that the advertisement configuration was not yet added for your game in the Gamedock Console. In this case contact your Game Producer/Gamedock Representative.

#### ** Cordova **

* *Issue*: **After I implemented the advertisement solution from Gamedock, I always get AdNotAvailable when requesting banners/interstitials/rewarded videos.**

  *Answer*: There are several common mistakes that might be causing this issue. The first is that as of 3.9.x or above, it is required that you do any ad related requests/operations only after the callback OnAdsInitialized has been fired (you need to listen to this callback). Another mistake could be that the advertisement configuration was not yet added for your game in the Gamedock Console. In this case contact your Game Producer/Gamedock Representative.

* *Issue*: **When starting the game first time with Gamedock, the Age Gate/Privacy Policy(GDPR) windows show up, but there is no text in the windows.**

  *Answer*: In general missing text in the Age Gate or Privacy Policy(GDPR) windows is related to either missing the "defaultGameConfig.json" in the build or not having setup properly the SDK Config in the Gamedock Console.

<!-- tabs:end -->