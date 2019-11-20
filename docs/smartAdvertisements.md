# Smart Advertisements

Typically, the monetization of your games comes through advertising. Showing the right ads to the right users at the right time can highly influence the revenues you can earn per ad. The Gamedock platform supports the use of Interstitial (smart) ads based on user behavior. For example, if a user has just completed three levels in a row and is about to receive a large in-game bonus, they are likely to be more engaged. Therefore, this could be a good moment to show an ad because it is unlikely that they are about to leave the game.

Interstitial ads are full-screen ads that cover the interface of an app until closed by the user. Typically, they are displayed at natural transition points in the flow of an app, such as between activities or during the pause between levels in a game. When an app shows an interstitial ad, the user has the choice to either click on the ad and continue to its destination (such as a reward video), or close it and return to the app.

## Handling Banner Ads

Banners are advertisements that can be displayed by the game in specific and designated areas. Currently, the Gamedock SDK supports the displaying of banners on the bottom part of the game. Banner ads can be shown or hidden depending on the situation and screen in which the player is. In order to work with the banners implementation from the Gamedock SDK use the following methods:

<!-- tabs:start -->

#### ** Unity **

~~~C#
//Request banner ads
//A new request is required if you want to change positon or ad size
Gamedock.Instance.RequestBannerAd(BannerPosition position = BannerPosition.NULL, BannerAdSize adSize = BannerAdSize.NULL);

//Possible values for BannerPosition
//If NULL is passed it will default to BOTTOM
public enum BannerPosition {
    NULL,
    TOP,
    BOTTOM
}

//Possible values for BannerAdSize
/If NULL is passed it will default to SMART_BANNER
//Some sizes might not work for Unity Editor
public enum BannerAdSize {
    NULL,
    BANNER,
    LEADERBOARD,
    FULL_BANNER,
    LARGE_BANNER,
    SMART_BANNER,
    MEDIUM_RECTANGLE
}

//Showing and hiding a banner ad
Gamedock.Instance.ShowBannerAd();
Gamedock.Instance.HideBannerAd();

//Callbacks
Gamedock.Instance.AdvertisementCallbacks.OnAdAvailable -= OnAdAvailable;
Gamedock.Instance.AdvertisementCallbacks.OnAdAvailable += OnAdAvailable;

Gamedock.Instance.AdvertisementCallbacks.OnAdNotAvailable -= OnAdNotAvailable;
Gamedock.Instance.AdvertisementCallbacks.OnAdNotAvailable += OnAdNotAvailable;

void OnAdAvailable(enumAdType adType) {
        if (adType == enumAdType.Banner) {
            ...Show Ad Container...
            //Show Banner Ad
            Gamedock.Instance.ShowBannerAd();
        }
}

void OnAdAvailable(enumAdType adType) {
        if (adType == enumAdType.Banner) {
            ...Hide Ad Container...
        }
}
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->


## Handling Interstitial Ads

Interstitial ads are full-screen ads that cover the interface of their host app. They are typically displayed at natural transition points in the flow of an app, such as between activities or during the pause between levels in a game. By default, the Gamedock SDK shows interstitial ads based on specific event triggers that can be configured in the Gamedock Console.

> The game events that should trigger interstitial ads need to discussed and agreed with your Gamedock Account Manager. You can also manually trigger an interstitial ad using the following functions:
<!-- tabs:start -->

#### ** Unity **

~~~C#
//Request an interstitial ad
Gamedock.Instance.RequestInterstitial();

//Show an interstitial ad
Gamedock.Instance.ShowInterstitial();

//Callbacks for interstitials are the same as for banners and reward videos except that the "enumAdType" is "interstitial"
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->



## Handling Reward Videos

