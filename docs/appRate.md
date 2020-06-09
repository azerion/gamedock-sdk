# App Rate Popup

If you want to engage with the player and ask him for feedback and reviews for your game, you can do so using the Gamedock SDK. By using the App Rate Popup functionality the user will see a popup where he can review your game. The following features are available:
 * Android:
    * A native popup will appear that has the banner image used from the native privacy policy popup (if you need to change that image check that section).
    * If the user selects 3 stars or below, he will be redirected to the supplied feedback url.
    * You can decide after how many times the method has been triggered, that the pop up is shown (by default that is 3).
    * The user can choose to review the game later or never. If the user choose later, you can decide after how many times the method has been triggered to show again the review (by default that is 6).
    * The pop up is not localized by default, so you will need to manage all the text in it. The text that can be set is for the reject button, the later button and the message towards the use.
 * iOS:
    * It will use the built in app rate popup provided by Apple. You can find more information about it here: [https://developer.apple.com/design/human-interface-guidelines/ios/system-capabilities/ratings-and-reviews/](https://developer.apple.com/design/human-interface-guidelines/ios/system-capabilities/ratings-and-reviews/)

## Opening the App Rate Popup

The following method is available to display the App Rate Popup:

<!-- tabs:start -->

#### ** Unity **

~~~csharp
//Show App Rate Popup
Gamedock.Instance.ShowAppRatePopup(string rejectText, string laterText, string message, string feedbackUrl, int triggerCount = 3, int laterCount = 6);
~~~

#### ** AIR **

~~~actionscript

~~~

#### ** Cordova **

~~~javascript
//Show App Rate Popup
gamedockSDK.showAppRatePopup(rejectText, laterText, message, feedbackUrl, triggerCount, laterCount);
~~~

<!-- tabs:end -->
