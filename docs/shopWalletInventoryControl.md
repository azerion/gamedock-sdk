# Shop, Wallet & Inventory Control

> A wallet holds a user’s balance of the currencies (such as coins and diamonds) used within a game. An in-game shop is a facility that allows users to buy items, or bundles of items, with their game currency. For example, within a game, users might be able to buy a sword with 100 coins. Once bought, items are added to a user’s personal inventory.

### Understanding the Object Structures

This section describes the structure of the objects used within the Gamedock SDK to manage wallet, shop, and inventory functionality.

The requirements for the items shown in Table 5 must be defined by the Game’s producer. Once finalized, the Gamedock Account Manager will coordinate with Gamedock LiveOps to have them set up and managed within SLOT. Note that changes to any of these objects can only be made via SLOT, and not the Gamedock SDK.

Table 5: SLOT-Managed Objects

| Item         | Description                                                                                                                                                                                                                                                                                                                                                       |
|:-------------|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Currencies   | The currencies used in the game. For example, coins and diamonds. Each currency has an ID, a name, and a type (0 = Premium and 1 = Non-Premium).                                                                                                                                                                                                                  |
| Items        | The items used in the game. For example, a sword. Each Item has an ID, a name, and a type (0 = Consumable, 1 = Booster, and 2 = Permanent). Images, including a display name and a description, can also be defined for items. Also item properties can be added to an item.                                                                                      |
| Unique Items | Same as Items but they are non-stackable. A unique id is assigned to each Unique Item as well as it having Unique Properties that the game can modify.                                                                                                                                                                                                            |
| Gacha        | The gacha items used in the game. This collection contains a list of possible items that the user can get when trying to open the gacha each having it’s own weight. It acts in the same way as an item.                                                                                                                                                          |
| Bundles      | The bundles present in the game. A bundle is a collection of items. Each bundle has an ID, a name, a list of the items that will be gained by the player when they buy the bundle, and a list of one or more prices that relate to the currencies required for users to buy it. Imagines, including a display and a description, can also be defined for bundles. |
| Shop         | The tabs that the define the shop layout. Each tab contains a name, a position, and a list of entries. Each entry has a label that is displayed in the shop, a position, and one of more bundle IDs.                                                                                                                                                              |
| Promotions   | The promotions associated with the shop. Each promotion contains one or more bundle IDs which points to the received bundles, an amount value which represents the number of bundles in the promotion, an updated prices list, a discount label, and a start and end date. Items and bundles are described above.                                                 |

The objects shown in Table 6 are managed by the developer through the Gamedock SDK. Note that, in special cases, Gamedock Customer Support can also implement changes to a user’s wallet.

Table 6: SDK-Managed Objects.

| Item      | Description                                                                                                                                                                                                                                                                                      |
|:----------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Wallet    | Contains information about the user’s balance. It contains a list of currencies (that match the currencies defined in Table 1), a current balance, a delta, the game version being used, and a logic field which is either CLIENT or SERVER (currently, only CLIENT logic is fully implemented). |
| Inventory | Contains information about the current Items possessed by the user. It has the same structure as the Wallet object.                                                                                                                                                                              |

### Resetting Player Data

The Gamedock SDK provides the functionality to individually reset the player’s wallet or inventory. They are reset to the new player’s state. Alternatively, they can both be reset simultaneously. Use the following code:

~~~C#
// Reset the wallet data.
Gamedock.Instance.ResetWallet();

// Reset the Inventory data.
Gamedock.Instance.ResetInventory();

// Reset both wallet and inventory data.
Gamedock.Instance.ResetPlayerData();
~~~

Note that a user’s wallet information will be reset both locally (on the user’s device) and within SLOT. 

### Image Loading and Processing Support

The item and bundle objects defined for a game (see Table 5) can also contain images to be displayed inside your game. To download and display these images, use the following code: This page describes how the Gamedock SDK handles a users wallet an in-game shop and the user’s inventory. Wallet The wallet feature is holding a user’s virtual balance of a particular currency. E.g. the user has 100 coins in his wallet. A wallet can contain multiple currencies, e.g. coins and diamonds. In-game shop A user can buy items or bundles (a pack of multiple items) with his virtual currency. Let’s say a user can buy a sword with 100 coins. Inventory When a user bought an item in the in-game shop it will be added to his personal inventory.

## Implementation

