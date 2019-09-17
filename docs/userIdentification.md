# User Management

When a user contacts Gamedock Customer Support they may be asked for a Gamedock user ID. Currently, Gamedock does not require registration for users, and so cannot link an email to a Gamedock user ID. All users are essentially guest users and, therefore, have an anonymous user ID.
Support for user identification depends on the games platform:
* Android: developers should show the Gamedock user ID in-game. For instance, within a settings screen. The Gamedock user ID can be obtained by calling the Gamedock.Instance.GetGamedockUID() method of the Gamedock SDK.
* iOS: no specific action is required. The build script automatically inserts a Settings.bundle file into your Xcode project. This results in the Generic Settings app from Apple being updated and showing some SDK-related option, as well as the user’s ID. If you still want to obtain the Gamedock user ID, you can call the Gamedock.Instance.GetGamedockUID() method.

## Setting Customer User IDs

If your game has a way to authenticate users (for example, by using Facebook), ensure that the Custom User ID is set with the Facebook ID, or your own global user ID.

Once the custom user ID and provider have been set, they will be sent with each event. The Gamedock SDK also uses its own generated guest user ID. To configure the Custom User ID and provider, use the following code:

~~~C#
//Set custom user id and provider
Gamedock.Instance.SetUserId(provider, customUserId);

//Get custom user id
string userId = Gamedock.Instance.GetUserId();

//Get provider
string provider = Gamedock.Instance.GetUserProvider();
~~~

Note that the provider is not strictly defined. Therefore, it does not matter what you pass as long as it is a string (for example, “FB”, ”facebook”, “twitter”, or “myBrand”).

## User ID modifications from SLOT

It’s possible for customer support to change the user id of a player through SLOT. This is useful when the user, for example, lost his progress because his previous account could not correctly be retrieved. See below an example of how to use this feature:

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

The Gamedock SDK will never automatically change the user id when the ConfirmUserIdChange() is never fired the old user id will remain being used.

## Informing the user about a required game update

If your game requires to be run on only the most recent version you can enforce that using the Gamedock SDK and Console. In Console under the version page you have the possibility to define two options:
* Recommended Version: This informs the game and the user that a new recommended version is available in the store. They should not be forced to update to that version.
* Forced Version: This informs the game and the user that in order to continue playing they should update the game from the store.

In order to implement the functionality into your game you only need to listen to the following callback from the Gamedock SDK:

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