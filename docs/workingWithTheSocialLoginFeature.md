# Working with the Social Login Feature

By default, a user’s data is lost when they remove a game from their device. If they later re-install it, they start again as a new user. The social login feature solves this problem by binding the user’s progress to a specified Facebook account. After re-installing the game on the same or another device via a Facebook login, they can continue from their previous state. In addition, this feature can also be used to enable users to play across multiple devices while preserving their game progress. In this way, the user’s game experience can be enhanced.

## Facebook SDK Requirements

To start using the social login feature with Facebook, do the following:

1. Download the latest version of the Facebook SDK. It is available from: [https://developers.facebook.com/docs/unity/downloads/](https://developers.facebook.com/docs/unity/downloads/).
1. Add the Facebook SDK to your IDE project as described in [https://developers.facebook.com/docs/unity/gettingstarted](https://developers.facebook.com/docs/unity/gettingstarted). Use the Facebook app ID provided by your Gamedock Account Manager.

## Implementing the Facebook Login

Within the game, login the user via the provided Facebook app using the following method and handle the result:

~~~C#
FB.LogInWithReadPermissions(new List<string>() {“public_profile”}, this.HandleResult);
~~~

Note that additional permissions (such as the user’s e-mail address) can be specified as part of the call. For further information, consult the Facebook SDK documentation. If the Facebook login is successful, retrieve the Facebook user ID and Facebook token from the Facebook SDK using the following properties:

~~~C#
String facebookUserId= AccessToken.CurrentAccessToken.UserId;
String facebookToken = AccessToken.CurrentAccessToken.TokenString;
~~~

Note that both items are required for the Gamedock SDK login.

## Implementing the Google Play Games

To start using the social login feature with Google Play Games, follow the instructions found here: [https://github.com/playgameservices/play-games-plugin-for-unity](https://github.com/playgameservices/play-games-plugin-for-unity).

## Implementing Game Center

Game center can be implemented using the Unity Social API: [https://docs.unity3d.com/Manual/net-SocialAPI.html](https://docs.unity3d.com/Manual/net-SocialAPI.html).
After login the game center’s user auth details can be retrieved using a library like this: [https://github.com/abivz/unity3d-gamekit-identity-plugin/](https://github.com/abivz/unity3d-gamekit-identity-plugin/).
The auth details can be passed to the UserLogin method in a dictionary as 4th parameter containing 3 key/value pairs: “publicKeyUrl”, salt” and “timestamp”.

## Implementing the Gamedock SDK Login

![github pages](_images/SocialLoginFeature.png)

Use the following method to login the user:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.UserLogin(string socialId, string socialProvider, string socialToken, Dictionary<string, object> socialValidationData = null);
~~~

where:
* *socialProvider* should be SocialLoginNetworks.GooglePlayGames, SocialLoginNetworks.GameCenter or SocialLoginNetworks.Facebook. Because this parameter is used across multiple methods, it is recommended that you maintain consistency by defining it statically.
* *socialId* should be the Facebook user ID, Google Play Games User Id or Game Center User Id.socialToken should be the Facebook access token retrieved earlier from Facebook, token from Google Play Games or Game Center authentication information (should be passed in the optional parameter). 


#### ** Android **



#### ** iOS **



<!-- tabs:end -->

## Failure

If the user login failed, the following event is triggered:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnLoginFailed(GamedockErrorMessage errorMessage);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

The *errorMessage* parameter describes what went wrong. The ShowNativeDialog() method call can be used to display a dialog with the error message directly to the user. Within GamedockErrorMessage, the error codes shown in the table below can be returned.

| Code | Description                                                                                    |
|:-----|:-----------------------------------------------------------------------------------------------|
| 32   | Invalid Gamedock token! Please login again.                                                  |
| 33   | Event requires user login.                                                                     |
| 34   | The provided social token could not be verified by the Gamedock backend. Please login again. |
| 35   | The user already has a social provider account. Please first logout.                           |
| 36   | The specified social ID is already linked to another user.                                     |

## Checking if a user is already logged in

Sometimes it is useful to know whether a user is already logged in. For example, when re-starting the game. The current user login status can be retrieved by calling the following method:

<!-- tabs:start -->

#### ** Unity **

~~~C#
bool loggedIn = Gamedock.Instance.IsLoggedIn();
~~~


#### ** Android **



#### ** iOS **



<!-- tabs:end -->

## Logging out a user

Use the following method call to log out a user:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.Logout(bool global);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

*global* specifies whether the user should be globally logged out of all devices they are currently playing on (TRUE), or remained logged in on any other devices (FALSE). One of the following events will be triggered to indicate whether the logout was successful:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnLogoutSuccessful();
Gamedock.Instance.SocialLoginCallbacks.OnLogoutFailed(GamedockErrorMessage errorMessage);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

Note that it is only important to handle the fail event in the case of a global logout. In this case, the *ShowNativeDialog()* call can be used to display a dialog with *errorMessage*.

## Logout and continue as a guest user

Use the following method to logout the user and let them continue as a guest user:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.UserPlayAsGuest();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

It will reset the user ID and user data. This method be called after their session token expired (explained in Handling Expired Session Tokens). This method has almost the same functionality as the normal logout call, but performs additional tracking and triggers a different success event to indicate that the user is playing as a guest:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.LoginSuccessful(false, null, null, true);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

## Handling Expired Session Tokens

The social login feature works by internally assigning a session token to the currently logged in Facebook, Google Play Game or Game Center user. Each gameplay session receives a new token. This token, called “spilToken”, is sent with each request made by the Gamedock SDK to the Gamedock backend. The token is used to validate that the user is still correctly logged in.
It can happen that the session of a logged in user is no longer valid, either because the session token has expired or due to a global logout on a different device. In these cases, an authorization error is triggered, and the user should either re-login or continue as a guest user. The following event will be triggered after an authorization error:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnAuthenticationError(GamedockErrorMessage errorMessage);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

After an authorization error, a popup is displayed to the user asking whether they want to re-login or continue as a guest user. The Gamedock SDK provides a default popup that can be used to show this error by calling the following method:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.ShowUnauthorizedDialog(string title, string message, string loginText, string playAsGuestText);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

The default dialog triggers the following event to inform the developer that the user selected the re-login option:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnRequestLogin -= OnRequestLogin();
Gamedock.Instance.SocialLoginCallbacks.OnRequestLogin += OnRequestLogin();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

The Facebook login process should be re-initiated after this event.

## Resetting the User Data

The user data (described in Supporting Wallet, Shop and Inventory Control) and game state (described in Working with Game States) can be reset after a logout or a non-guest login by calling the following method:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.ResetData();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

## Displaying the Current Device ID

The device ID can be displayed together with the Gamedock user ID in the game. This can be useful for Customer Support when resolving issues. See Implementing Customer Support for more information.

The device ID can be retrieved using the following method:

<!-- tabs:start -->

#### ** Unity **

~~~C#
string deviceId = Gamedock.Instance.GetDeviceId();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

## Implementing Cross-Device Data Synchronization

![github pages](_images/SyncFeature.png)

The user data synchronization feature can be used to enable the synchronizing of user data when a logged in user is playing across multiple devices.

## Requesting the latest user data

After initializing the Gamedock SDK, it is recommended that you request the latest user data. Normally, this is loaded successfully and is ready to use. However, in some cases merge conflicts can occur which must be resolved. The procedure to do so is described later in this section. The following method can be used to retrieve the user’s data from the Gamedock backend:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.RequestUserData();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

Note that if the data cannot be retrieved from the Gamedock backend, it will be loaded from the data stored locally on the device. The following event is triggered when the data is available for use:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataAvailable -= OnUserDataAvailable();
Gamedock.Instance.SocialLoginCallbacks.OnUserDataAvailable += OnUserDataAvailable();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

After initialization has been completed, it is possible to use and modify the user data using the methods described in Supporting Wallet, Shop and Inventory Control.

## Playing on Multiple Devices

When a second device is being used to play the same game using the same Facebook ID, synchronization errors can occur. If this happens, the following event will be triggered:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataSyncError -= OnUserDataSyncError();
Gamedock.Instance.SocialLoginCallbacks.OnUserDataSyncError += OnUserDataSyncError();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

Call the *RequestUserData()* method to re-synchronize the locally stored user data. It is recommended that gameplay is suspended at this point, and does not resume until the user data has been successfully synchronized again. There is a utility method available to show a native dialog that handles this case. It is described in Useful Utility Dialog Methods.

## Resolving Merge Conflicts

When a merge error occurs, the following event will be triggered:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataMergeConflict(MergeConflictData localData, MergeConflictData remoteData) -= OnUserDataMergeConflict();
Gamedock.Instance.SocialLoginCallbacks.OnUserDataMergeConflict(MergeConflictData localData, MergeConflictData remoteData) += OnUserDataMergeConflict();
~~~


#### ** Android **



#### ** iOS **



<!-- tabs:end -->

This indicates that the current local user data cannot be merged with the remote user data. This must be resolved by either selecting the current local data, the remote server data, or by creating a merge of both data sources. Both local and remote states are returned to resolve the conflict. The following method should be called whenever a merge conflict was resolved:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.MergeUserData(string mergeData, string mergeType);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

where:
* *mergeData* specifies the merged user data.
* *mergeType* specifies the selected merge resolution type (“remote”, “local”, or “merge”).

If the merge was successfully accepted by the Gamedock backend, the following event will be triggered:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataMergeSuccessful -= OnUserDataMergeSuccessful();
Gamedock.Instance.SocialLoginCallbacks.OnUserDataMergeSuccessful += OnUserDataMergeSuccessful();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

If the merge failed, the following event will be triggered:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataMergeFailed(string mergeData, string mergeType) -= OnUserDataMergeFailed();
Gamedock.Instance.SocialLoginCallbacks.OnUserDataMergeFailed(string mergeData, string mergeType) += OnUserDataMergeFailed();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

In this case, you should retry the merge resolution with the MergeUserData method (described above) using the data returned by this event. The default Gamedock.Instance.ShowMergeFailedDialog method can also be used to display a native error dialog box that automatically retries as soon as the user clicks the Retry button.

## Other Possible Errors

It is not possible for the Gamedock backend to accept user data from two devices at the same time. When the first device sends its changes, a lock is applied to prevent other devices from attempting to send data while the update is in progress. If this happens, the following event will be triggered:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataLockError -= OnUserDataLockError();
Gamedock.Instance.SocialLoginCallbacks.OnUserDataLockError += OnUserDataLockError();
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

It is recommended that the game waits and then tries to resend the changes later. Since Gamedock SDK version 2.7.0 the *OnPlayerDataError()* and *OnGameStateError()* events have been removed. They have been merged into the new OnUserDataError() event. The conditions in which this new event is triggered remain the same as the two replaced events, and the errorMessage payload is also unchanged. The new event has the following format:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataError(GamedockErrorMessage errorMessage) -= OnUserDataError;
Gamedock.Instance.SocialLoginCallbacks.OnUserDataError(GamedockErrorMessage errorMessage) += OnUserDataError;
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

A synchronization error can occur when user data is handled through the Gamedock Console. It indicates that the data on the Gamedock backend is different from that on the device. In this case, the same flow is required to resolve the merge conflict.

## Useful Utility Dialog Methods

The following utility method can be useful during development to display a native dialog box indicating that the user data on the Gamedock backend is different from that on the device:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.ShowSyncErrorDialog(string title, string message, string startMergeButtonText);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

The following utility method can be used to display a native dialog box asking the user whether to use the remote or local user data:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.ShowMergeConflictDialog(string title, string message, string localButtonText, string remoteButtonText, string mergeButtonText = null);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

Note that there will also be a button in the dialog when a mergeButtonText string is provided. It is recommended that this method is only used during development and that a dialog in the style of the game is created for the final product.

The following event is triggered by the *ShowMergeConflictDialog()* method:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SocialLoginCallbacks.OnUserDataHandleMerge(string mergeType);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

It specifies the choice made by the user: mergeType can be “remote”, “local”, or “merge”. The following utility method can be used to display a native merge failed dialog box asking the user whether they want to retry merging of the user data:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.ShowMergeFailedDialog(string title, string message, string retryButtonText, string mergeData, string mergeType);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

It is recommended that this method is only used during development and that a dialog in the style of the game is created for the final product.

The following method is available for displaying login/logout errors:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.ShowNativeDialog(string title, string message, string buttonText);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->