If there is no network connection, then the SDK will use the latest known defaults. In exceptional cases, people will open the app for the first time and don’t have an Internet connection. For this specific case we need to add two defaults JSON files in the assets/streaming assets folder of the project: Add a file named ‘defaultGameData.json‘ in the assets/streaming assets folder of your project. Here is an example of a simple example file:

~~~JSON
{
  "items": [
      {
          "id": 1,
          "name": "Sword",
          "type": 0,
          "initialValue": 0,
          "imageUrl": "SOME_URL"
      }, {
          "id": 2,
          "name": "Shield",
          "type": 0,
          "initialValue": 0,
          "imageUrl": "SOME_URL"
      }, {
          "id": 3,
          "name": "Axe",
          "type": 0,
          "initialValue": 0,
          "imageUrl": "SOME_URL"
      }, {
          "id": 4,
          "name": "Spear",
          "type": 0,
          "initialValue": 0,
          "imageUrl": "SOME_URL"
      }
  ],
  "bundles": [
      {
          "id": 1,
          "name": "Sword",
          "prices": [
              {
                "currencyId": 1, 
                "value": 2
              }
          ],
          "items": [
            {
              "id": 1, 
              "amount": 1
            }
          ],
          "imageUrl": "SOME_URL"
      }, 
      {
          "id": 2,
          "name": "Shield",
          "prices": [
              {
                "currencyId": 1, 
                "value": 4
              }
          ],
          "items": [
            {
              "id": 2, 
              "amount": 1
            }
          ],
          "imageUrl": "SOME_URL"
      }, 
      {
          "id": 3,
          "name": "Weapons",
          "prices": [
              {
                "currencyId": 2, 
                "value": 50
              }
          ],
          "items": [
            {
              "id": 1, 
              "amount": 1
            }, 
            {
              "id": 3, 
              "amount": 1
            }, 
            {
              "id": 4, 
              "amount": 1
            }
          ],
          "imageUrl": "SOME_URL"
      }, 
      {
          "id": 4,
          "name": "Warior",
          "prices": [
              {
                "currencyId": 1, 
                "value": 20
              }
          ],
          "items": [
            {
              "id": 4, 
              "amount": 1
            }
          ],
          "imageUrl": "SOME_URL"
      }
  ],
  "currencies": [
      {
          "id": 1,
          "name": "Coins",
          "type": 0
      }, {
          "id": 2,
          "name": "Diamonds",
          "type": 1
      }
  ],
  "shop": [
      {
          "name": "tab1",
          "entries": [
              {
                  "bundleId": 1,
                  "label": "someLabel",
                  "position": 1
              }, {
                  "bundleId": 2,
                  "label": "someLabel",
                  "position": 2
              }
          ]
      }, {
          "name": "tab2",
          "entries": [
              {
                  "bundleId": 3,
                  "label": "someLabel",
                  "position": 1
              }, {
                  "bundleId": 4,
                  "label": "someLabel",
                  "position": 2
              }
          ]
      }
  ],
  "promotions": [
      {
          "bundleId": 1,
          "amount": 5,
          "prices": [{
              "currencyId": 1,
              "value": 100
          }],
          "discount": "20",
          "startDate": "2016-01-01 19:00:00",
          "endDate": "2016-01-01 20:00:00"
      }, {
          "bundleId": 3,
          "amount": 1,
          "prices": [{
              "currencyId": 1,
              "value": 100
          }],
          "discount": "50%",
          "startDate": "2016-01-01 19:00:00",
          "endDate": "2016-01-01 20:00:00"
      }
  ]
}
~~~

Add a file named ‘defaultPlayerData.json‘ in the assets/streaming assets folder of your project.
Here is an example of a simple example file:

~~~JSON

{
  "wallet":
    {
      "currencies":[
        {
          "id": 22,
          "currentBalance": 0,
          "delta": 0
        },
        {
          "id": 13,
          "currentBalance": 0,
          "delta": 0
        }
      ],
      "offset": 0,
      "logic": "CLIENT"
    },
  "inventory":
    {
      "items":[
      ],
      "offset":0,
      "logic": ""
    }
}
~~~

The Gamedock Unity classes “GamedockGameDataHelper.cs” and “PlayerDataHelper.cs” contain all methods for the wallet, in-game shop and inventory features. These classes are instantiated on “Awake ()” in the “Gamedock.cs” file and automatically retrieve the data from the Gamedock SDK, so you can start using the methods immediately. See below code snippets to use the wallet, in-game shop and inventory features:

