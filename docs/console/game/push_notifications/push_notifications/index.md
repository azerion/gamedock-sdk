# Push Notifications

This page shows all the push notifications, both running and expired. From here you can create new notifications and
also edit, delete, activate, and deactivate them.

## Contents

- [Table listing](#table-listing)
- [Create Push Notification](#create-push-notification)
- [Edit Push Notification](#edit-push-notification)
- [Remove Push Notification](#remove-push-notification)
- [Activate/Deactivate Push Notification](#activatedeactivate-push-notification)

## Table listing

This table lists the following data for each Push Notification that exists:

- **Id** The unique Id of the Push Notification - This is given automatically
- **Name** The name that was given to the Push Notification

## Create Push Notification

To create a new Push Notification:

1. Click on the button **Create Push Notification**.
2. You will be navigated to the Push Notification creation page.

## Edit Push Notification

At the right, on the action column, click the **Edit push
notification** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for
the row to edit, you will be navigated to the edit page.

## Remove Push Notification

At the right, on the action column, click the **Remove push
notification** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/trash.png) button to
remove it. You will be prompted to verify this action. Removal is permanent.

## Activate/Deactivate Push Notification

At the right, on the action column, click the **Activate push
notification** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/ok-circle.png) button
to activate it, or the **Deactivate push
notification** ![trash](https://github.com/azerion/gamedock-sdk/blob/master/docs/console/_images/remove-circle.png)
button to deactivate it. Once deactivated, a Push Notification will keep all it's configuration but won't be pushed to
the users, it can then be activated at any point.

> **Adding users to Push Notification Groups**
>
> In order to add a user to a group, you would have to go to said users push notifications page in his profile
> (https://console.gamedock.io/game/sample/users/{UUID}/push_notifications/) and set this user to the group of your choice.