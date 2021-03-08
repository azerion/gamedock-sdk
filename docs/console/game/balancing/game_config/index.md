# Game Config

This page shows the existing Game Configurations. In this page you can create a new Game config or
edit/activate/duplicate/view/remove an existing one. Game configs that are already been active cannot be edited or
removed.

## Contents
- [Table listing](#table-listing)
- [Create a new Game Config](#create-a-new-game-config)
- [Delete a version](#delete-a-version)
- [Edit a Game Config](#edit-a-game-config)
- [Remove a Game Config](#remove-a-game-config)
- [Activate a Game Config](#activate-a-game-config)
- [Create a new based on this:](#create-a-new-game-config-based-on-existing-one)

## Table listing

This table lists the following data for the all the Game configs that exist for the selected platform/version/segment
combination:

- **Id** The unique Id of the Game Config - This is given automatically
- **Last updated by** The user that did the last update on that config
- **Last updated at** The date of the last update
- **Last status change at** The date of the last status change (activated/deactivated)

## Create a new Game Config

To create a new Game Config:

1. Click on the button **Create new**.
2. A modal will appear with the create Game Config form, the form contains the following fields:
    - **platform**: The platform that this Game Config will target.
    - **version**: The version that this Game Config will target - which means this version and all versions above it that
      don't already have an active Game Config.
    - **segment data**: The segment that this Game Config will target.
    - **config**: The actual config as JSON.

## Delete a version

To delete the whole version of Game Config:
1. Click on the three dots on the top right of the panel
2. Click on "Delete this version"
3. You will be prompted to verify your action.
This action will delete all the Game Configs for the selected version. Deletion is permanent.
   
## Edit a Game Config

At the right, on the action column, click the **Edit Game
Config** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for the
row to edit (if the button is not there it means that said Config was already activated and thus cannot be edited
further), a modal will appear with the edit Game Config form, the form has the following fields:

- **config**: The config as JSON.

## Remove a Game Config

At the right, on the action column, click the **Remove Game
Config** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button to remove
it. You will be prompted to verify this action. Removal is permanent.

## Activate a Game Config

At the right, on the action column, click the **Activate Game
Config** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/ok-circle.png) button to
activate it, or the **Deactivate Game
Config** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/remove-circle.png)
button to deactivate it.

There can be only one Game Config activated per platform/version/segment combination. Once activated, an Game config
cannot be deactivated, you can only activate another Game config instead. The currently active Game config would be marked
green.

## Create a new Game Config based on existing one

At the right, on the action column, click the **Create new based on
this** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/duplicate.png) button. A popup
will appear with the cloning form, here you can choose a new version and segment data, you are also able to do config
changes at this point. 
