# Handling Errors

The Gamedock SDK sends a multitude of error messages to the different error callbacks that reside in each of the SDK features. In order to have a better understanding of where the SDK might fail, a list is provided below for each of the feature callbacks. The list only specifies the callbacks that have associated with them an Error Code.

The Error Code object can be found in the Gamedock SDK under the name **GamedockErrorMessage** and contains the following elements:
* Id – The Id of the error code that is associated with. This Id is unique for each Error Code
* Name – The name of the Error code
* Message – A human readable message explaining what the error is about

## Error Code List

~~~
OnUserDataError
  • LoadFailed(1, "LoadFailed", "Data container is empty!")
  • ItemNotFound(2, "ItemNotFound", "Item does not exist!")
  • CurrencyNotFound(3, "CurrencyNotFound", "Currency does not exist!")
  • BundleNotFound(4, "BundleNotFound", "Bundle does not exist!")
  • WalletNotFound(5, "WalletNotFound", "No wallet data stored!")
  • InventoryNotFound(6, "InventoryNotFound", "No inventory data stored!")
  • NotEnoughCurrency(7, "NotEnoughCurrency", "Not enough balance for currency!")
  • ItemAmountToLow(8, "ItemAmountToLow", "Could not remove item as amount is too low!")
  • CurrencyOperation(9, "CurrencyOperation", "Error updating wallet!")
  • ItemOperation(10, "ItemOperation", "Error updating item to player inventory!")
  • BundleOperation(11, "BundleOperation", "Error adding bundle to player inventory!")
  • PublicGameStateOperation(12, "UserIdMissing", "Error adding public game state data! A custom user id must be set in order to save public game state data")
  • GameStateOtherUsersServerError(13, "OtherUsersGameStateError", "Error when loading provided user id's game states from the server")
  • GachaOperation(30, "GachaOperation", "Error opening gacha!")
  • NotEnoughGachaBoxes(31, "NotEnoughGachaBoxes", "Not enough gacha boxes in the inventory!")
  • UserDataServerError(38, "UserDataServerError", "Error retrieving user data from server (gameState and playerData)!")
  • UserDataResetError(41, "UserDataResetError", "Error while resetting user data. This may be caused by loss of internet connection.")
  • UniqueItemAdd(45, "UniqueItemAdd", "Unable to add unique item to inventory because an item with the same unique id is present. Use Update or Remove methods first before trying again.");

OnConfigError
  • ConfigServerError(19, "ConfigServerError", "Error retrieving config")
  • ConfigResetError(39, "ConfigResetError", "Error while resetting game config. This may be caused by loss of internet connection.")

OnDailyBonusError
  • DailyBonusServerError(14, "DailyBonusServerError", "Error processing the reward from daily bonus")
  • DailyBonusLoadError(15, "DailyBonusLoadError", "Error loading the daily bonus page")

OnGameDataError
  • LoadFailed(1, "LoadFailed", "Data container is empty!")
  • ItemNotFound(2, "ItemNotFound", "Item does not exist!")
  • CurrencyNotFound(3, "CurrencyNotFound", "Currency does not exist!")
  • BundleNotFound(4, "BundleNotFound", "Bundle does not exist!")
  • GameDataServerError(20, "GameDataServerError", "Error retrieving game data")
  • GachaNotFound(29, "GachaNotFound", "Gacha does not exist!")
  • GameDataResetError(40, "GameDataResetError", "Error while resetting game data. This may be caused by loss of internet connection.")

OnLiveEventError
  • LiveEventServerError(25, "LiveEventServerError", "Error retrieving live event data")
  • LiveEventInvalidNextStage(26, "LiveEventInvalid", "Error validating live event next stage")
  • LiveEventMissingNextStage(27, "LiveEventMissingNextStage", "Error opening next stage due to missing data")
  • LiveEventLoadError(28, "LiveEventLoadError", "Error loading the live event page")

OnLoginFailed
  • InvalidSpilTokenError(32, "InvalidSpilTokenError", "Spil Token is invalid! Please login again!")
  • InvalidSocialTokenError(34, "InvalidSocialTokenError", "The provided social token could not be verified with the backend")
  • UserAlreadyLinkedError(35, "UserAlreadyLinkedError", "User already has a social provider account")
  • SocialIdAlreadyLinkedError(36, "SocialIdAlreadyLinkedError", "The social id is already linked to another user!")
  • SocialLoginServerError(37, "SocialLoginServerError", "Error communicating with the server!")

OnAuthError
  • InvalidSpilTokenError(32, "InvalidSpilTokenError", "Spil Token is invalid! Please login again!")
  • RequiresLoginError(33, "RequriesLoginError", "Event requires user login!")
  • SocialLoginServerError(37, "SocialLoginServerError", "Error communicating with the server!")

OnSplashScreenError
  • SplashScreenLoadError(16, "SplashScreenLoadError", "Error loading the splash screen")

OnImageLoadFailed
  • ImageLoadFailedError(17, "ImageLoadFailedError", "Error loading image")

OnRewardTokenClaimFailed
  • RewardServerError(18, "RewardServerError", "")

OnIAPServerError
  • IAPServerError(22, "IAPServerError", "Error communication with the server for IAP")

OnServerTimeRequestFailed
  • ServerTimeRequestError(24, "ServerTimeRequestError", "Error retrieving server time")
  
OnTieredEventsError
  • TieredEventShowProgressError(42, "TieredEventShowProgressError", "Unable to show tiered event progress.")
  • TieredEventUpdateProgressError(43, "TieredEventUpdateProgressError", "Unable to update the tiered event progress.")
  • TieredEventClaimTierError(44, "TieredEventClaimTierError", "Unable to claim the tier reward.")
~~~