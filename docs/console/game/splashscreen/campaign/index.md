## Campaign

This page shows the different campaigns created for the game

## Content
- [Table listing](#table-listing)
- [Create campaign](#create-campaign)
- [Edit campaign](#edit-campaign)
- [Testing devices](#testing-devices)
- [Remove campaign](#remove-campaign)


## Table Listing

- **Name** Campaign name
- **Enabled** If it's enabled or not
- **Status** Status of the campaign, finished or running
- **Creative** Creative that it's been used by the campaign 
- **Start Date** Campaign Start Date
- **End Date** Campaign End Date
- **Timezone** Localtime or UTC time zones
- **Platforms** Campaign available for the listed platforms

## Create Campaign
1. Click on **Create campaign**
2. A Create new campaign form will appear with the following fields:
    - **Name** Name of the new campaign. This is mandatory
    - **Enabled** Check for enabling the campaign
    - **Creative** The Creative template the campaign will use
    - **Start Date** Campaign Start Date
    - **End Date** Campaign End Date
        -***Check for UTC*** - Note that you can set in the dropdown the send parameter to use user's local time or UTC time
    - **Delay** Splashscreen from the campaign will not be shown for this period
    - **Delay unit** The time unit for the delay. This can range from second to month
        -***Show on game demand*** - Note that you can set in the dropdown if the campaign will be shown immidiately or on game demand
    - **Priority** Set the priority whenever multiple splashscreens are triggered at the same time
    - **Platforms** Different platforms and version ranges where the campaign will be included
    - **Rule groups** Move the rule groups to the Selected panel for filtering the campaign by available Rule groups
    - **Triggers** Triggers can be added by clicking on **Add Trigger** button and selecting an event from the dropdown and a condition
    - **Entity triggers** Entity triggers can be added by clicking on **Add Entity Trigger** and selecting the type of entity, the selected entity, and the conditions for the trigger
    - **Conditions** Conditions can be added by clicking on **Add Condition** and selecting the different parameters for the condition

3. Click on **Save** to store the changes

## Edit Campaign

1. Click on **Edit campaign** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button on the selected row
2. An Edit campaign form with the following fields will appear:
    - **Name** Name of the new campaign. This is mandatory
    - **Enabled** Check for enabling the campaign
    - **Creative** The Creative template the campaign will use
    - **Start Date** Campaign Start Date
    - **End Date** Campaign End Date
        -***Check for UTC*** - Note that you can set in the dropdown the send parameter to use user's local time or UTC time
    - **Delay** Splashscreen from the campaign will not be shown for this period. This is the delay the server will take to resend the splashscreen
    - **Delay unit** The time unit for the delay. This can range from second to month
        -***Show on game demand*** - Note that you can set in the dropdown if the campaign will be shown immidiately or on game demand
    - **Priority** Set the priority whenever multiple splashscreens are triggered at the same time
    - **Platforms** Different platforms and version ranges where the campaign will be included
    - **Rule groups** Move the rule groups to the Selected panel for filtering the campaign by available Rule groups
    - **Triggers** Triggers can be added by clicking on **Add Trigger** button and selecting an event from the dropdown and a condition
    - **Entity triggers** Entity triggers can be added by clicking on **Add Entity Trigger** and selecting the type of entity, the selected entity, and the conditions for the trigger
    - **Conditions** Conditions can be added by clicking on **Add Condition** and selecting the different parameters for the condition

     On the right side of the screen you can see the Campaign performance for last week

## Testing devices
1. Click on **Testing devices** ![device](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/device.png) button on the selected row
2. A popup will appear. Click on **Add Testing Device**
3. Select device from dropdown and check the desired parameters for testing purposes
4. Repeat operation to add the desired number of testing devices
5. Save to store your changes

## Remove Campaign
1. Click on **Remove campaign** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button 
2. You will be prompted to verify your action
   This action will delete the campaign. 