# Implementing Customer Support

The issue of customer support is an important aspect of games delivery. It is strongly recommended that you review its requirements with your Gamedock Account Manager as part of the initial engagement. Broadly, there are three strategies integrated into the Gamedock SDK for providing customer support for your games:
* An external website (such as Zendesk). Typically, this features a contact form and FAQs section. This approach may have additional operational costs associated with it.
* Zendesk Webview. Here, the help screen is shown as an overlay within the app and, typically, features a contacts form and FAQ section. It allows for the customization of the help screen. However, several limitations are associated with this implementation. For example, users may need to specify more form fields (such as user ID) because not all information can be passed to the customer support overlay.

Which of the above strategies you select depends on the nature of your game and its support requirements.

## Opening Zendesk Within Your Games

The following method is available:

<!-- tabs:start -->

#### ** Unity **

~~~C#
// Show Zendesk Support Center in a Web View 
Gamedock.Instance.ShowHelpCenterWebview(string url, string[] tags);
~~~

#### ** Android **



#### ** iOS **



<!-- tabs:end -->
