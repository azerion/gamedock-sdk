# Splash and Daily Bonus Screens

The Gamedock framework offers the possibility of supporting both splash and bonus screens. Splash screens appear while a game is loading. They are a very useful means of engaging with the user community and can be used for a variety of reasons, including as an additional form of advertising, to restrict access to content such as pornography or gambling, and to grab the user’s attention through special offers. Typically, daily bonus screens are used to reward users each time they return to the game. Within the Gamedock framework, both screen types are implemented as HTML5 web pages that appear as pop-ups within the game. This has the advantage that changes can be made to them without the need to update the game itself.

## Understanding the Daily Bonus Screens Strategy

Within the Gamedock platform, splash and daily bonus screen support are implemented as follows:
1. The Game’s producer defines the splash screens required to be used within the game. This includes the platforms for which each screen is intended, the relevant game version, the event that triggers the screen, its URL, the period within which it is active. The daily bonus screens should also be defined, and include the items or currency the user should receive, and the number of times the user should see the screen. Note that if these screens are to be developed by a third party, Gamedock can provide a template for their creation.
1. Your Gamedock Account Manager will then coordinate with Gamedock LiveOps to ensure that the screens are set up on the Gamedock server.
1. Within the Gamedock SDK, developers can then specify when these screens should appear within the game.

## Controlling Daily Bonus Screens

The reward received by users through the daily bonus screen can be handled in one of two ways. If the game implements the wallet and inventory control system provided by the Gamedock SDK, then it is handled automatically, and a callback is fired when the user’s wallet and inventory have been updated with the correct values. If the game does not use these mechanisms, then the DailyBonusReward callback will be fired returning a string list of rewards, and then the developer must implement the logic necessary for updating the game’s wallet and inventory.

Before requesting the daily bonus screen, you should implement the callback listener using the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusAvailable -= OnDailyBonusAvailable;
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusAvailable += OnDailyBonusAvailable;

Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusNotAvailable -= OnDailyBonusNotAvailable;
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusNotAvailable += OnDailyBonusNotAvailable;
~~~

#### ** AIR **

~~~C#
Gamedock.GetInstance().addEventListener(SDKEvents.DAILY_BONUS_AVAILABLE, onDailyBonusAvailableEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.DAILY_BONUS_NOT_AVAILABLE, onDailyBonusNotAvailableEvent);
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

To request the daily bonus screen during the game, use the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.RequestDailyBonus();
~~~

#### ** AIR **

~~~C#
Gamedock.GetInstance().RequestDailyBonus();
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

If the daily bonus screen is available call the following method to show it:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.ShowDailyBonus();
~~~

#### ** AIR **

~~~C#
Gamedock.GetInstance().ShowDailyBonus();
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

To listen to status updates of the daily bonus screen listen to the following events:

<!-- tabs:start -->

#### ** Unity **

~~~C#
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusOpen -= OnDailyBonusOpen;
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusOpen += OnDailyBonusOpen;

Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusClosed -= OnDailyBonusClosed;
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusClosed += OnDailyBonusClosed;

Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusError -= OnDailyBonusError;
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusError += OnDailyBonusError;

//Called only if the daily bonus has external rewards
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusReward -= OnDailyBonusReward;
Gamedock.Instance.SplashScreenCallbacks.OnDailyBonusReward += OnDailyBonusReward;
~~~

#### ** AIR **

~~~C#
Gamedock.GetInstance().addEventListener(SDKEvents.DAILY_BONUS_OPEN, onDailyBonusOpenEvent);			
Gamedock.GetInstance().addEventListener(SDKEvents.DAILY_BONUS_CLOSED, onDailyBonusClosedEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.DAILY_BONUS_ERROR, onDailyBonusErrorEvent);

//Called only if the daily bonus has external rewards
Gamedock.GetInstance().addEventListener(SDKEvents.DAILY_BONUS_REWARD, onDailyBonusRewardEvent);
~~~

#### ** Cordova **

> This feature is currently not supported on Cordova.

<!-- tabs:end -->

It’s also possible to create a daily bonus screen using Unity’s asset bundle system, for that the raw daily bonus config data can be used:

~~~C#
DailyBonus config = Gamedock.Instance.GetDailyBonusConfig();
~~~
