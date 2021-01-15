# Tiered Events

* **[Configuration in Console](#configuration-in-console)**
* **[Using tiered events from the SDK](#using-tiered-events-from-the-sdk)**

---

> [!TIP]
> Tiered events have to be configured through the Gamedock Console. Please ask your product manager to configure this before starting the implementation of this feature.

A tiered event is a unique event(not to be confused with tracking events) which allows the user to get special rewards by spending currencies or items within the game. A tiered event consists of multiple tiers, each individual tier has a certain goal. The goal is always to spend a certain amount of currency or items and the player will get a reward after completing a tier and then progresses to the next tier. The tiered event is finished when all the tiers are completed or when the end date of the event has been reached. The player has to spend currencies or items depending on the goal of the current tier he’s in, to progress. A web view is used to visualize the progress of the user which can be accessed through a button in the games GUI. The reward(s) for the current tier can be claimed through this web view when the goal has been reached by the player.
It’s possible to configure multiple Tiered Events to be able to run at the same time.

You can also display the tiered event progress without the need of an web view if it is desired. The SDK also exposes the functionality to manually claim a tier reward (normally done within the web view).

### Configuration in Console

**To Be Added Soon**

### Using tiered events from the SDK

The tiered events configuration can be requested manually after the Gamedock SDK has been initialized and either the available or not available callback will be fired in order to indicate if any tiered events are available:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
// Request
Gamedock.Instance.RequestTieredEvents();

// Available
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventsAvailable -= OnTieredEventsAvailable;
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventsAvailable += OnTieredEventsAvailable;
void OnTieredEventsAvailable(){}

// Not available
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventsNotAvailable -= OnTieredEventsNotAvailable;
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventsNotAvailable += OnTieredEventsNotAvailable;
void OnTieredEventsNotAvailable(){}
~~~

#### ** AIR **

~~~actionscript
// Request
Gamedock.GetInstance().RequestTieredEvents();

// Available
Gamedock.GetInstance().addEventListener(SDKEvents.TIERED_EVENTS_AVAILABLE, onTieredEventsAvailableEvent);

// Not available
Gamedock.GetInstance().addEventListener(SDKEvents.TIERED_EVENTS_NOT_AVAILABLE, onTieredEventsNotAvailableEvent);

~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

To get a list of all available active tiered events use the following method:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
List<TieredEvent> activeTieredEvents = Gamedock.Instance.GetAllTieredEvents();
~~~

#### ** AIR **

~~~actionscript
var activeTieredEvents:Vector.<TieredEvent> = GetAllTieredEvents();
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

The structure of Tiered Events is as follows:

~~~csharp
//Tiered Event
public int id; // The id of the tiered event as found in the Gamedock Console.
public string name; // The name of the tiered event.
public string type; // The type of the tiered event. It can either be a "collect" or a "spend".
public long startDate; // The start date timestamp in ms.
public long endDate; // The end date timestamp in ms.
public string imageUrl; // An url to download the image configured for the tiered event.
public List<TieredEventTier> tiers; // A list of all the tiers the tiered event has.
public Dictionary<string, object> properties; // A dictionary containing additional properties about the tiered event.

//TieredEventTier
public int id; // The id of the tier as found in the Gamedock Console.
public string name; // The given name for the tier.
public int entityId; // The id of the entity that needs to be updated (collect or spend).
public string entityType; // The type of the entity. It can be CURRENCY or ITEM.
public int entityTierStart; // The value at which the entity value starts the tier. Ex.: Tier 1 if it goes from 0 to 50, will be 0, and for Tier 2 if it goes from 50 to 200, will be 50.
public int entityTierEnd; // The value at which the entity value ends the tier. Ex.: Tier 1 if it goes from 0 to 50, will be 50, and for Tier 2 if it goes from 50 to 200, will be 200.
public string imageUrl; // An url to download the image configured for the tiered event.
public List<TieredEventReward> rewards; // The rewards that will be given when the tier is completed.
public Dictionary<string, object> properties; // A dictionary containing additional properties about the tier event.

//TieredEventProgress
public int tieredEventId; // The id of the tiered event for which the progress is.
public int currentTierId; // The id of the current tier for the user.
public int previousAmount; // The previous amount for the value of the Tier Entity.
public int currentAmount; // The current amount, after the changes, for the value of the Tier Entity.
public bool completed; // Informs if the current tier has been completed so that the user can claim his reward.
public List<int> completedTiers; // A list of tier ids which have been completed by the user.
public List<int> claimableTiers; // A list of tiers which the user can claim.
~~~

To get the progress of a tiered event call:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
TieredEventProgress progress = Gamedock.Instance.GetTieredEventProgress(int tieredEventId);
~~~

#### ** AIR **

~~~actionscript
var progress:TieredEventProgress = GetTieredEventProgress(tieredEventId:int);
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

#### Updating tiered events

The progress is automatically updated by the Gamedock SDK when either currency is being spent using the Wallet feature or when items are being spent using the Inventory feature.
An event is fired to inform that the tiered event has been updated:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventUpdated -= OnTieredEventUpdated;
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventUpdated += OnTieredEventUpdated;

void OnTieredEventUpdated(TieredEventProgress progress) {
  progress.tieredEventId; // The id of the tiered event which was updated
  progress.currentTierId; // The id of the current active tier within the tiered event
  progress.currentAmount; // The progress within the current tier
  progress.completed; // Indicates if the tiered event is completed
  progress.completedTiers; // List with completed tier ids
  progress.claimableTiers; // List of tier ids which are claimable by the player
} 
~~~

#### ** AIR **

~~~actionscript
Gamedock.GetInstance().addEventListener(SDKEvents.TIERED_EVENT_UPDATED, onTieredEventUpdatedEvent);
private function onTieredEventProgressOpenEvent(evt:TieredEventProgressOpenEvent) : void
{
	evt.tieredEventId; // The id of the tiered event which was updated
	evt.currentTierId; // The id of the current active tier within the tiered event
	evt.currentAmount; // The progress within the current tier
	evt.completed; // Indicates if the tiered event is completed
	evt.completedTiers; // List with completed tier ids
	evt.claimableTiers; // List of tier ids which are claimable by the player
}
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

> [!NOTE]
> Tier progress is always recorded even if the user is currently not at that tier. Ex.: If the user has currently completed Tier 1 but not claimed his reward, the SDK will still record progress for the next tiers.

#### Showing tiered event progress

The progress of the tiered event is visible to the user through a web view which is controlled by the Gamedock SDK and can be opened using a single call. There are 2 events which will be called to inform if the screen is opened or being closed:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
// Show the progress screen (using a WebView)
Gamedock.Instance.ShowTieredEventProgress(int tieredEventId);

// Open
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventProgressOpen -= OnTieredEventProgressOpen;
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventProgressOpen += OnTieredEventProgressOpen;
void OnTieredEventProgressOpen() {}

// Closed
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventProgressClosed -= OnTieredEventProgressClosed;
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventProgressClosed += OnTieredEventProgressClosed;
void OnTieredEventProgressClosed() {}
~~~

#### ** AIR **

~~~actionscript
// Show the progress screen
Gamedock.GetInstance().ShowTieredEventProgress(tieredEventId:int);

// Open
Gamedock.GetInstance().addEventListener(SDKEvents.TIERED_EVENT_PROGRESS_OPEN, onTieredEventProgressOpenEvent);
private function onTieredEventProgressOpenEvent(evt:TieredEventProgressOpenEvent) : void
{
	trace(evt.toString());
}

// Closed
Gamedock.GetInstance().addEventListener(SDKEvents.TIERED_EVENT_PROGRESS_CLOSED, onTieredEventProgressClosedEvent);
private function onTieredEventProgressClosedEvent(evt:TieredEventProgressClosedEvent) : void
{
	trace(evt.toString());
}
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

If the user claims his reward in the web view the OnTieredEventUpdated event will be called with the new active tier information.

#### Claiming rewards for a tier

When the requirements for a tier have been achieved by the user, a reward can be claimed (based on the configuration), in order to move to the next tier. Use the following method to claim the reward:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
// Claim a tier reward for a specific tier in a tiered event
Gamedock.Instance.ClaimTierRewards(tieredEventId, tierId);
~~~

#### ** AIR **

> This feature is currently not supported on AIR.

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

The values of the tier reward will be automatically be added to the user's Wallet and Inventory. An OnPlayerDataUpdated callback will be fired for each of the rewards with the reason value **"Tiered Reward From Client"**.

> [!NOTE]
> A tier can only be fully completed once the reward has been claimed.

#### Handling errors

A few errors can occur for the tiered events feature, the following event is used to inform you:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventsError -= OnTieredEventsError;
Gamedock.Instance.TieredEventsCallbacks.OnTieredEventsError += OnTieredEventsError;
void OnTieredEventsError(GamedockErrorMessage error) {
}
~~~

#### ** AIR **

~~~actionscript
Gamedock.GetInstance().addEventListener(SDKEvents.TIERED_EVENTS_ERROR, onTieredEventsErrorEvent);
private function onTieredEventsErrorEvent(evt:TieredEventsErrorEvent) : void
{
	log(evt.toString());
}
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

The following errors are possible:
* Id 42, TieredEventShowProgressError: The progress of the player could not be shown.
* Id 43, TieredEventUpdateProgressError: The progress of the tiered event failed to update.
* Id 44, TieredEventClaimTierError: The user tried to claim his reward but this failed.