~~~C#
//Retrieving Gamedock Game Data
//List of currencies configured in SLOT
List<Currency> Currencies = Gamedock.GameData.Currencies;

//List of items configured in SLOT
List<Item> Items = Gamedock.GameData.Items;

//List of bundles configured in SLOT and that are used in the Shop
List<Bundle> Bundles = Gamedock.GameData.Bundles;

//Shop object that defines the configuration
Shop Shop = Gamedock.GameData.Shop;
//For Shop Entries, the type can be BUNDLE or PACKAGE
//Shop stickers can be found on each Shop Entry under the ImageEntries list
//Each image entry contains an URL to download the sticker image

//Getting a Currency, Item, Bundle or Gacha by ID or NAME
Gamedock.GameData.GetCurrency (ID);
Gamedock.GameData.GetCurrency (NAME);

Gamedock.GameData.GetItem (ID);
Gamedock.GameData.GetItem (NAME);

Gamedock.GameData.GetBundle (ID);
Gamedock.GameData.GetBundle (NAME);

Gamedock.GameData.GetGacha (ID);
Gamedock.GameData.GetGacha (NAME);

//Retrieve item properties
Dictionary<string,object> itemProperties = Gamedock.GameData.GetItem(49).Properties;

//Retrieving Player Data
Wallet Wallet = Gamedock.PlayerData.Wallet;
Inventory Inventory = Gamedock.PlayerData.Inventory;

//Getting the Current Balance for a given Currency ID
Gamedock.PlayerData.GetCurrencyBalance (ID);

//Getting the Item Amount for a given Item ID
Gamedock.PlayerData.GetItemAmount (ID);

//Check if an Item is present in the Player Inventory
Gamedock.PlayerData.InventoryHasItem (Item ID);

//Retrieve all the gacha the user has
Gamedock.PlayerData.GetGachas();

//Wallet Oprations
//Adding Currency to the User's Wallet
Gamedock.PlayerData.Wallet.Add (Currency ID, Amount, Reason, Location, ReasonDetails = null, TransactionId = null);
//Subtracting Currency to the User's Wallet
Gamedock.PlayerData.Wallet.Subtract (Currency ID, Amount, Reason, Location, ReasonDetails = null, TransactionId = null);
//Method to set an currency limit
Gamedock.Instance.SetCurrencyLimit(int currencyId, int limit);

//Inventory Operations
//Adding Item to the User's Inventory
Gamedock.PlayerData.Inventory.Add (Item ID, Amount, Reason, Location, ReasonDetails = null, TransactionId = null);
//Subtracting Item to the User's Inventory
Gamedock.PlayerData.Inventory.Subtract (Item ID, Amount, Reason, Location, ReasonDetails = null, TransactionId = null);
//Consuming a bundle
Gamedock.PlayerData.BuyBundle(Bundle ID, Reason, Location, ReasonDetails = null, TransactionId = null, List<PerkItem> perkItems = null);
//Opening a Gacha Item
Gamedock.PlayerData.OpenGacha(Gacha ID, Reason, Location, ReasonDetail = null, List<PerkItem> perkItems = null);
//Method to set an item limit
Gamedock.Instance.SetItemLimit(int itemId, int limit);

//Create Unique Item
//Be sure to check the "is unique" checkbox for your item in SLOT, this will make the item non-stackable and allows you to create unique items from it.
UniquePlayerItem uniqueItem = Gamedock.PlayerData.Inventory.CreateUniqueItem(itemId);
UniquePlayerItem uniqueItem = Gamedock.PlayerData.Inventory.CreateUniqueItem(itemId, uniqueId);

//Add Unique Item to the inventory
Gamedock.PlayerData.Inventory.AddUniqueItemToInventory(uniqueItem, reason, reasonDetails, location, transactionId);

//Update Unique Item from the inventory
bool hasUniqueItem = InventoryHasUniquePlayerItem(uniqueId);
UniquePlayerItem uniqueItem = Gamedock.PlayerData.Inventory.GetUniqueItem(uniqueId);
uniqueItem.uniqueProperties.Add("test", "test");
Gamedock.PlayerData.Inventory.UpdateUniqueItemFromInventory(uniqueItem, reason, reasonDetails, location, transactionId);

//Remove Unique Item from the Inventory
Gamedock.PlayerData.Inventory.RemoveUnqiueItemFromInventory(uniqueItem, reason, reasonDetails, location, transactionId);

