# Frequently Asked Questions

## General
1. **What platforms/game engines does Gamedock support?**

Currently Gamedock supports the following platforms:
* Android (Native)
* iOS (Native)
* Unity Android, iOS & Standalone(experimental)
* Cordova Android & iOS
* AIR Android & iOS

2. **What are the costs involved with using Gamedock?**

Interested in what Gamedock can do for your app? Please get in touch with one of our representatives via [gamedock.support@azerion.com](gamedock.support@azerion.com) for more information on how to get started.

## Data
1. **How long does Gamedock retain the data from users?**

The Gamedock backend retains the tracked data from users for a maximum amount of 1 year after which that data is purged automatically. The user can also request to have his data removed earlier if he wants.

2. **Are there any limits when sending data to the Gamedock Backend?**

At the moment there is no hard limit on the amount of data the game should be sending, though certain situation should be taken into account. The game should not be spaming event tracking on events that are not relevant in any way to insightful data. Also the game should take into account when sending the Gamestate, that the size of it doesn't go over 1MB.

3. **What happens with the data that has been tracked by the game while playing offline?**

All the that has been tracked while the game was offline will be sent to the backend when a network connection is established. On Android, the data is sent regardless if the app is open or not, while on iOS the data will be sent only if the app is open.

4. **Where can I view the data that has been sent by the SDK?**

The data sent by the Gamedock SDK can be seen in two places. If you want to see live data being sent from you (the developer) to the backend, you can use the Event Dashboard in the Console. If you want to see analytics data and insights into your gamae please visit [https://reporting.gamedock.io/](https://reporting.gamedock.io/). Make sure to contact your organization manager or a Gamedock representative to get access to the reporting tool.

## Privacy
1. **Is Gamedock GDPR compliant?**

Gamedock is committed to being GDPR, CCPA and distribution platform compliant, and to support development teams with the tooling they need to help end users manage their data. Under GDPR, our status is that of both a data processor and a data controller as much of our functionality relies on the data we collect. For more information please refer to our Privacy Policy here: [https://azerion.com/business/mobile-apps-privacy-policy.html](https://azerion.com/business/mobile-apps-privacy-policy.html) .

2. **What type of data does Gamedock track?**

We collect a variety of information through end users general interaction with apps that have the Gamedock SDK integrated. Collected personal data may include, but is not limited to, device information, application usage data and automated electronic interations. For more information please refer to our Privacy Policy here: [https://azerion.com/business/mobile-apps-privacy-policy.html](https://azerion.com/business/mobile-apps-privacy-policy.html).

3. **Can it be specified if a user has opted out of user specific features (personalized content, contextual ads)?**

The Gamedock SDK has two ways of accepting opt out choices from the user:
* The SDK comes pre-built with a consent popup functionality which can be customized to certain degrees and which take the input from the user on choices regarding ads and content. The SDK also reports back to the game what the choices from the user have been and also this information can be retrieved at any point.
* If you decide not to use the pre-built consent popup, you can also pass in the information to the SDK manually for personalized content and contextual ads.

## SDK
1. **What additional optional modules/plugins does Gamedock contain in it's package?**

The Gamedock SDK contains the following optional additional modules that can be enabled/disabled depending on your needs:
* Adjust SDK module
* AppsFlyer SDK module
* AdMob/AdManager including multiple additional mediation ad partners
* Firebase SDK module containing the implementation for Analytics, Remote Config, Dynamic Links and Crashlytics

2. **Do I need any additional keys in order to initialize/work with the SDK?**

All keys are retrieved automatically from the console (if configured correctly of course) if you are using Unity or Cordova. For Unity you can always refresh all the configurations by using the Configuration menu (Top Bar->Gamedock SDK->General->Create Default Configuration Files). On Cordova the configuration keys are only retrieved once, when you add the plugin to your game (if you need to refresh the keys, remove the plugin and add it again).

3. **Does the SDK support offline behavior/operations?**

Yes, the Gamedock SDK supports offline tracking and operations. All operations done with the SDK which would send network information is saved locally on the phone until a network connection is available and then sent to the backend. Social login synchronization is also supported while the user has logged in and the device is offline.

## Console
1. **How can I access the Gamedock Console?**

The Gamedock console can be accessed at the following address: [https://console.gamedock.io/](https://console.gamedock.io/).

2. **Can I personally create a Gamedock Account or do I need to contact a Gamedock representative?**

In order to access the Gamedock Console you can login in with an approved email address (ex.: an Azerion gmail address). If you need to have your organization email be approved by Gamedock, please contact a Gamedock representative.

3. **I logged in to the Gamedock Console but I do not see any games. What is happening?**

By default, when you first login to the Console, no access is given to any games, even if your organizationl email contains games. Please make sure to contact your organization administrator or a Gamedock representative to give you access to the games you require.

4. **I can access my game in the Console, but certain features are not appearing for me. How can I get access to more features?**

Each of the feature in Console requires specific permissions to be given to your account for that game in order for you to see information in the Console. So if you need access to a specific feature or you want access to all the features, make sure to contact your organization administrator or a Gamedock representative to give you access.