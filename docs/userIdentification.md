# User Management

When a user contacts Gamedock Customer Support they may be asked for a Gamedock user ID. Currently, Gamedock does not require registration for users, and so cannot link an email to a Gamedock user ID. All users are essentially guest users and, therefore, have an anonymous user ID.
Support for user identification depends on the games platform:
* Android: developers should show the Gamedock user ID in-game. For instance, within a settings screen. The Gamedock user ID can be obtained by calling the Gamedock.Instance.GetGamedockUID() method of the Gamedock SDK.
* iOS: no specific action is required. The build script automatically inserts a Settings.bundle file into your Xcode project. This results in the Generic Settings app from Apple being updated and showing some SDK-related option, as well as the user’s ID. If you still want to obtain the Gamedock user ID, you can call the Gamedock.Instance.GetGamedockUID() method.

<!-- tabs:start -->

#### ** Unity **

~~~C#
//Get Gamedock User Id
strimng userId = Gamedock.Instance.GetGamedockUID();

//Get Gamedock Device Id
string deviceId = Gamedock.Instance.GetDeviceId();
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **



#### ** Cordova **

~~~JavaScript
//Get Gamedock User Id
gamedockSDK.getGamedockUserId();

//Get Gamedock Device Id
gamedockSDK.getGamedockDeviceId();
~~~~

<!-- tabs:end -->



## Setting External IDs

Additional external ids can be passed to the SDK in order to provide better tracking and offering the possibility of linking different services on the backend. You can pass additional external ids at SDK initialization if you perform manual initialization for the SDK. This can be done using the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.MonoInstance.Initialize(Dictionary<string, string> externalIds = null);
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **



#### ** Cordova **

~~~JavScript
gamedockSDK.initialise(withAgeGate, ageGateOptions, withPrivacyPolicy, environment, externalIds);
~~~

<!-- tabs:end -->

External ids can also be set and removed (if necessary) at later stages in the game using the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
//Add external Id
Gamedock.Instance.AddExternalId(externalPartner, id);

//Remove external Id
Gamedock.Instance.RemoveExternalId(externalPartner);
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **



#### ** Cordova **

~~~JavaScript
//Add external Id
gamedockSDK.addExternalId(externalPartner, id);

//Remove external Id
Gamedock.Instance.removeExternalId(externalPartner);
~~~

<!-- tabs:end -->

Note that the provider is not strictly defined. Therefore, it does not matter what you pass as long as it is a string (for example, “FB”, ”facebook”, “twitter”, or “myBrand”).

## User ID modifications from the Gamedock Console

It’s possible for customer support to change the user id of a player through the Gamedock Console. This is useful when the user, for example, lost his progress because his previous account could not correctly be retrieved. See below an example of how to use this feature:

<!-- tabs:start -->

#### ** Unity **

~~~C#
// Start listening to user id change requests
Gamedock.Instance.InitializationCallbacks.OnUserIdChangeRequest -= OnUserIdChangeRequest;
Gamedock.Instance.InitializationCallbacks.OnUserIdChangeRequest += OnUserIdChangeRequest;

private void OnUserIdChangeRequest(string newuserid) {
  // Update the game to allow the new user id to be used
  
  // Confirm back to the Gamedock SDK to change the user id
  Gamedock.Instance.ConfirmUserIdChange();
}
~~~

First, the Gamedock SDK calls the OnUserIdChangeRequest with the new user id. In this callback, the game should prepare the state to allow a user id change. Once this is done the ConfirmUserIdChange() method of the Gamedock SDK should be called to let the Gamedock SDK change the Gamedock SDK and do a full reload of the entire loaded user data.

#### ** Android **



#### ** iOS **



#### ** AIR **



#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

The Gamedock SDK will never automatically change the user id when the ConfirmUserIdChange() is never fired the old user id will remain being used.

## Informing the user about a required game update

If your game requires to be run on only the most recent version you can enforce that using the Gamedock SDK and Console. In Console under the version page you have the possibility to define two options:
* Recommended Version: This informs the game and the user that a new recommended version is available in the store. They should not be forced to update to that version.
* Forced Version: This informs the game and the user that in order to continue playing they should update the game from the store.

In order to implement the functionality into your game you only need to listen to the following callback from the Gamedock SDK:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.InitializationCallbacks.OnGameVersionStatus -= OnGameVersionStatus;
Gamedock.Instance.InitializationCallbacks.OnGameVersionStatus += OnGameVersionStatus;

public void OnGameVersionStatus(GamedockUnityImplementationBase.UpdateStatus status) {
}

//Possible values for GamedockUnityImplementationBase.UpdateStatus
public enum UpdateStatus {
    Recommended,
    Forced
}
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **



#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->