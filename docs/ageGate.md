# Age Gate

Certain games are required to have an age gate at the start of the game before it allows the players to continue. This functionality is provided by the Gamedock SDK and it comes in two flavours: a native popup where you can only configure the banner image or a Unity prefab which can be full customizable as long as no elements or scripts are removed.

![github pages](_images/agegate-popup.png)

## Enable or disable the age gate popup

The age gate popup can be enabled using the "GamedockSDK" object or through the Gamedock SDK Configuration menu. If enabled, the age gate will always appear first time the user opens the game **before** the GDPR/Privacy Policy popup. In order to configure the age gate popup with, you can edit it in the "GamedockSDK" object. The following options are available:

![github pages](_images/agegate-config.png)

The SDK gives the possibility for blocking the user from continuing to the game if the minimum age requirement is not met. You also can select to either use the native popup or the Unity prefab. 

**If you use the Unity prefab, make sure to drag the prefab from the Assets/Resources/Gamedock/AgeGate folder on to the GamedockSDK object.**

## Handling age gate callbacks

Regardless of which option you choose (native or prefab), the SDK provides feedback information for the choice that the user has made when presented with the age gate. In order to get that feedback, register the following callback:

~~~C#
//Callback informing the choice for the age gate
Gamedock.Instance.AgeGateCallbacks.OnAgeGateStatus -= OnAgeGateStatus(bool passed, string age, bool checkPrivacyPolicy);
Gamedock.Instance.AgeGateCallbacks.OnAgeGateStatus += OnAgeGateStatus(bool passed, string age, bool checkPrivacyPolicy);
~~~

The variables returned are the following:
 * *passed* - Informs the game if the age gate was passed based on the minimum age requirement.
 * *age* - Returns the age that was chosen by the user. Can be: **0-12, 13-15, 16+**.
 * *checkPrivacyPolicy* - Informs if the user should be exposed to GDPR compliency. You are not required to do anything manual with the actual GDPR popup, though if the flag is false, you might want to hide the GDPR button in your Settings screen for example.

## Changing the header image

If you want to set your own custom header image instead of the Azerion logo, you can do so by overwriting the appropriate image file to the following location (if it does not exist, you will need to create it):

PROJECT_PATH/Assets/Plugins/Android/res/drawable/

The image files should have the name “privacy_policy_landscape_custom.png” or “privacy_policy_portrait_custom.png” depending on your orientation. The image size is 800px x 220px or 600px x 220px.

For iOS, the header image can be replaced at Gamedock.framework/PrivacyPolicyHeader.png.

For Unity 2017.1 and above you can use the supplied project found in the SDK bundle under NativeLibraries/Android/Resources. Build this project in Android Studio and make sure to replace the necessary images.

## Changing the age gate popup text

Note that the text and translations of the popup are kept in the Gamedock SDK Game config feature, which should be by default integrated into your game. Note that in case you are working on an update you can fetch the new game config in Unity (we already updated the game config contents). Only in case of explicit requests by your account manager the default text and translations may be changed. Please don’t change this text on your own as this must be legally correct.