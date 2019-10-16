# Adding the Gamedock SDK

> As the Gamedock SDK grows and expands, new SDK versions with additional features will be made available. These new versions can update or improve your game. However, previous versions will still be available for legacy games. It is recommended that you update your games to the latest SDK.

<!-- tabs:start -->

#### ** Unity **

### Download and Import the GameDock Unity package into your project

You can find the latest version of the Unity plugin here: [https://github.com/azerion/gamedock-sdk/releases](https://github.com/azerion/gamedock-sdk/releases)

Unpack the downloaded archive, inside you will find the native library folders and a Unity package. You can ignore the folder for now and just import the Unity package.

### Using the Gamedock Unity SDK

1. Attach the script named “Gamedock.cs” to a new GameObject in your startup scene, and name that GameObject "GamedockSDK".
2. Make sure to check set the Bundle identifier (iOS) and Package Name (Android) of your game in the Unity PlayerSettings.
3. Go to the Gamedock SDK menu in the top bar of Unity and select Configuration.

Make sure the fields are configured correctly and press the ‘Create default configuration files’ button to retrieve the latest configurations for your game. This step should be repeated before every build delivered to make sure that the latest offline configs are included in the build.

The Gamedock SDK is now ready to use, most Gamedock SDK features will be configured automatically when the SDK initializes, see the specific feature sections to see which integration parts still have to be implemented. Please make sure to also follow the next section ‘GDPR & Privacy Policy’ to make your game GDPR compliant.

### Initializing the GameDock Unity SDK

By default, the Gamedock SDK will automatically initialize on Awake(). You can disable that functionality on the "GamedockSDK" object and initialize the SDK at a later stage. Initializing the SDK can be done using the following code:

~~~C#
Gamedock.MonoInstance.Initialize();
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **

### Download and Import the AIR ANE's into your project

You can find the latest version of the AIR plugin here: <url to be added>

Unpack the downloaded archive, inside you'll find 9 ANE's that you can import into your projects:

#### For iOS & Android
- GameDock-x.x.x.ANE: The main GameDock ANE, required for all platforms. For iOS, this also includes most dependencies, for Android, there are other ANE's that can be added as modules. 

#### For iOS
- com.distriqt.Core: Prevents crashes on iOS devices caused by dependencies using compiler flags that AIR doesn't recognise. Always include this for iOS.

#### For Android:
- GameDockAdjust-x.x.x.ANE: Optional, used for Adjust tracking and deeplinking.
- GameDockAdMob-x.x.x.ANE: Optional, used for Advertising (interstitials, rewarded videos, banners).
- GameDockChartboost-x.x.x.ANE: Optional, used for interstitials (will be deprecated soon and included in AdMob).
- GameDockFirebase-x.x.x.ANE: Optional, used Firebase event tracking, deeplinks and push notifications (Android).
- GameDockGPG-x.x.x.ANE: Optional, contains Google Play Games, used for achievements and leaderboards.
- GameDockGPS-x.x.x.ANE: Required, contains Google Play Services, used by GameDock, Admob, Firebase and GPG.
- GameDockSDKGoogleAppId-x.x.x.ANE: Optional, contains only a strings.xml resource with an app id that is unique for each game. The id is required for Firebase (analytics, among others). This ANE is provided only if your app uses it, and is unique per app.
- GameDockResources-x.x.x.ANE: Optional, used to replace GameDock assets (images) with game-specific assets, for instance for the logo's on the GDPR privacy policy menu.

### Using the Gamedock AIR SDK

1. Import the ANE's into your project via your prefered IDE and link them via your app.xml.
2. Make sure your game version and app identifier (f.e. com.yourcompany.yourgame) match those configured in the GameDock Console, this way your game will receive the correct configurations/data.
3. Make sure you include the required .json files in the project root when packaging a build. These files should be provided to you by your GameDock representative and are downloadable via the GameDock Console.
These include:
- defaultGameConfig.json: Required, used for GameConfig and SDKConfig features.
- defaultGameData.json: optional, used for wallet/inventory features.
- defaultMissionConfig.json: optional, used for missions features. 
4. For Android, be sure to add the correct ManifestAdditions, depending on the features you're using. See the Example app included with the GameDock AIR download for examples, or see: <url to be added>.

The Gamedock SDK is now ready to use, most Gamedock SDK features will be configured automatically when the SDK initializes, see the specific feature sections to see which integration parts still have to be implemented. Please make sure to also follow the next section ‘GDPR & Privacy Policy’ to make your game GDPR compliant.

### Initializing the GameDock AIR SDK

In your app's main entry-point, before making any other calls or initialising other libraries, do the following:
1. Check if GameDock is supported for the current platform (mobile/pc etc).
2. Attach event handlers for any GameDock events that your app requires.
3. Initialise GameDock.

Example (including privacy policy / GDPR and Google Play Games for Android):
~~~C#
	public function Main()
	{
		// Initialise GameDock and show Privacy Policy / GDPR popup.
		if (!GameDock.isSupported())
		{
			trace("GameDock is not supported on this platform."); // When not Android or iOS
			return;
		}
  
		// Attach event handlers for GameDock features used by your app.
		
		// Such as ads
		GameDock.GetInstance().addEventListener(GameDockEvents.AD_AVAILABLE, onAdAvailableEvent);
		GameDock.GetInstance().addEventListener(GameDockEvents.AD_FINISHED, onAdFinishedEvent);
		GameDock.GetInstance().addEventListener(GameDockEvents.AD_NOT_AVAILABLE, onAdNotAvailableEvent);
		GameDock.GetInstance().addEventListener(GameDockEvents.AD_STARTED, onAdStartedEvent);
		
		// And GDPR / Privacy policy popup.
		GameDock.GetInstance().addEventListener(GameDockEvents.AGE_GATE_STATUS, onAgeGateStatusEvent);
		GameDock.GetInstance().addEventListener(GameDockEvents.PRIVACY_POLICY_STATUS, onPrivacyPolicyStatusEvent);
  
		// Disable automatic registering for Push Notifications for iOS so users don't get a pop-up.
		GameDock.GetInstance().DisableAutomaticRegisterForPushNotificationsiOS();
  
		// Initialise GameDock with the prefered privacy policy / GDPR settings. 
		// After the user passes the privacy policy / GDPR menu, GameDock will start requesting/processing data and firing events.
		GameDock.GetInstance().Init(true, true, true, 16, false, GCMProjectId);
	}
  
	private function onPrivacyPolicyStatusEvent(evt:PrivacyPolicyStatusEvent) : void
	{
		// If the user accepted the policy, initialise other libraries, such as Google Play Games.
		if(evt.accepted)
		{
			if (GameDockGPG.isSupported())
			{
				// Initialise Google Play Games and log in the user.
				trace("Starting GameDock Google Play Games");
				GameDockGPG.create(false, false, null);
				GameDockGPG.games.signIn();
			} else {
				trace("Google Play Games is not supported on this platform (not Android!)");
			}
		}
	}

~~~

* Be sure to also check the example project included with the GameDock AIR SDK download, as it provides examples for most features.

### Publishing an app with the GameDock AIR SDK

- When publishing your app, you'll likely want to replace any Azerion branding (logo's, background images etc) with your own. For AIR, you'll need to have a Windows device with WinRar (or similar) in order to replace the assets contained in  GameDockResources.x.x.x.ANE. If you don't have a Windows device, ask your GameDock representative to create a custom ANE for you via Slack. 

- For iOS, make sure that the InfoAdditions and Entitlements match those in the provisioning profile, or you may have trouble publishing/uploading to App Stores. You can check what's defined in your provisioning profile via console/terminal commands (see also: https://stackoverflow.com/questions/11834650/ios-look-inside-provisioning-profile).

- For iOS, when using push notifications, make sure that the "aps-environment" entitlement is set to the correct environment (development/production).

<!-- tabs:end -->