//Method to request user data
Gamedock.Instance.RequestUserData();

//Method used to refresh the data from SLOT
Gamedock.Instance.UpdatePlayerData();

//Events to register to
Gamedock.Instance.GameDataCallbacks.OnGamedockGameDataAvailable -= OnGamedockGameDataAvailable;
Gamedock.Instance.GameDataCallbacks.OnGamedockGameDataAvailable += OnGamedockGameDataAvailable;

Gamedock.Instance.GameDataCallbacks.OnGamedockGameDataError -= OnGamedockGameDataError;
Gamedock.Instance.GameDataCallbacks.OnGamedockGameDataError += OnGamedockGameDataError;

Gamedock.Instance.UserDataCallbacks.OnPlayerDataUpdated -= OnPlayerDataUpdated;
Gamedock.Instance.UserDataCallbacks.OnPlayerDataUpdated += OnPlayerDataUpdated;

Gamedock.Instance.UserDataCallbacks.OnPlayerDataAvailable -= OnPlayerDataAvailable;
Gamedock.Instance.UserDataCallbacks.OnPlayerDataAvailable += OnPlayerDataAvailable;

//Callback invoked when an unique item is created as a result of a BuyBundle or OpenGacha operations
Gamedock.Instance.UserDataCallbacks.OnPlayerDataNewUniqueItem -= OnPlayerDataNewUniqueItem;
Gamedock.Instance.UserDataCallbacks.OnPlayerDataNewUniqueItem += OnPlayerDataNewUniqueItem;

Gamedock.Instance.UserDataCallbacks.OnUserDataError -= OnUserDataError;
Gamedock.Instance.UserDataCallbacks.OnUserDataError += OnUserDataError;

//List of Standard Reasons (you can pass your own reason as a String)
//Accessed through the Class "PlayerDataUpdateReasons"
RewardAds = "Reward Ads";
ItemBought = "Item Bought";
ItemSold = "Item Sold";
EventReward = "Event Reward";
LoginReward = "Login Reward";
IAP = "IAP";
PlayerLevelUp = "Player Level Up";
LevelComplete = "Level Complete";
ItemUpgrade = "Item Upgrade";
BonusFeatures = "Bonus Features";
Trade = "Trade";
ClientServerMismatch = "Client-Server Mismatch";
ItemPickedUp = "Item Picked Up";
DailyBonus = "Daily Bonus From Client";
Rush = "Rush";
Gift = "Gift";
Cancel = "Cancel";
Collection = "Collection";
Reset = "Reset";
InitialValue = "Initial Value";
~~~

## Reseting data

The SDK also provides the functionality to reset the player’s data, or just specifically the player’s Wallet and Inventory.

In order to reset the Wallet data use the following code:

~~~C#
Gamedock.Instance.ResetWallet();
~~~

In order to reset the Inventory data use the following code:

~~~C#
Gamedock.Instance.ResetInventory();
~~~

In order to reset the whole Player data use the following code:

~~~C#
Gamedock.Instance.ResetPlayerData();
~~~

## Item and Bundles Image Processing and Loading

The Items and Bundles objects provided by the SDK can also contain images that can be displayed inside your game. In order to download and display these images use the following information:

~~~C#
//Retrieve the image path for an item
//If it returns null the SDK will attempt to download the image in the background and call the listener when it has finished
string imagePath = item.GetImagePath();

//Retrieve the image path for an bundle
//If it returns null the SDK will attempt to download the image in the background and call the listener when it has finished
string imagePath = bundle.GetImagePath();

//Preload and download all the image information for the present items and bundles
//The specific listener will be called when all the images have been processed
Gamedock.Instance.PreloadItemAndBundleImages();

//The event listeners that you can subscribe to for image processing
Gamedock.Instance.ImageLoadingCallbacks.OnImageLoadSuccess;
Gamedock.Instance.ImageLoadingCallbacks.OnImageLoadFailed;
Gamedock.Instance.ImageLoadingCallbacks.OnImagePreloadingCompleted;

//If you have the imagePath for an image you can use this Gamedock method to load the Texture2D image
Gamedock.Instance.LoadImage(gameObject, imagePath, width, height, textureFormat, mipMap);

//The event listener for when the Texture2D image was loaded by Unity
Gamedock.Instance.ImageLoadingCallbacks.OnImageLoaded;

//Clear the local cache
Gamedock.Instance.ClearDiskCache();
~~~