# Change Log

### Version 3.6.0 *(29-09-2019)*

**IMPORTANT!**


**New Features**


**Bug fixes**


**Other**




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



