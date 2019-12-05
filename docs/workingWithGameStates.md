# Working with Game States

The Gamedock SDK supports the saving of game state information. There are two varieties of game state information:
* Private: these are associated with the Gamedock user ID. This user ID is automatically created by the Gamedock SDK the first time the user launches the game. Typically, they contain information related to a user’s progress. For example, preference settings, achieved levels and checkpoints, unlocked features or characters, and story progression. These game states cannot be shared with external users.
* Public: if you plan on saving these, you are required to provide a custom user ID and provider (such as Facebook or Twitter). Typically, they contain information such as achievements, leaderboards, highest scores, and things that should be highlighted. These game states can be shared with external users.

## Implementing Game States

The latest versions of the states are retrieved automatically by the Gamedock SDK at the start of the game. If a state cannot be retrieved (for example, due to a failed network connection), then the state stored locally on the user’s device is used. If this is not available, then it is treated as a new game. In addition, if a user logs on to a game using Facebook, you can request the public states of their friends by supplying their user IDs and providers.

To operate game state support, use the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
// Set public and private game states.
Gamedock.Instance.SetPublicGameState(gameState);
Gamedock.Instance.SetPrivateGameState(gameState);

// Get public and private game states.
string publicGameState = Gamedock.Instance.GetPublicGameState();
string privateGameState = Gamedock.Instance.GetPrivateGameState();

// Request other user's game states.
// Requires a provider and a JSON string list.
Gamedock.Instance.GetOtherUsersGameState(provider, userIdsList);
~~~

To listen to the available callbacks, use the following methods:

~~~C#
// The following methods are called for the game state operations.
public delegate void OtherUsersGameStateDataLoaded(OtherUsersGameStateData data);
//Check the Handling errors page for a list of error messages
public delegate void UserDataError(GamedockErrorMessage errorMessage);
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **

~~~C#
// Set public and private game states.
Gamedock.GetInstance().SetPublicGameState(gameState);
Gamedock.GetInstance().SetPrivateGameState(gameState);

// Get public and private game states.
var publicGameState:String = Gamedock.GetInstance().GetPublicGameState();
var privateGameState:String = Gamedock.GetInstance().GetPrivateGameState();

// Request other user's game states.
// Requires a provider and a JSON string list.
Gamedock.GetInstance().GetOtherUsersGameState(provider, userIdsList);
~~~

To listen to the available callbacks, use the following methods:

~~~C#

// The following methods are called for the game state operations.

Gamedock.GetInstance().addEventListener(SDKEvents.OTHER_USERS_GAME_STATE_DATA_LOADED, onOtherUsersGameStateDataLoadedEvent);
private function onOtherUsersGameStateDataLoadedEvent(evt:OtherUsersGameStateDataLoadedEvent) : void
{
	trace(evt.toString());
}

//Check the Handling errors page for a list of error messages
Gamedock.GetInstance().addEventListener(SDKEvents.USER_DATA_ERROR, onUserDataErrorEvent);
private function onUserDataErrorEvent(evt:UserDataErrorEvent) : void
{
	trace(evt.toString());
}
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

> There is a 2mb limit for the gamestate, sending bigger gamestates will be ignored by the backend.