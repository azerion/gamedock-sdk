## User Data user details

This page shows the details of the user data store for a selected user

## Content
- [Search User](#search-user)
- [Select User Alias](#select-alias)
- [Create User Alias](#create-alias)
- [User Data](#user-data)

## Search User

1. Enter a UserID on the Uid field and click **Search**
2. **User Data** details will be displayed

## Select User Alias
1. Select the dropdown and click on the desired user alias
2. **User Data** details will be displayed
3. **Edit User Alias** When selecting an alias, clicking on **![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) Edit user alias** button will show a popup with the following:
    - ***Alias*** User alias 
    - ***Uid*** User ID
    - ***Notes*** Any notes associated to the user alias
4. **Remove User Alias** When selecting an alias, clicking on **![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) Remove user alias** button will show prompt a confirmation for deleting the alias

## Create User Alias
1. Enter a UserID on the Uid field and click **Search**
2. If that UserID does not have an alias associated, you can click on **Create user alias**
3. A create user alias form is displayed with the following:
    - ***Alias*** User alias 
    - ***Uid*** User ID
    - ***Notes*** Any notes associated to the user alias
4. Click **Save** to store changes



## User Data

This panel shows details relative to the User Data store for the searched UserID

- **Event Profile** List of events associated to the profile
- **User Profile** User profile details
- **Experiment status** 
    - Click on **Show User Segments** to see the User segments.
    - Click on **Add user to experiment** to open a popup for adding the user to an existing experiment:
        - ***Experiment*** Dropdown for selecting the experiment
        - ***Variant*** Dropdown for selecting the variant for the experiment
- **Wallet** Status of the user wallet
- **Inventory** List of Items and Unique items associated to the user
- **History** User history
- **Push Notifications** Push notifications data
- **Missions** Missions associated to the user
- **Private Gamestate** Game state saved for the user
- **Convert User** Transfer game progress from one Uid to another
- **Data** User data stored
- **Hashes** Hashes associated to the user
- **Social Account** Social account associated to the user
- **Daily Bonus** Daily bonus state associated to the user. Click **Set User State** to open a form for setting the user state:
    - ***PLatform***
    - ***Segment Data***
    - ***Days collected***
    - ***Last collected***

- **Public Gamestate** Public Game state stored for the user