# Games
This page contains a list of games that have been configured. Per game an id, Name can be set. Also the game can be linked to an Organization and a Franchise. Lastly the app identifier from the store needs to be configured per platform (BundleId for iOS, PackageName for Android).

## Contents
- [Create a game](#create-a-game)
- [Edit a game](#edit-a-game)
- [Hide/unhide a game](#hide-unhide-a-game)
- [Change the organization for a game](#change-the-organization-for-a-game)
- [Export games](#export-games)

## Create a game
To create a game:
1. Click on the button **Create Game**
2. Fill in the fields, Game Id allows lower case characters, numbers and underscore '\_'. The Android, Facebook, Ios, Webgl fields should contain the game identifiers for those platforms. If these are left empty we assume the game is not running on the given platform
3. Click the **Save** button to save your configuration

### What's next?
After creating a game the following steps should be taken:
* Create BI mapping
* Create an SDK config

You may want to consider:
* Creating a Game Config
* Request ad configuration from the advertising team

## Edit a game
To edit a game:
1. Find the game that you want to edit in the list of games
2. Click the ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for that row
3. A pop-up will now show up where you can edit various properties of the game (see create game for an explanation of the fields)
4. When done press **Save**


## Hide/unhide a game
The functionality to hide a game basically does not remove the game, but will remove it from game dropdowns within Gamedock Console (for example in the top bar). This feature is useful when a game is currently not maintained and is only hindering.
To hide/unhide a game:

1. Find the game that you want to hide/unhide in the list of games
2. Click the  ![eye-close](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/eye-close.png)</span> or ![eye-open](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/eye-open.png)</span> button for that row to hide or unhide the game repectively

## Change the organization for a game
To change the organization:
1. Find the game that you want to change the organization for in the list of games
2. Click the ![transfer](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/transfer.png) button for that row
3. A pop-up will show where you can select the new organization for the game
4. When done press **Save**


## Export games
Exporting games creates an export file of the games in the list.
To export the games to our services:
1. Click the button with three dots next to the **Create Game** button
2. Select **Export data**
3. A pop-up will show where you can configure what should be in your export, what columns
4. When done press **Export**
5. A csv file will be downloaded containing the configured data