Reward videos are advertisements that users voluntarily watch and, if played to the end, receive some form of in-game reward. The in-game currency the user receives, and how soon afterward they can watch another reward video, are set by parameters within the configuration file. Most advertisement functionality is handled automatically by the Gamedock SDK. However, you will need to specify how the triggering of reward videos and subsequent payout to the player upon completion of the video should be handled. The following shows an example of code that checks if a reward video is available, hides or shows the Watch Video button, and rewards the player if a reward video was successfully played.

<!-- tabs:start -->

#### ** Unity **

~~~C#
public GameObject rewardVideoButton;

void OnEnable(){
  rewardVideoButton.SetActive (false);
  Gamedock.Instance.AdvertisementCallbacks.OnAdAvailable += OnAdAvailable;
  Gamedock.Instance.AdvertisementCallbacks.OnAdNotAvailable += OnAdNotAvailable;
  Gamedock.Instance.RequestRewardVideo ();
}

void OnDisable(){
  Gamedock.Instance.AdvertisementCallbacks.OnAdAvailable -= OnAdAvailable;
  Gamedock.Instance.AdvertisementCallbacks.OnAdNotAvailable -= OnAdNotAvailable;
}

void OnAdAvailable(Gamedock.Unity.Utils.enumAdType adType){
  if (adType == Gamedock.Unity.Utils.enumAdType.RewardVideo) {
    rewardVideoButton.SetActive (true);
  }
}

void OnAdNotAvailable(Gamedock.Unity.Utils.enumAdType adType){
  if (adType == Gamedock.Unity.Utils.enumAdType.RewardVideo) {
    rewardVideoButton.SetActive (false);
  }
}
~~~

When the user clicks the button, the following code is triggered:

~~~C#
public void ShowRewardedVideo(){
    Gamedock.Instance.AdvertisementCallbacks.OnAdStarted += AdOpened;
    Gamedock.Instance.AdvertisementCallbacks.OnAdFinished += AdFinished;
    Gamedock.Instance.PlayRewardVideo ();
}

void AdOpened(){
    //mute the game and pause if neccessary
    muteAudio = true;
}

void AdFinished(Gamedock.Unity.Utils.GamedockAdFinishedResponse response){
    
    game.resume();
    
    if (response.GetTypeAsEnum() == Gamedock.Unity.Utils.enumAdType.RewardVideo){
            if (response.reason.Equals("close") && response.reward != null) {
                playerCoins += response.reward.reward;
            } else if (response.reason.Equals("dismiss")){
                Debug.Log("Video was canceled! No reward will be given.");
            }
    }

}
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->



## Handling More Apps Screens

The More Apps screen needs to be triggered manually. Typically, it shows other games that the user might be interested in playing. The procedure for showing a More Apps screen is very like that to show a reward video. First, check if the feature is available. If so, you can show a button in the game to open the More Apps screen. Use the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
public GameObject moreAppsButton;
 
void OnEnable(){
  Gamedock.Instance.RequestMoreApps ();
}
 
void OnAdAvailable(Gamedock.Unity.Utils.enumAdType adType){
  if (adType == Gamedock.Unity.Utils.enumAdType.MoreApps) {
    moreAppsButton.SetActive (true);
  }
}
 
void OnAdNotAvailable(Gamedock.Unity.Utils.enumAdType adType){
  if (adType == Gamedock.Unity.Utils.enumAdType.MoreApps) {
    moreAppsButton.SetActive (false);
  }
}
 
void MoreAppsButtonOnClick()
{
  Gamedock.Instance.PlayMoreApps();
}
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->

## Checking if an ad is available

You can also directly check if an ad is available by using the following code:

<!-- tabs:start -->

#### ** Unity **

~~~C#
bool isBannerAvailable = Gamedock.Instance.IsAdAvailable(EnumAdType.Banner);
bool isInterstitialAvailable = Gamedock.Instance.IsAdAvailable(EnumAdType.Interstitial));
bool isRewardedVideoAvailable = Gamedock.Instance.IsAdAvailable(EnumAdType.RewardVideo));
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->