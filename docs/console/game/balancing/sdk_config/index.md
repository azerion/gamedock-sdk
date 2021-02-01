# SDK Config

This page shows the existing SDK Configurations. In this page you can create a new SDK config or
edit/activate/duplicate/view/remove an existing one. SDK configs that are already been active cannot be edited or
removed.

## Contents

- [Table listing](#table-listing)
- [Create new SDK Config](#create-new-sdk-config)
- [Edit SDK Config](#edit-sdk-config)
- [Remove SDK Config](#remove-sdk-config)
- [Activate SDK Config](#activate-sdk-config)
- [Create new based on this](#create-new-based-on-this)

## Table listing

This table lists the following data for the all the SDK configs that exist for the selected platform/version/segment
combination:

- **Id** The unique Id of the SDK Config - This is given automatically
- **Last updated by** The user that did the last update on that config
- **Last updated at** The date of the last update
- **Last status change at** The date of the last status change (activated/deactivated)

## Create a new SDK Config

To create a new SDK Config:

1. Click on the button **Create new**.
2. A modal will appear with the create SDK Config form, the form contains the following fields:
    - **platform**: The platform that this SDK Config will target.
    - **version**: The version that this SDK Config will target - which means this version and all versions above it that
      don't already have an active SDK Config.
    - **segment data**: The segment that this SDK Config will target.
    - **config**: The actual config as JSON.

## Edit a SDK Config

At the right, on the action column, click the **Edit SDK
Config** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for the
row to edit (if the button is not there it means that said Config was already activated and thus cannot be edited
further), a modal will appear with the edit SDK Config form, the form has the following fields:

- **config**: The config as JSON.
- **new keys**: In the case that the SDK config template has new keys that may have to be added, this multiselect field
  will be visible and populated with the missing keys. Once a key is moved to the right column, the JSON will be updated
  with the appropriate keys and values. Moving them again on the left will undo this action - depending on the key, you
  may or may not have to set the value.

## Remove a SDK Config

At the right, on the action column, click the **Remove SDK
Config** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/trash.png) button to remove
it. You will be prompted to verify this action. Removal is permanent.

## Activate a SDK Config

At the right, on the action column, click the **Activate SDK
Config** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/ok-circle.png) button to
activate it, or the **Deactivate SDK
Config** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/remove-circle.png)
button to deactivate it.

There can be only one SDK Config activated per platform/version/segment combination. Once activated, an SDK config
cannot be deactivated, you can only activate another SDK config instead. The currently active SDK config would be marked
green.

## Create a new SDK Config based on existing one

At the right, on the action column, click the **Create new based on
this** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/duplicate.png) button. A popup
will appear with the cloning form, here you can choose a new version and segment data, you are also able to do config
changes at this point. 
