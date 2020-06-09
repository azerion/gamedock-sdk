Change Log
==========

Version 3.9.1 *(04-06-2020)*
----------------------------
**Bug fixes**
 * Android: Fixed issue with custom set package names.
 * iOS: Updated all ad networks to have the UIWebView references warning be removed when uploading builds with Gamedock to the Apple Store

**Other**
 * Android/iOS: Updated AdMob mediation adapters and networks in order to fix crashes and have the improvements from those updates


Version 3.9.0 *(26-05-2020)*
----------------------------
**New Features**
 * _Advertisement Initialization_: The SDK now reports back to the game when the advertisement module has been initialized. **Make sure to start using the ads methods after the "OnAdsInitialized" callback has been fired otherwise ads will not work properly! Check the documentation page for Advertisement for more information.** Additionally, the SDK now reports tracks internally the time it took to initialize each ad mediation partner.
 * _Multi-operation Wallet and Inventory Transactions_: It is now possible to perform multiple operations on the Wallet and Inventory, before committing and sending to the backend the information. All the operation will be grouped into one event thus allowing for easier tracking. The following operations are supported: *AddCurrency, SubtractCurrency, AddItem, SubtractItem, OpenGacha, AddUniqueItem, RemoveUniqueItem, UpdateUniqueItem*. For more information on how to use this, check the following page: [https://azerion.github.io/gamedock-sdk/#/shopWalletInventoryControl](https://azerion.github.io/gamedock-sdk/#/shopWalletInventoryControl).
 * _App Rate Screen_: This feature allows the displaying of a popup in which the user is asked to rate the game. If the user gives a rating lower than 4, the user is redirected to a provided feedback url. For more information, check the documentation here: [https://azerion.github.io/gamedock-sdk/#/appRate](https://azerion.github.io/gamedock-sdk/#/appRate).

**Bug fixes**
 * Android: Fixed crash related to IAP initialization.
 * Android: Fixed issue with AppsFlyer not tracking properly.
 * iOS: Fixed ad tracking for banner ads.
 * iOS: Renamed HookBridge method "cStringCopy" to "gdStringCopy" to avoid conflicts with other libraries.
 * Android/iOS: Excluded SDK reserved events from being tracked by Firebase.
 * Unity: Fixed issues with iOS post-build script.
 * Unity: Fixed issue with Editor inventory subtraction delta.
 * Unity: Fixed minor issue with Features Initialization when using social login in the editor.

**Other**
 * Android: Removed the Gamedock Firebase module. In order to use Firebase and the features supported by Gamedock make sure to include the dependencies mentioned at the bottom of this page: [https://azerion.github.io/gamedock-sdk/#/addingTheGamedockSDK](https://azerion.github.io/gamedock-sdk/#/addingTheGamedockSDK).
 * Android/iOS: Refactored AdMob implementation to use the new provided API which should improve loading times of ads. This ties in with the Advertisement Initialization feature. **Because of the new api, it is not possible anymore to track clicks on any rewarded video ads from AdMob or it's partners (the "rewardedVideoDidClick" event).**
 * Android/iOS/Unity: Refactored the way certain callbacks communicate between Unity and the native layer. The forward facing api will not change, but it does mean fewer native calls made from Unity towards the native layer (since the data is available in the initial callback). This can show slight improvements in performance and data reliability.
 * Android/iOS/Unity: Added minor feature to check which version id is received for specific configuration. Currently only Game Config is supported but more will be added later.
 * Android/iOS/Unity/Cordova: Added additional security to the SDK.
 * Android/iOS/Unity/Cordova: Added IAP subscription validation. If a subscription is valid it will be returned from the backend in the same callback as regular subscriptions. Make sure to mark the IAP purchase event that it is a subscription for this to work.
 * Unity: Changed default iOS module inclusion. The additional Gamedock iOS SDK modules are now disabled by default.
 * Unity: Added several helper methods for *PlayerDataHelper* and *GameDataHelper*.
 * Unity: All helpers (PlayerData, GameData, etc.) have been moved under *Gamedock.Instance*.
 * Android/iOS/Unity/Cordova: Added AdStart callback for when a banner is shown as well as notify which type of ad is shown through the AdStart callback
 * Android/iOS/Unity/Cordova: Updated Firebase and AppsFlyer libraries to the latest versions.
 * Android/iOS/Unity/Cordova: Updated Ad libraries to the latest versions.
 * Android/iOS/Unity/Cordova: Added minor additional tracking properties for advertisement requested events.


Version 3.8.1 *(25-02-2020)*
---------------------------
**Bug fixes**
 * Android: Fixed crash when the SDK thread is not created properly.
 * Android: Fixed crash where in certain cases the install store name could not be retrieved.
 * Android: Fixed ANR issue with the InitializationCompleted callback for Unity.
 * Android: Fixed few other ANR related issues.
 * iOS: Fixed issue when showing/hiding banner ads.
 * Unity: Updated Android post-build script to support Unity 2019.3.+ .
 * Unity: Updated iOS post-build script to support Unity 2019.3.+ .


Version 3.8.0 *(04-02-2020)*
----------------------------
**New Features**
 * _Priority Ads_: The SDK now allows the configuration of Priority Ads thorough the Gamedock Console. This feature allows adding ad placements (banners, interstitial and rewarded videos) as priority using different ad providers than the default stack. For example, Ad Manager ad unit ids can be shown X amount of times before the SDK then falls back to the default AdMob mediation stack. On the SDK side, no additional implementation is required as all configuration is done through the Console.
 * _Toggleable Features_: Most of the SDK features can now be turn on or off individually, thus potentially reducing the number of events fired automatically by the SDK. The SDK will report in it's logs if a feature is not enabled. Enabling/Disabling features is done through the Gamedock Console. In the Unity Editor, you can see the features overview in the Configuration->General tab.

**Bug fixes**
 * Android: Fixed issue with Unity Ads not displaying ads properly.
 * Android: Fixed several issues related to ad request/displaying.
 * Android: Fixed crash when displaying Splahscreens through WebViews.
 * Android: Fixed crash related to SDK threading.
 * Android: Fixed issue with displaying Unity Ads ads.
 * iOS: Fixed issue related to MissionData handling.
 * iOS: Fixed issue with Age Gate callback not forwarding the correct response for native implementations.
 * Cordova: Fixed initialization issue with IAP tracking.
 * Unity: Improved logging.
 * Unity: Fixed several warning messages.

**Other**
 * Android/iOS/Unity/Cordova: Direct interstitial requests will now take into account interstitial timers set in the Gamedock Console.
 * Android/iOS/Unity/Cordova: Added extra tracking for all advertisement placements (banners, interstitials, rewarded videos).
 * Android/iOS/Unity/Cordova: Added extra InitializationCompleted callback from the SDK when the initial initialization is completed (you should still listen to the various callbacks for each feature for more accurate functionality).
 * Android/iOS/Unity/Cordova: Updated Firebase libraries to the latest versions.
 * Android/iOS/Unity/Cordova: Updated Ad libraries to the latest versions.


Version 3.7.0 *(20-11-2019)*
----------------------------

**IMPORTANT! If you are experiencing issues with missing scripts on some of our Editor prefabs, it is caused by Unity not importing properly some of it's components. In order to fix it please download [this](https://splashscreens.cdn.spilcloud.com/files/1574351079_Prefabs.zip) package and overwrite the folder "Assets/Gamedock/Editor/Prefabs".** 

**New Features**
 * _Fyber Mediation and Awesome Ads_: Two new mediation networks have been added to the AdMob stack.
 * _Chartboost Refactoring_: The Chartboost module has been removed and Chartboost has been moved as a mediation inside AdMob.

**Bug fixes**
 * Unity: Fixed issue with FPS tracking creating an infinite value list.
 * Unity: Fixed issue with SDK Windows throwing exceptions when appearing in the editor.

**Other**
 * Android/iOS: Added new initialization flow (builder) for native initialization which can be used for native implementations of the SDK or for new engine plugins.
 * Android/iOS/Unity: Added new method to directly request an interstitial. The flow matches the requesting of rewarded videos.
 * Android/iOS/Unity: Added new method to directly check if an ad is available (banner, interstitial, rewarded video).
 * Android/iOS/Unity: Added new method to retrieve the Firebase Instance Id. 
 * Android/iOS: Added additional mediation information to be sent with the SDK event when an interstitial is displayed (similar to rewarded videos).
 * Android/iOS/Unity: Added two new methods for passing GDPR (Privacy Policy) information and retrieving it.
 * Android/iOS: Added server side callback logic for Rewarded Videos. The SDK now sends additional information with the rewarded video requests (SDK User Id, Package Name/Bundle Id, OS, and a list of external user ids that have been passed to the SDK (ex.: the game id).
 * Unity: Reduced size of the example assets for Privacy Policy and Age Gate.
 * Unity: Moved the JSONObject class to the Gamedock namespace.
 * Unity: Removed the Android Project Id value as that is not used anymore.
 * Android/iOS: Updated AdMob mediation networks.
 * Android/iOS: Added CCPA AdMob compliancy.
 

Version 3.6.1 *(24-10-2019)*
----------------------------

**Bug fixes**
 * Android: Fixed issue with reward video initialization causing ANRs.
 * Android: Removed pre-caching of reward videos.
 * iOS: Fixed issue with native Age Gate and GDPR popups not displaying properly on iOS 13 and Night Mode.
 * iOS: Fixed issue with Age Gate not returning the correct age group in the callback.
 * Unity: Fixed several issues when requesting default configuration files

**Other**
 * Android: Updated Unity Ads SDK to 3.3.0.


Version 3.6.0 *(08-10-2019)*
----------------------------
**IMPORTANT! The SDK has been migrated from Spil to the new Gamedock brand. This means that all API calls and references have been changed to Gamedock. Make sure to update all your references in order to get the SDK working again.**

**New Features**
 * _Migration to Gamedock_: The SDK has been rebranded to Gamedock meaning that all Spil/Spilgames references have been removed (as much as possible). Make sure to update your API calls/Gameobjects/Prefabs accordingly.
 * _AppsFlyer Module_: The AppsFlyer SDK has been added as a module. The module can be enabled/disabled in the Configuration screen under each platform.
 * _External Partner Ids_: The SDK now accepts the passing of external partner ids, either when initializing or at a later stage, in order to better connect tracking between the different SDK that you might be using (AppsFlyer, Steam, Facebook, etc.).

**Bug fixes**
 * Android: Fixed several ad related crashes and ANR issues.
 * Android: Fixed isolated cases where the SDK will fail to initialize properly.
 * Android: Fixed issue with GCM key retrieval causing ANRs; it has been replaced with FCM and now requires the Firebase module.
 * iOS: Fixed crash that could happen if certain Ad networks were enabled.
 * iOS: Fixed crash for WebView javascript data injection on iOS 13.
 * Unity: Fixed build errors caused by switching to WebGL/Standalone.
 * Unity: Fixed gradle script to include symbol uploading to Crashlytics.

**Other**
 * Android/iOS: Updated all Ad networks.
 * Android/iOS: Added myTarget mediation network.
 * Unity (experimental): Added Standalone support for SDK tracking and features (at the moment the following features are not supported: Splashscreens, Daily Bonus, Tiered Events, Ads).
 * Unity (experimental): Fixed WebGL support for the SDK tracking and features (at the moment the following features are not supported: Splashscreens, Daily Bonus, Tiered Events, Ads).
 * Unity: Added toggle to easily override the AppController for iOS.
 * Unity: Exposed the Android Crashlytics/Fabric api key to the manifest. If you are using a different Fabric account then the old Spilgames one, make sure to update this key.


Version 3.5.0 *(29-07-2019)*
----------------------------
**IMPORTANT! The SDK callbacks have been moved to their specific classes (ex.: Spil.Instance.OnAdAvailable -> Spil.Instance.AdvertisementCallbacks.OnAdAvailable).**

Version 3.5.0 includes COPPA compliance logic, Age Gate functionality, Headerlift implementation and bug fixes.

**New Features**
 * _COPPA compliance_: This feature enable the possibility to toggle on/off COPPA compliance logic in the SDK. This can be done by passing the extra flag when initialising the SDK.
 * _Age Gate_: This feature allows the enabling of an extra Age Gate screen before the GDPR (Privacy Policy) pop-up. Users are prompted with 3 options to select the age range they are in, and based on the selection and the settings passed when requesting the Age Gate, the SDK will initialise accordingly. The Age Gate must be requested before the GDPR (Privacy Policy) (more information in the documentation).
 * _Headerlift_: A new mediator was added based on the Heardlift SDK (which internally uses Ad Manager). This mediator works the same way as the existing AdMob and Chartboost mediators and it is part of the AdMob module.

**Bug fixes**
 * Android: Fixed issue with AdColony rewarded videos not triggering the "AdFinished" callback correctly if the user watched the video completely.
 * Android: Fixed potential crashes when gathering stats on certain devices where the information was not present.
 * Android: Fixed ANR issue where event tracking could cause deadlocking on certain occasions.
 * Android: Fixed ANR issue when registering GCM id.
 * Android: Fixed issue with Network traffic statistic not being calculated correctly.
 * Android: Fixed several ad related crashes that could occur for banners and interstitials; also improved UI thread safety when checking/showing ads.
 * iOS: Fixed memory spike issue for Game Data and Player Data loading.
 * iOS: Fixed issue with Game State crashing in certain scenarios.

**Other**
 * Android/iOS: Updated 3rd party ad libraries.
 * Android/iOS: Added Tapjoy and Ironsource Mediation networks (will work with both AdMob and Headerlift).
 * Android/iOS: Added extra cancel button next to the Ads loader in cases where the ad could not be displayed properly (the button appears after 5 seconds from when the ad viewing was triggered)
 * Android/iOS: Added extra tracking for "rewardedVideoDidDisplay" and "rewardedVideoDidNotDisplay" events to also send the mediation adapter that is being used when displaying the ad (or not).
 * Android/iOS: Added extra tracking for the interstitial events to also send the condition id of the condition that triggered the interstitial displaying.
 * Android: Added Firebase Crashlytics NDK support.
 * Android/iOS: Added support for FPS tracking (this information will be sent alongside the other stats in the "heartbeat" event).
 * iOS: Added toggle to remove NanoPB in order to prevent duplicates with other libraries also using it.
 * iOS: Removed the old python script and replaced it with the C# script. 
 * Unity: Several improvements for the Unity plugin.
 
 
Version 3.4.0 *(08-05-2019)*
----------------------------
**IMPORTANT! If you are using a separate implementation of Fabric Crashalytics remove it as the Spil Firebase module now contains the Firebase Crashlytics library.**

Version 3.4.0 includes the Mission feature, duplicate Gacha reward checking, Firebase Crashlytics and device performance tracking.

**New Features**
 * _Mission_: This feature allows for the configuration of containers and mission (through SLOT) as well as tracking the user's progress for containers and missions. It is integrated with the User Data/Sync system so no additional synchronization is need. Get more information about how this feature works on the official website documentation.
 * _Duplicate Gacha Reward Checking_: This feature represents an enhancement to the Gacha system, where now you can configure that a Gacha reward should be unique and no duplicates should be given. Through SLOT you can also configure that if no rewards are possible, a default reward is given by the SDK.
 * _Firebase Crashlytics_: This feature is a migration of the Fabric Crahslytics feature into Firebase as soon Fabric will be discontinued. If your game already has the Firebase SDK module integrated, no additional actions are required.
 * _Device Performance Tracking_: An automatic performance tracking system has been added to the SDK that pulls information at a set interval and sends that information with each heartbeat event. The information that the SDK is gathering refers to Memory, CPU and Network Traffic (sent and received).

**Bug fixes**
 * Android: Fixed issue with the GDPR partner layout not working on certain android sdk versions.
 * Android/iOS/Editor: Fixed issue with Gachas not applying correctly the Perks.
 * Android: Fixed an issue with Firebase Event tracking.
 * iOS: Fixed a bug where the banner did not appear when the HideBanner() method was called just before the ShowBanner() was called.

**Other**
 * Android/iOS: Updated 3rd party libraries (Firebase, Advertisement).
 * Android/iOS: Added additional tracking for the ad request/show flow in order to better understand fill/show/click behaviour.
 * Android/iOS/Editor: Added a 1 second delay warning if the game tries to update Mission/Container progress and Game State too often. The update will still go through but this is intended to give a better overview for the game developer on how to optimise certain update operations.


Version 3.3.0 *(14-02-2019)*
----------------------------
Version 3.3.0 includes Game Update flow (forced/recommended), Help Center extra tag parameters, Splashscreen caching, GDPR improvements, GZIP compression and Firebase Deep Link Attribution.

**New Features**
 * _Game Update Flow_: This feature gives the possibility to notify the user if he needs to update his game. There are two modes for this: Forces and Recommended. The feature can be toggled from SLOT on the Game Versions page.
 * _GZIP Compression_: This feature allows the enabling and disabling of GZIP compression based on the size of an event that will be sent to the backend. The setting as well as the threshold can be configured inside the SDK configuration that can be found on the Sdk Config page in SLOT. Consult a Spil Representative for additional support.
 * _Firebase Deep Link Attribution_: This feature allows for attribution tracking using Firebase Deep Links. The links can be attached to any cross-promotion campaign and will track the attribution once the target app has been installed and that app has the Spil SDK 3.3.0 or higher.
 
**Bug fixes**
 * Android: Fixed issue with encryption decrypting on lower end devices.
 * Android: Potentially fixed issue with Privacy Policy Popup scaling on portrait for some devices using the native pop-up.
 * iOS: Added missing 'gachaId' and 'bundleId' parameters in the UpdatePlayerData event towards Unity.
 * iOS: Changed reward video closed 'reason' parameter from 'dismiss' to 'close' for the native adFinished delegate method.
 
**Other**
 * Android/iOS: Updated all 3rd party libraries (Firebase, Advertisement, Adjust). **Important! For Android make sure to click on the "Create Default Configuration Files" (Spil SDK->Configuration->General) in order to add the correct AdMob app id. Failing to do so will result in a hard crash at the start of the game.**
 * Android/iOS: Added optional tag parameters that can be passed when opening a Help Center Webview.
 * Android/iOS/Editor: Added extra settings parameter when requesting a banner ad. The request now supports two locations, TOP and BOTTOM, (if nothing is passed it defaults to BOTTOM), and multiple ad sizes. These settings need to be passed at request time and not at showing.
 * Android/iOS: Added retry logic functionality for Advertisement initialization in cases when the app starts offline and connects to the internet during play.
 * Android/iOS/Editor: Added Splashscreen caching based on the settings defined in SLOT. A Splashscreen now can either be shown immediately (old functionality) or be kept in memory and shown at a later stage. The SDK only keeps one Splashscreen in memory and if another caching Splashscreen is received before the old one is shown, a priority is taken into account that can be configured also in SLOT (for each individual Splashscreen).
 * Android/iOS/Editor: Added GDPR partners list displayed in the Settings screen of the GDPR popup. **Important! If you are using the Prefab option for the GDPR pop-up make sure to update it accordingly.**
 * iOS: Made the framework modular into 4 configurable modules: Admob/Adjust/Chartboost/Firebase.
 * Android/iOS/Editor: Support for Unity 2018.3.x added.
 * Android/iOS/Editor: Improved Unity Spil Logging performance.
 * Android: Improved performance for communication from Unity to the native layer.
 * Android/Editor: Added configuration for custom package name.
 * Android/iOS/Editor: Added extra optional parameter "isSubscription" for IAPPurchased events. The parameter is used if an IAP is a Subscription.
 
**Deprecated**
 * iOS: Simulator and iOS 8 support dropped. 

Version 3.2.1 *(27-11-2018)*
----------------------------
Version 3.2.1 includes only hot fixes.

**Bug fixes**
 * Android/Editor: Fixed issue with delta value not being sent correctly to the PlayerDataUpdated callback.
 * iOS: Fixed issue with not showing the Settings screen for the Privacy Policy pop-up.

Version 3.2.0 *(12-11-2018)*
----------------------------
Version 3.2.0 includes Gacha, Bundle, Shop and Packages properties definitions, Unique Items, Perk Item support for Wallet/Inventory operations, User Id Change Request (for non social logged in users), general improvements and bug fixes.

**New Features**
 * _Unique Items_: This feature allows non-stackable items to be added to the inventory. Several methods have been added to the SDK to allow these operations. Unique items can be enabled to through slot, the have their own unique properties and unique ids. The feature works with the existing sync functionality of the Inventory.
 * _Entity Properties_: Properties definitions have been added to the following features: Gacha, Bundle, Shop Tabs/Entry and IAP Packages. Properties can be configures in SLOT.
 * _Perk Item support_: Perk Items can now be passed when doing Wallet/Inventory/Gacha operations. Perk Items can influence the following: price, amount of rewards given from a bundle purchase or the weight of gacha contents.
 * _User Id Change Request_: This feature allows control from SLOT to switch non social logged in user ids to be switched. The operation can be done from SLOT and tells the SDK to switch to the designated new user id and reset the data.
 * _WebGL Support_: This feature allows games that implement the Spil SDK to be deployed for WebGL and Facebook Gameroom games.
 * _Banners_: This feature allows games to display a bottom banner ad. The banner ad can be toggled on or off depending on the situation.
 * _Firebase Remote Config_: Added support for Firebase Remote Config. Check the documentation for the available methods and callbacks.

**Bug fixes**
 * Android: Fixed issue with PrivacyPolicy prefab not loading on games that use OBB split. Now, if you want to use the prefab you need to reference it in the SpilSDK object in the scene. The prefab can be found at Resources/Spilgames/PrivacyPolicy
 * iOS: Fixed issue with iOS 12 duplicate "notificationOpened" event.
 * iOS: Fixed an issue where the deeplink claim error callback was not fired when a deeplink reward failed to claim.
 * iOS: Minor fixes for deeplink edge case handling.
 * iOS: Aligned the UpdatePlayerData callback parameters with Android to add missing parameters.
 * Editor: Fixed missing gacha information in the PlayerDataUpdated callback when opening the gacha.

**Other**
 * Android/iOS/Editor: Added extra 'hasSplashscreen' value for Promotions
 * Android/iOS: Updated 3rd party libraries
 * Android/iOS/Editor: Added bundleId and gachaId values to PlayerDataUpdatedData callback. These are filled in based on the operations the game does (BuyBundle/OpenBundle & OpenGacha).
 * Android/iOS/Editor: Added possibility to social login with Google Play Games (Android) or Game Center (iOS) services. You would need to pass one of the values found in the SocialManager class.
 * Editor: Added easier configuration options for enabling/disabling Android modules. Also added two modes for using the Android Spil SDK: AAR (old system) and direct Gradle import.
 * Android/iOS: Adjust signature feature logic implemented.
 * Android/iOS: Added Applovin and InMobi as AdMob mediation networks.
 * Editor: Improved the Configuration window. Added possibility to switch between full Gradle build of the SDK and using the AAR file system. Make sure you remove the old file and configure the Android Spil SDK through the Configuration->Android window.

Version 3.1.0 *(02-08-2018)*
----------------------------
Version 3.1.0 includes Item properties definitions, Amazon support, limits for Currencies and Items, general improvements and bug fixes.

**New Features**
 * _Item Properties_: This feature allows to have specific properties for items in the form of an extra JSON parameter. The properties can be configured in the SLOT interface and retrieved from the Game Data Items. The parameters are free form to be configured.
 * _Amazon Support_: This feature allows games that implement the Spil SDK to be deployed on the Amazon store. The local price, currencies and amazon user id need to be passed manually for the SDK when tracking IAPs. When registering a device, specify that the store is "Amazon".
 * _Currency & Item Limits_: This feature allows for developers to set limits on how many items/currency values can the user have. If any operations go over the set limit, an overflow value will be communicated.

**Bug fixes**
 * Android: Fixed issue with Deep Link processing only happening on application restart. It should now be processed on application resume as well.
 * Android: Fixed crash when requesting reward videos.
 * Android: Fixed crash for Android 4.x devices.
 * Android: Fixed issue when opening a bundle (not buying) where contents would not be given.
 * iOS: Fixed Russian scaling issue GDPR pop-up
 
**Other**
 * Android: Added support for more types of notifications received from SLOT (large text, background image)
 * Android/iOS: Added MoPub SDK 5.1.0 for Advertisement mediation (only interstitials)
 * Android/iOS: Added Deep Link functionality to pass JSON and Splash Screen trigger values
 * Android/iOS/Editor: Reworked functionality for Daily Bonus. It now works in a 2-step process: Request Daily Bonus (fires an Available callback) and Open Daily Bonus.
 * Android/iOS/Editor: Added extra reporting parameter for Items. This can be configured in SLOT in order to provide more flexibility for reporting events involving Items.
 * Android/iOS: Enabled Firebase Analytics tracking. If a game has implemented the Spil SDK Firebase framework, events that would normally be tracked towards SLOT will also be tracked for Firebase.
 * Android/iOS/Editor: Added method to request game config manually.
 * Editor: Event tracking file is now automatically downloaded when retrieving the default JSON files.
 * Android/iOS: Updated 3rd party libraries

Version 3.0.0 *(13-06-2018)*
----------------------------
**IMPORTANT! The Event Tracking methods have been deprecated and a new API has been introduced. The old methods will be removed in a near future version. Please update your tracking as soon as possible. The new tracking API: SpilTracking.{EventName}({RequiredParametersValues}).Add{OptionalParameters}({OptionalParametersValues}).Track();**

**IMPORTANT! For Android, the Google Play Services and AppCompat AAR files have been removed and the dependencies are now resolved using the mainTemplate.gradle file. If you are using Unity 2017.+ make sure you are building with Gradle and use the provided gradle file. Make sure you delete the old AAR and JAR files from your project otherwise the build process will fail with duplicate dependencies. For older versions of Unity, the aar files are still provided in the NativeLibraries/Android folder under AppCompat and Google Play Services. If you are using the provided AAR file, Facebook SDK might not work properly due to a hard dependencies that they have on an old version of the AppCompat libraries. If you have problems with that (Facebook crashes when logging in) contact a Spil representative for further assistance.** 

**New Features**
 * _Tiered Events_: This feature provides the possibility to configure tiered events. A tiered event is a unique event(not to be confused with tracking events) which allows the user to get special rewards by spending currencies or items within the game.
 * _Asset Bundles Configurations_: This feature allows the configuration of Asset Bundles through SLOT. It can only be used if the SDK is used with Unity.
 * _Tracking API_: A new Tracking API has been introduced for better scalability of event tracking as well as possibility to have better tracking per game.

**Bug fixes**
 * iOS: Removed sync error after first login

**Other**
 * Android: Updated minimum required Appcompat version to 27
 * Android: Removed AAR and JAR files for Appcompat and Google Play Services from the Plugins/Android folder. Please make sure to remove the files when you update to 3.0.0
 * Android: Dependency for Appcompat and Google Play Services (including Games) is now done through the Gradle file
 * Android/iOS: Updated Third Party Mediation libraries
 * Android/iOS: Implemented GDPR consent forwarding for AdMob, Chartboost and mediation partners. Now reward video ads will play regardless of the choice the user makes in the GDPR popup while still keeping track of their option
 * Unity Editor: Improved the Editor Configuration screens and removed some messages that were not relevant anymore
 * Unity Editor: Added extra code comments for relevant methods (more to come)
 * Unity Editor: Added extra introduction screen detailing integration steps for the SDK. This screen will appear automatically once for each new version and can also be accessed through the Top Menu (Spil SDK) in Unity

Version 2.10.0 *(03-05-2018)*
----------------------------
**IMPORTANT! The "SendCustomEvent" method has been hidden from the normal API in Spil.Instance. Please use the predefined methods to track analytic events. If a method is not defined for your specific event please contact your Spil representative.**

Version 2.10.0 includes the migration from Fyber to AdMob advertisement mediation, improvements to the Privacy Policy popups, several improvements for communicating with WebViews and bug fixes.

**New Features**
 * _AdMob Advertisement Mediation_: The main advertisement mediation network has been changed from Fyber to AdMob. Also DFP has been removed as a separate module and included in the AdMob module. All advertisement will be served using AdMob as mediation. For Android please remove the DFP and Fyber module and only use the AdMob module.

**Bug fixes**
 * Android: Fixed issue with Daily Bonus closed callback not being fired
 * Android: Fixed issue with Promotions prices not being picked up correctly if override was not set
 * Android: Fixed issues with delta not saving properly in certain sending situations
 * Unity: Fixed issue with "privacyChanged" event being fired in cases where no setting was changed from the Settings screen for Privacy Policy
 * Unity Editor: Fixed bug with Wallet & Inventory not syncing properly if changes were made in SLOT
 * Unity Editor: Fixed bug with Privacy Policy Status callback not firing correctly in some situations
 * iOS: Fixed issue with More Apps not displaying
 * iOS: Fixed bug where a Sync Error would be thrown the first time you login into your social login and sync data

**Other**
 * Unity: Removed the possibility to use the "SendCustomEvent" to create events. All events should be tracked through predefined methods
 * Android: Updated Google Play Services to 12.0.1
 * Android/iOS: Removed double tap functionality for Privacy Policy Accept button in native and Unity prefab options
 * Android/iOS: Added functionality to receive the contents of a Gacha Box by WebViews
 * Unity: Added install event for editor mode
 * Android/iOS: Added functionality to have currencies in bundles
 * Unity Editor: Server time functionality will use the response from the server instead of the Unity local time
 * Unity: Changed the "type" parameter for the RequestSplashScreen method to be required
  

Version 2.9.1 *(29-03-2018)*
----------------------------
Version 2.9.1 includes only bug fixes.

**Bug fixes**
 * Android: Fixed bug with promotions saving information in the game data key
 * Android: Fixed issue where the Splash Screen Error callback would not be fired if no internet connection is available
 * iOS: Fixed a russian GDPR localization issue.
 * iOS: Fixed an issue where privacyChanged wasn't always send to the backend.
 * Editor: Spil.cs fixed OnValidate not finding the Spil object.


Version 2.9.0 *(23-03-2018)*
----------------------------
Version 2.9.0 includes an improved version of the PrivacyPolicy (GDPR) popup, the Promotions and Stickers features as well as some bug fixes.

**New Features**
 * _Privacy Policy Version 2 (GDPR)_: Improvements to the Privacy Policy popups as well as more screens have been added with 2 options for the user to turn off. These options are the disabling of advertisement and SDK segmentation. The new screens that have been added next to the initial popup are the Settings, Ads and Info screens. There are two flavors to this implementation. One is native (showing a native popup that can only have the header image changed) and on is using the provided Unity prefabs found in Resources/Spilgames/PrivacyPolicy. The Unity flavor comes with two prebuilt prefabs (Landscape - Operate Now & Portrait - Mahjong). These prefabs can be customized however you please as long as the elements in them remain the same. Please double check with your Spil representative before making the changes.  
 * _Promotions_: This feature give the ability to configure promotions for the Bundles and IAP packages. The promotions can be price reductions or extra items/currencies. The promotion can also have a maximum amount of purchases.
 * _Shop Stickers_: This feature gives the possibility to have multiple images attached to a Shop entry. The image urls can be found in the ImageEntries list contained in the Entry object.
 
**Bug fixes**
 * Android: Fixed crash when merging User Data
 * Android: Fixed issue where sessionStart and sessionStop were not tracked correctly in certain instances.
 * Android/iOS: Fixed issue when resetting sdk data and losing internet connection. It is now enforced that you require internet connection if you logged in and try to reset data.
 * Android: Fixed issue with debug mode crashing the application in certain conditions.
 * iOS: Aligned certain error codes to be fired in the same way as Android
 * iOS: Minor image caching improvements
 * Editor: Fixed editor prefabs (ordering and click-through)
 * Editor: Several bug fixes related to login/sync

**Other**
 * Unity: Enabled possibility to have IAP packages in the shop
 * Unity: Added optional dropoff measurement for GDPR using Unity Analytics. This feature is disabled by default and should only be enabled if confirmed by your Spil representative.
 * Android: In order to customise the Privacy Policy (GDPR) native banner, you will need to add an extra .aar file created using the provided project (NativeLibraries/Android/Resources/). The images that need to be replaced are found in the drawable folder. You should replace the "privacy_policy_landscape_custom.png" or "privacy_policy_portrait_custom.png" depending on your orientation. Also you must keep the same sizes for aspect ratio purposes.
 * iOS: In order to customise the Privacy Policy (GDPR) native banner, you need to replace the "privacyPolicyHeader.png" image found in the /Plugins/iOS/Spil.framework/
 

Version 2.8.2 *(27-02-2018)*
----------------------------
Version 2.8.2 hotfix.

**Bug Fixes**
 * iOS: Fixed a Game Center banner issue.
 
 
Version 2.8.1 *(23-02-2018)*
----------------------------
Version 2.8.1 hotfix.

**Bug Fixes**
 * iOS: Fixed an issue where some users received an ad timeout.
 

Version 2.8.0 *(15-02-2018)*
----------------------------
Version 2.8.0 includes mostly bug fixes.

**New Features**
 * _Local Price Support for Splashscreens_: This feature allows splash screens created through the SDK to display In-App Purchases with the local price and local currency.

**Bug Fixes**
 * Android/iOS: Fixed issue with wallet and inventory offsets overflowing and not picking up correctly the data from SLOT
 * iOS: Removed gamestate error events to be aligned with Android.
 * Android: Fixed issue with push notification image
 * Android: Fixed issue with permission callback not always firing
 * Android: Fixed rare crash in WebView activity
 * Android: Fixed rare crash when retrieving device id

**Other**
 * Android/iOS: The privacy policy dialog now has different visual for the accept button
 * Android/iOS: Updated all 3rd party & mediation libraries
 * Unity: Changed functionality for the Spil object to better handle singleton creation
 * Unity: Added option to choose per platform the privacy policy enabling
 * Unity: Moved the Editor prefabs outside the Resources folder and optimised the Spil logo


Version 2.7.5 *(25-01-2018)*
----------------------------
Version 2.7.5 includes only critical bug fixes.

**Bug Fixes**
 * Android: Fixed issue with privacy policy message not being picked up if game updates
 * Android: Fixed issue with privacy policy flow when switching from no popup to with popup
 * Android: Fixed issue with bundle buy track event not picking up correct order of events
 * iOS: Fixed an issue where some events are not always being triggered


Version 2.7.4 *(17-01-2018)*
----------------------------
**IMPORTANT! For Android the "SpilSDKApplicationWithFabric" has been removed. The Fabric functionality has been moved into the standard "SpilSDKApplication". Please make the necessary changes.**

Version 2.7.4 brings the Privacy Policy (GDPR) functionality, Android Push Notification images, updates to the Unity Editor and several bug fixes.

**New Features**
 * _Privacy Policy (GDPR)_: This feature is turned on by default since it is mandatory by Google that a Privacy Policy message is shown to the user when the game starts the first time. The feature is strongly connected to the initialisation phase, not allowing the user to continue if the policy was not accepted. On the development side the only thing that has changed is the addition of an extra check box in the SpilSDK object. The SDK will internally handle the Privacy Policy popup and the initialisation. No additional calls are required and an additional callback (OnPrivacyPolicyStatus) has been added for initialising any components outside the Spil SDK.
 * _Android Push Notification images_: It is now possible to attach images to a push notification. The image will be displayed when the user expands the push notification. Configuration for the image url is done in SLOT.

**Bug Fixes**
 * Android: Fixed issue with user data available callback not being called on update.
 * Android: Fixed crash when processing a response that had corrupted data.
 * Android: Fixed class cast exception crash when processing Game Data.
 * Editor: Fixed initialisation issue where the UserDataAvailable was called twice.
 * Editor: Fixed Reset Wallet/Inventory issue.
 * iOS: Removed social login failure event to align with Android
 * Android/iOS: Removed network error being thrown if the user was offline.

**Other**
 * Android: Added JSONArray parsing when sending an event with custom parameters
 * Unity Editor: Replaced the debug screens (LiveEvent, DailyBonus, Ads, etc.) with prefabs for better visuals
 * Android/iOS: Updated 3rd party libraries


Version 2.7.3 *(02-01-2018)*
----------------------------
Version 2.7.3 includes a fix for an issue on the iOS event queue which can cause a crash. It also improves playerdata/gamestate syncing on iOS.


Version 2.7.1 *(30-11-2017)*
----------------------------
**IMPORTANT! For Android make sure to update your AndroidManifest.xml file to remove the WRITE_EXTERNAL_STORAGE permission!**

Version 2.7.1 brings the Social Login & Cross-Device Syncing, removal of the WRITE_EXTERNAL_STORAGE dangerous permission, update of 3rd party libraries and several other improvements.

**New Features**
 * _Social Login & Cross-Device Sync_: These features can be combined to accomplish user data syncing across multiple devices and across multiple platforms using Facebook login. The Social Login feature can also be used without the data-syncing feature; however, this can result in a loss of data when the user starts to play on multiple devices. The User data-syncing feature cannot be used without also implementing the Social Login feature. The syncing is done on the Wallet, Inventory and Gamestate features.

**Bug Fixes**
 * iOS: Fixed an empty uid parameter for the first sessionStart event for MDS.
 * iOS: Fixed the live events start date parameter.
 * iOS: SLOT was not always updated correctly of the initial wallet/inventory state of the client.

**Other**
 * Android: Removed WRITE_EXTERNAL_STORAGE permission dependency and usage from the SDK. The user id will not be saved anymore in the Spilgames folder and it will be resetted on app install. For user who are updating the game the user id will stay the same.
 * Android: Due to the removal of the WRITE_EXTERNAL_STORAGE permission, the enabling and disabling 'debugMode' will be done explicitly through the Sample App. Please contact a Spil representative if you need to install the application.
 * Android/iOS: Added new 'deviceId' parameter which is sent with each event. This will have the same value across games from Spilgames played on the same device.
 * Android/iOS: Removed automatic triggering of request events on startup (onCreate). You will need to explicitly call the init() method now in order to tell the SDK to retrieve SLOT data.
 * Android/iOS: Changed the 'requestPlayerData' and 'requestMyGameState' to one call name 'requestUserData'. This change is due to the cross-device syncing feature.
 * Android/iOS: Merged callbacks for PlayerData and GameState into combined UserData callbacks.
 * Android/iOS: Removed Zendesk SDK and all it's components. Support for this feature has been discontinued.
 * Android/iOS: Added extra parameter to the 'requestSplashScreen' request to define the type of Splash Screen.
 * Android/iOS: All 3rd parties updated.
 * Android/iOS: Added Facebook Audience Network to Fyber.
 * Android/iOS: Removed Facebook Audience Network from DFP (the adapter is still included so if the game has the spilsdk-fyber module, Facebook interstitials will still work).
 * Android/iOS: Added AdMob Network to Fyber.
 * Android: Updated Google Play Services to 11.6.0.
 * iOS: Minor Firebase deeplink improvements.


Version 2.6.1 *(16-10-2017)*
----------------------------
Version 2.6.1 brings Spil More Apps, ability to configure an image for the permission dialogs for Android, new event tracking implementation and bug fixes.

**New Features**
 * _Spil More Apps_: This feature replaces the Chartboost more apps and allows the setting up of a more apps screen using the SLOT system. The flow of requesting and showing the Spil More Apps screen is the same as with the previous implementation.

**Bug Fixes**
 * Android: Fixed issue with inventory initialisation not picking up correctly the initial values in offline mode
 * Android: Fixed WAKE_LOCK issue by replacing the offline queueing library (old Trigger - new Android Job)
 * Android: Fixed issue with deep linking being processed twice when using Firebase
 * Android: Fixed issue with ConcurrentModification crash when sending update events to the Inventory
 * iOS: Minor deeplink improvements to handle deeplink more reliable
 * iOS: Fixed an offline gamestate syncing issue
 * iOS: Fixed an rare crash which could happen when in offline mode packages and promotion where requested

**Other**
 * iOS: iCloud is now no longer used to store the Spil User ID, keychain access is now used instead
 * iOS: It’s now possible to reset the Spil User ID through the settings menu
 * iOS: Switching between debug, production and staging environment now also cleans up all previous stored configs/states
 * iOS: Reorganised the Spil SDK settings app menu to make the functionality more clear
 * iOS: The event tracker has been optimized, it’s now using less memory and processes events faster
 * iOS: The SDK initialization code has been optimized, the SDK does now finish loading sooner
 * Android: Added possibility to configure images for permission rationale and permission deny
 * Android: Added permission response callback
 * Android/iOS: Added optional location and reward type parameters for reward videos
 * Android/iOS: Updated Fyber Ad Networks
 * Android/iOS: Updated DFP Ad Networks
 * Android: Updated Google Play Services to 11.0.4
 

Version 2.5.0 *(09-08-2017)*
----------------------------
Version 2.5.0 includes Gacha box feature, Android improved permission flow, Adjust Deep Linking, additional methods for Splash Screens and several bug fixes.

**New Features**
 * _Gacha Box_: This feature allows for the configuration of Gacha box items through the SLOT system. It gives the opportunity to configure items that can be gained through a roll system. The Gacha acts like an item so it can be added to the Inventory and bought through the Bundle system. An additional method for opening the gacha has been added.

**Bug Fixes**
 * Android: Fixed issue with initial values not being stored correctly when the game was offline
 * Android: Fixed crash when trying to initialise deep linking
 * Android: Fixed crash when a web view was not finding a certain resource
 * Android: Fixed crash when checking for external permissions
 * iOS: Aligned issue with OnGameStateError not being called if there is no internet connection
 * Editor: Fixed issue with sending event with custom data not having the correct type
 * Unity: Updated SDK to Unity 2017.1 and fixed issue with sending events in Editor

**Other**
 * Android/iOS: Added additional methods for Splash Screen which includes buying bundles and adding items and currency to the user
 * Android: Improved Permission flow by always requesting a Permission Rationale before the permission request and showing a Deny Rationale in case the user denied the permission
 * Android: Added option to localize and configure the Permission Rationale and Deny Rationale via Game Config (SLOT)
 * Android/iOS: Added "updatePlayerData" event trigger when receiving updates from SLOT for Player Data
 * Android/iOS: Added Adjust Deep Linking which uses the same flow as Firebase Deep Linking
 * Android/iOS: Added method "requestMyGameSate" to request the game states manually. Use this only in case of game state error


Version 2.4.0 *(10-07-2017)*
----------------------------
Version 2.4.0 includes the new feature Live Event, overall improvements to the native SDKs and it's features and bug fixes.

**New Features**
 * _Live Event_: A feature which allows the game to display custom events defined in SLOT, which require the user to consume one of his Inventory item in order to get rewards at the end of the event.

**Bug Fixes**
 * Android: Fixed potential issue with OOM caused by large Game State events
 * Android: Improved Web View performance for all types: Splash Screens, Daily Bonus and Live Event
 * iOS: Fixed an issue with the Fyber loader displaying incorrectly
 * iOS: Fixed issue with OnUpdateGameState not being called on the first initialization

**Other**
 * Android/iOS: Added new WebView loader added
 * Android/iOS: Added new callbacks for receiving information from a WebView and detecting if a WebView requests an IAP
 

Version 2.3.1 *(09-06-2017)*
----------------------------
**IMPORTANT! We've added an optional parameter for the "token"(purchaseToken) for "TrackIAPPurchasedEvent". It is strongly advised to use it for Android as we have had issues with retrieving this internally. For iOS it is not required.**

**Bug Fixes**
 * Android: Fixed issue with Google Advertisement Id not being retrieved/stored correctly
 * Android: Implemented option for developer to pass IAP token for the "iapPurchased" event
 * Android: Fixed issue with Firebase Deeplinking import into Unity
 * Android/iOS: Deeplinking now tracks internally the URL
 * Android: Fixed issue with OOM if the Event custom data would be too large
 * Android: Fixed issue with Initial Value being tracked more than once
 * Android: Fixed issue with Reset Updated Data crashing the game for Unity
 * iOS: Fixes for Fyber reward videos

**Other**
 * Updated Third Party Libraries

Version 2.3.0 *(16-05-2017)*
----------------------------
**IMPORTANT! Make sure that you remove the Spil Plugin files that were located in the Editor folder! These files are now directly present under the Spilgames folder!**

**New Features**
 * _Game Data Localisation_: New parameters were added to the Game Items, which include a "displayName" and "displayDescription" which gives you the possibility to localize the items, currencies and bundles inside your game from SLOT. By retrieving the information for one of the three, you will get this additional information. The information for these values is based on the user's phone localization settings.
 * _Firebase Deep Linking_: Deep Linking has been added to the Spil SDK. It uses the Google Firebase implementation at it's core, while also integrating SLOT rewards for the games.
 * _Server Time_: A method for requesting server time from SLOT has been added to th SDK. This is intended primarily as a means for preventing cheating in the game. 
 * _IAP Validation_: The Spil SDK now supports server IAP validation. The validation is done when an "iapPurchased" event is tracked and all the correct parameters have been sent to the server.
 * _Local Storage Encryption_: Encryption has been added to all the values that are stored locally on the phone by the SDK. This is done internally and no further actions are need by the developer.
 * _iOS Spil SDK updated to v2.2.0_
 * _Android Spil SDK updated to v2.3.0_

**Bug Fixes**
 * Android: Fixed issue with Unity Push Notification crashing the game in certain conditions
 * Android: Fixed IAP validation data processing issue
 * Android: Fixed issue with UpdatedData not being sent correctly to Unity
 * Android: Fixed Adjust issue that would prevent Adjust from initialising for Android version between 5 and 6
 * Android: Fixed crash caused by cast exception when the Game/SDK was resumed in certain cases
 * iOS: Fixed private gamestate sending issue
 * iOS: Fixed a wallet updating issue
 * iOS: Fixed currency type issue
 * Fixed several issues with Editor Mode

**Other**
 * Updated Third Party Libraries
 * Restructured plugin structure


Version 2.2.10 *(21-03-2017)*
----------------------------
This version brings image processing, additional parameters for updating user information, 3rd party SDK updates and bug fixes.
* iOS Spil SDK updated to v2.1.9.
* Android Spil SDK updated to v2.2.9.
* Added image processing and loading logic for items, bundles and external images (see: http://www.spilgames.com/developers/integration/unity/implementing-spil-sdk/spil-sdk-wallet-shop-inventory/ for more information).
* Added "reasonDetails" optional parameter to the methods that update the player's wallet and inventory.
* Added "transactionId" optional parameter to the methods that update the player's wallet and inventory.
* Added iOS Firebase Deep linking support.
* Added button in Unity for reporting issues with the SDK.
* Updated 3rd party libraries for iOS and Android.
* Bug fix for iOS config file being to big.
* Bug fix for iOS regarding GameState feature sending unnecessary events.
* Bug fix for Android with Adjust not initialising properly for pre Android 5 Devices.
* Bug fix for Android with Fyber not sending Ad Finished in certain conditions.
* Editor Mode bug fixes.


Version 2.2.9 *(25-01-2017)*
----------------------------
***Known Issue***
In Editor Mode, the ConfigResponse.cs has an issue. In order to get the correct Config for the game in Editor mode change the following code at line 33 in ConfigResponse.cs:
if(config.HasField("key")) to if(config.HasField(key))


This version brings a lot of wallet and inventory improvements, next to Apple TV and Editor mode improvements
* iOS Spil SDK updated to v2.1.8.
* Android Spil SDK updated to v2.2.8.
* Replaced JSONModel library because of serialization issues.
* Added initial value support for items & currencies.
* Implemented reset methods for the inventory, wallet and entire player data.
* Apple TV support improved.
* General improvements and bug fixes.
* Default Spil events added.
* Editor Mode support fixes.


Version 2.2.8 *(15-12-2016)*
----------------------------
This version brings updates to the way you are sending events via the SDK, 3rd part library updates for iOS and bug fixes for several key aspects of the SDK.
* iOS Spil SDK updated to v2.1.6.
* Android Spil SDK updated to v2.2.7.
* All 3rd party libraries updated.
* Many event tracking improvements.
* General improvements and bug fixes.
* tvOS support added.
* Fixed Chartboost ads not showing for Android.
* Push notifications fixes.
* Fixed recreating the default JSON files. Now they will always be recreated when you push the button in the Editor Window.
* Fixed Editor Mode issue regarding persistent data over multiple instance. Remember to use the same UID that you set on the SpilSDK object.
* Removed deprecated methods (such as all "SendXEvent" methods, which have been renamed to "TrackXEvent" and "ConsumeBundle" which has been renamed to "BuyBundle").


Version 2.2.7 *(30-11-2016)*
----------------------------
This version only has a few hotfixes for Android and updates for the Ad Libraries.
 * Fixed crash for IAP events.
 * Updated Ad Libraries for Android (Fyber, DFP and Chartboost).
 * Other minor bug fixes for Android.
 * Android Spil SDK updated to v2.2.6.


Version 2.2.6 *(18-10-2016)*
----------------------------
This version includes a full implementation of the Editor Mode for the Spil SDK, a permission request system for Android, several improvements in the configuration window as well as clearer issue checking.
 * Chartboost parental gate implemented in iOS.
 * Slight adjustments to the event sending for push notifications.
 * Added automatic event sending for when an ad is displayed, clicked, dismissed and closed.
 * Added permission request system for Android. The SDK now automatically request dangerous permissions at start-up (similar to how unity was doing it), but now a rationale is include for each permission. You also have the ability to disable this system and request the permissions manually when you need them during runtime.
 * A new look for the Spil SDK configuration windows have been added. You now have several tabs for each section, two new windows for documentation and release, as well as better build check-up for Android (hopefully less issues will be reported now :) ).


Version 2.2.5 *(26-10-2016)*
----------------------------
This version only has a few hotfixes for both Android and iOS.
 * Added Custom Bundle Identifier support for iOS.
 * Fixed sending format for the TrackWalletInventoryEvent.
 * iOS Spil SDK updated to v2.1.2.
 * Android Spil SDK updated to v2.2.4.


Version 2.2.4 *(20-10-2016)*
----------------------------
 * Fixed an iOS export issue.
 * + 1-5 fire damage.


Version 2.2.3 *(14-10-2016)*
----------------------------
This version brings multiple features of the Spil SDK to the Editor Mode, the Daily Bonus screen functionality as well as several bug fixes for both Android and iOS.
 * iOS Spil SDK updated to v2.1.0.
 * Android Spil SDK updated to v2.2.3.
 * Added the following Spil SDK functionalities to the Unity Editor Mode: Game State, Packages, Config, Advertisement and Event Tracking. More will follow!.
 * Several bug fixes for Android regarding the Wallet functionality.
 * Added Vungle ad network inside Fyber.
 * Updated Google Play Services to 9.6.1 (included also Google Play Games library in case you need it).
 * Bug fixes, code cleanup and improvements (for more details regarding native, check the Android and iOS repositories).


Version 2.2.2
----------------------------
Tweaks & bug fixes.
 * iOS SpilSDK updated to v2.0.8.
 * Android SpilSDK updated to v2.2.2.
 * User gamestate added.
 * Automated events implemented. (Splash screens etc).
 * iOS Build script now also supports entitlements adding. (iCloud, push messages & app groups).
 * Zendesk custom theme implemented. (iOS only)
 * Wallet track event helper methods added.


Version 2.2.1
----------------------------
Tweaks & bug fixes. minor updates and bug fixes.
 * Tweaks & bug fixes.
 * Android SpilSDK updated to v2.2.1.


Version 2.2.0
----------------------------
Version 2.2.0 is here and brings new features for analytics (Adjust, Google Analytics) and customer support (Zendesk) along with some minor updates and bugfixes.
 * iOS SpilSDK updated to v2.0.6.
 * Android SpilSDK updated to v2.2.0.
 * Methods added for custom user ids.
 * Added Zendesk library and functions for customer support.
 * Ad provider libraries have been updated.
 * Google Analytics is now integrated within the SDK.
 * Adjust is now integrated within the SDK.
 * Fixes for duplicate events on iOS.
 * Restructured the Android SDK to be modular.
 * Moved the example code out of Spil.cs and into a seperate file "ExampleCode.cs".
 * 2% improved chance of finding magic items.


Version 2.1.0
----------------------------
Version 2.1.0 is here and brings new "Shop", "Wallet" and "Inventory" features that allow developers to create an in-game shop, items and economy that can be monitored, managed and balanced from the Spil back-end. 
 * Updated to Android SpilSDK V2.1.0 and iOS SDK V2.0.3.
 * Added Wallet, Inventory and Shop features for creating and managing in-game economy.
 * Fixed and improved reward passed via push notifications.
 * Updated test app to include Wallet, Inventory and Shop features (See the TestApp directory).
 * TestRequest methods for testing advertisements are now also available for iOS.
 * Improved logging for iOS.
 * AndroidManifest.xml for google play measurements now intentionally crashes build until it is updated by user (how to notes are included).
 * Various minor bugfixes and improvements for ease of use.
 * 150% damage vs dragons


Version 2.0.2
----------------------------
Version 2.0.2 is here and brings some fixes and updates primarily for iOS. 
This version also includes a new post-processor script to make building to iOS easier.


Version 2.0.1
----------------------------
Version 2.0.1 is here and brings a lot of fixes and updates. Version 2.0.1 is primarily aimed at Android, in the coming weeks we expect to release V2.0.2 which will also include improvements for iOS.
(Android only) Since V2.0.1 Unity developers have to include a defaultGameConfig.json file in their StreamingAssets directory. This json file should contain a ChartBoost id and signature as well as a key for Google IAP (only required if the game uses in-app purchases).
A defaultGameConfig.json file could look like this:

{
"chartBoostAppId":"ValueHere",
"chartBoostAppSignature":"ValueHere",
"googleIAPKey":"ValueHere"
}
