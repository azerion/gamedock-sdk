# Anti-Cheating

Many games suffer from the problem of users attempting to subvert the rules of the game to obtain an unfair advantage over other players. Depending on the game, different activities constitute cheating, and it is either a matter of game policy or consensus opinion as to whether an activity is cheating.

Typical cheating strategies include the use of the following:
* Aimbot (sometimes called “auto-aim”) is a type of bot used in multiplayer first-person shooter games to provide varying levels of automated target acquisition to the player. While most common in first-person shooter games, they exist in other game types and are sometimes used along with a TriggerBot, which shoots automatically when an opponent appears within the field-of-view or aiming reticule of the player.
* Look-ahead cheating is a method within a peer-to-peer multiplayer gaming architecture where the cheating client gains an unfair advantage by delaying his actions to see what other players do before announcing its own action.
* World hacking is a method or third-party program that enables a user to exploit bugs and to view more of a level than intended by the developer. For example, it may allow a player to see through solid or opaque objects and manipulate or remove textures, to know in advance when an opponent is about to come into targeting range from an occluded area. World hacking relies on the fact that an FPS server usually sends raw positional information for all players in the game, and leaves it up to the client’s 3D renderer to hide opponents behind walls, in plant foliage, or in dark shade.
* Extrasensory perception (ESP) displays contextual information such as the health, name, equipment, position, and orientation of other participants as navigational/directional markers, which would normally be hidden from game players. This may be performed by reading the program’s memory with an external program, or intercepting and decoding packets as they travel between the client and the server, or by reading the memory arrays containing player positions.
* Removal of game elements allow the cheater to remove a game’s inhibitors or annoyances. These can include gun recoil, bullet spread, and obfuscating visual effects. Such removals can significantly decrease a user’s skill requirement levels.

#### Further Information

See [https://en.wikipedia.org/wiki/Cheating_in_online_games](https://en.wikipedia.org/wiki/Cheating_in_online_games) for a more complete description of cheating mechanisms.

## Receipt Validation

The receipt for a game or an in-game purchase is a record of the sale of the game or of any purchases made from within the game. You can add receipt validation code to your game to prevent unauthorized copies of your game from running.

The Gamedock SDK offers server-side IAP validation for your games. Whenever an iapPurchased event is triggered, a server validation occurs, and a response is sent back to the game. To listen to the response from the server regarding IAP validation, use the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.IAPValidationCallbacks.OnIAPValid -= OnIAPValid;
Gamedock.Instance.IAPValidationCallbacks.OnIAPValid += OnIAPValid;

Gamedock.Instance.IAPValidationCallbacks.OnIAPInvalid -= OnIAPInvalid;
Gamedock.Instance.IAPValidationCallbacks.OnIAPInvalid += OnIAPInvalid;

Gamedock.Instance.IAPValidationCallbacks.OnIAPServerError -= OnIAPServerError;
Gamedock.Instance.IAPValidationCallbacks.OnIAPServerError += OnIAPServerError;

public void OnIAPValid(string data){
  Debug.Log("IAP valid with data: " + data);
}

public void OnIAPInvalid(string message){
  Debug.Log("IAP invalid with response: " + message);
}

public void OnIAPServerError(GamedockErrorMessage errorMessage)
{
  Debug.Log("IAP error with message: " + errorMessage.message);
}
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **

Receipt validation is not supported for AIR.


<!-- tabs:end -->

Optionally, the Gamedock Games SDK can also send the receipt to the game’s backend. In this way, corrective action can be taken against false purchases or other suspicious activity.

> Note that the operation of this support depends on the connection between the game and its backend. Further information about possible connection options is available from your Gamedock Account Manager.

## Retrieving Server-Time Information

The Gamedock SDK also offers the possibility to retrieve the game’s server time. This can prove useful for anti-cheating measures. For example, if the user changes the device time or clock this does affect the execution of the game’s logic. To retrieve the server time, use the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
// Request server time
Gamedock.Instance.RequestServerTime ();
// Server time callbacks
Gamedock.Instance.ServerTimeCallbacks.OnServerTimeRequestSuccess -= OnServerTimeRequestSuccess;
Gamedock.Instance.ServerTimeCallbacks.OnServerTimeRequestSuccess += OnServerTimeRequestSuccess;

Gamedock.Instance.ServerTimeCallbacks.OnServerTimeRequestFailed -= OnServerTimeRequestFailed;
Gamedock.Instance.ServerTimeCallbacks.OnServerTimeRequestFailed += OnServerTimeRequestFailed;

void OnServerTimeRequestSuccess (long time)
{
  Debug.Log ("Server time is: " + time);
}
void OnServerTimeRequestFailed (GamedockErrorMessage errorMessage)
{
  Debug.Log ("Server failed to retrieve with error: " + errorMessage.message);
}
~~~

#### ** Android **



#### ** iOS **



#### ** AIR **

~~~C#
// Request server time
Gamedock.GetInstance().RequestServerTime();
// Server time callbacks
Gamedock.GetInstance().addEventListener(SDKEvents.SERVER_TIME_REQUEST_FAILED, onServerTimeRequestFailedEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SERVER_TIME_REQUEST_SUCCESS, onServerTimeRequestSuccessEvent);

private function onServerTimeRequestFailedEvent(evt:ServerTimeRequestFailedEvent) : void
{
	trace(evt.toString());
}

private function onServerTimeRequestSuccessEvent(evt:ServerTimeRequestSuccessEvent) : void
{
	trace(evt.toString());
}
~~~

<!-- tabs:end -->