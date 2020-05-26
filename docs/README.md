# Change Log

###  Version 3.9.0 *(26-05-2020)*

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

###  Version 3.8.1 *(25-02-2020)*

**Bug fixes**
 * Android: Fixed crash when the SDK thread is not created properly.
 * Android: Fixed crash where in certain cases the install store name could not be retrieved.
 * Android: Fixed ANR issue with the InitializationCompleted callback for Unity.
 * Android: Fixed few other ANR related issues.
 * iOS: Fixed issue when showing/hiding banner ads.
 * Unity: Updated Android post-build script to support Unity 2019.3.+ .
 * Unity: Updated iOS post-build script to support Unity 2019.3.+ .


###  Version 3.8.0 *(04-02-2020)*

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


### Version 3.7.0 *(20-11-2019)*

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
 * Unity: Reduced size of the example assets for Privacy Policy and Age Gate.
 * Unity: Moved the JSONObject class to the Gamedock namespace.
 * Unity: Removed the Android Project Id value as that is not used anymore.
 * Android/iOS: Updated AdMob mediation networks.
 * Android/iOS: Added CCPA AdMob compliancy.


### Version 3.6.1 *(24-10-2019)*

**Bug fixes**
 * Android: Fixed issue with reward video initialization causing ANRs.
 * Android: Removed pre-caching of reward videos.
 * iOS: Fixed issue with native Age Gate and GDPR popups not displaying properly on iOS 13 and Night Mode.
 * iOS: Fixed issue with Age Gate not returning the correct age group in the callback.
 * Unity: Fixed several issues when requesting default configuration files

**Other**
 * Android: Updated Unity Ads SDK to 3.3.0.


### Version 3.6.0 *(08-10-2019)*

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


### Version 3.5.0 *(29-07-2019)*

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
 
 
### Version 3.4.0 *(08-05-2019)*

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


### Version 3.3.0 *(14-02-2019)*

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



