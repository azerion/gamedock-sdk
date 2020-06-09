# Splash and Daily Bonus Screens

The Gamedock framework offers the possibility of supporting both splash and bonus screens. Splash screens appear while a game is loading. They are a very useful means of engaging with the user community and can be used for a variety of reasons, including as an additional form of advertising, to restrict access to content such as pornography or gambling, and to grab the user’s attention through special offers. Typically, daily bonus screens are used to reward users each time they return to the game. Within the Gamedock framework, both screen types are implemented as HTML5 web pages that appear as pop-ups within the game. This has the advantage that changes can be made to them without the need to update the game itself.

## Understanding the Splashscreens Strategy

Within the Gamedock platform, splash and daily bonus screen support are implemented as follows:
1. The Game’s producer defines the splash screens required to be used within the game. This includes the platforms for which each screen is intended, the relevant game version, the event that triggers the screen, its URL, the period within which it is active. The daily bonus screens should also be defined, and include the items or currency the user should receive, and the number of times the user should see the screen. Note that if these screens are to be developed by a third party, Gamedock can provide a template for their creation.
1. Your Gamedock Account Manager will then coordinate with Gamedock LiveOps to ensure that the screens are set up on the Gamedock server.
1. Within the Gamedock SDK, developers can then specify when these screens should appear within the game.

## Controlling Splash Screens

Splash screens can be triggered in one of two ways. They can either be fired automatically as a response to a tracking event (such as level complete), or they can be triggered manually.

Before requesting the splash screen, you should implement the callback listener using the following code:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenOpen -= OnSplashScreenOpen;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenOpen += OnSplashScreenOpen;

Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenClosed -= OnSplashScreenClosed;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenClosed += OnSplashScreenClosed;

Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenError -= OnSplashScreenError;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenError += OnSplashScreenError;

//Used for cached splash screens
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenAvailable -= OnSplashScreenAvailable;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenAvailable += OnSplashScreenAvailable;

Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenNotAvailable -= OnSplashScreenNotAvailable;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenNotAvailable += OnSplashScreenNotAvailable;

Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenOpenShop -= OnSplashScreenOpenShop;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenOpenShop += OnSplashScreenOpenShop;

Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenData -= OnSplashScreenData;
Gamedock.Instance.SplashScreenCallbacks.OnSplashScreenData += OnSplashScreenData;

Gamedock.Instance.IAPValidationCallbacks.OnIAPRequestPurchase -= OnIAPRequestPurchase;
Gamedock.Instance.IAPValidationCallbacks.OnIAPRequestPurchase += OnIAPRequestPurchase;
~~~

#### ** AIR **

~~~actionscript
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_OPEN, onSplashScreenOpenEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_CLOSED, onSplashScreenClosedEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_ERROR, onSplashScreenErrorEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_AVAILABLE, onSplashScreenAvailableEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_NOT_AVAILABLE, onSplashScreenNotAvailableEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_OPEN_SHOP, onSplashScreenOpenShopEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.SPLASH_SCREEN_DATA, onSplashScreenDataEvent);
Gamedock.GetInstance().addEventListener(SDKEvents.IAP_REQUEST_PURCHASE, onIAPRequestPurchaseEvent);
~~~

#### ** Cordova **

~~~javascript
gamedockSDK.on('SplashScreenOpen', () => {
    
    }
});

gamedockSDK.on('SplashScreenClosed', () => {

    }
});

gamedockSDK.on('SplashScreenAvailable', (type) => {

    }
});

gamedockSDK.on('SplashScreenNotAvailable', () => {

    }
});

gamedockSDK.on('SplashScreenOpenShop', () => {

    }
});
~~~

<!-- tabs:end -->

To work with splash screens during game time, use the following code:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
Gamedock.Instance.RequestSplashScreen(string type);

//Should be used when an OnSplashScreenAvailable callback is triggered 
//Can be used immediately or later in the game once the callback is triggered
Gamedock.Instance.ShowSplashScreen();
~~~

#### ** AIR **

~~~actionscript
Gamedock.GetInstance().RequestSplashScreen(type:String);

//Should be used when an OnSplashScreenAvailable callback is triggered 
//Can be used immediately or later in the game once the callback is triggered
Gamedock.GetInstance().ShowSplashScreen();
~~~

#### ** Cordova **

~~~javascript
gamedockSDK.requestSplashScreen(type);

//Should be used when an OnSplashScreenAvailable callback is triggered 
//Can be used immediately or later in the game once the callback is triggered
gamedockSDK.playInterstitial();
~~~

<!-- tabs:end -->