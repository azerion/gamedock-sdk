# Events
On this page you can configure global events. These events can be used by all games. Some of them are called by the SDK automatically some have to be integrated manually in the game (this is reflected in the field integration).
Next to creating the event you can set various properties by clicking on a row, which will expand the extra option to the right (Setting up what services to call, in which SDK versions this event is applicable) and below (Setting properties of the event) the table.

## Contents
- [Create an event](#create-an-event)
- [Edit an event](#edit-an-event)
- [Remove an event](#remove-an-event)
- [Add an event service](#add-an-event-service)
- [Change the order of services](#change-the-order-of-services)
- [Enabling/Disabling services](#enabling-disabling-services)
- [Remove a service](#remove-a-service)
- [Add an SDK version](#add-an-sdk-version)
- [Edit an SDK version](#edit-an-sdk-version)
- [Remove an SDK version](#remove-an-sdk-version)
- [Add a property](#add-a-property)
- [Edit a property](#edit-a-property)
- [Remove a property](#remove-a-property)
- [Publish events to consul](#publish-events-to-consul)

### Create an event
To create an event:
1. Click on the button **Create event**
2. Fill in the Name, Description, Integration and Publish
3. Click **Save**

#### What's next?
After creating an event you may want to set up further configuration like service, sdk versions and properties for this event or publish the event to consul and make it effective on production. You can find this documentation below.

### Edit an event
To edit an event:
1. Find the event that you want to edit in the list of events (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. Click the ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for that row
3. A pop-up will show in which you can edit the values for your event
4. When done press **Save**

### Remove an event
Before removing an event you have to make sure all linked other entities (services, version and property information) are deleted.
To remove an event:
1. Find the event that you want to remove in the list of events (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. Click the ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button for that row
2. Confirm that you want to remove the event in the pop-up

### Add an event service
If you add a service to an event the event will be routed to the service. This should only be used by backend developers as they know where the event can be routed to.
To add an service:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. Click on the button **Create event service**
3. Pick the service that you want to send this event to
4. Click **Save**

### Change the order of services
To move an event service:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as Services find the platform you want to reorder
3. Click and hold the ![move](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/move.png) and drag the row up/down the list
4. Release the mouse button when the row is in the position where it should be

### Enabling/Disabling services
To enable/disable an event service:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as Services find the service you want to enable/disable
3. Click the ![remove-circle](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/remove-circle.png) or ![ok-circle](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/ok-circle.png) button for that row
4. Confirm that you want to enable/disable the service by clicking ok on the confirmation pop-up

### Remove a service
To remove an event service:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as Services find the service you want to delete
3. Click the ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button for that row
4. Confirm that you want to remove the event service in the pop-up

### Add an SDK version
Adding an SDK version will make the event only applicable for these specific SDK version. Leaving the list empty will make the event applicable for all versions.
To add an SDK version:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. Click on the button **Create event sdk version**
3. Pick the sdk version that you want this event to be applicable to
4. Click **Save**

### Edit an SDK version
To edit an SDK version:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as SDKs find the platform you want to edit the version from
3. Click the ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for that row
4. A pop-up will show in which you can edit the platform, from version and to version for your SDK version
5. When done press **Save**

### Remove an SDK version
To remove an SDK version:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as SDKs find the platform you want to delete the version from
3. Click the ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button for that row
4. Confirm that you want to remove the SDK version

### Add a property
Adding a properties will enable the backend to verify the new event. All properties that are being sent should be present for documentation reasons and to ensure consistency among games.
To add a property:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. Scroll down to find and click on the button **Create event property**
3. Fill in the fields and when done click **Save**

### Edit a property
To edit a property:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as properties on the bottom of the page find the property that you want to edit
3. Click the ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for that row
4. A popup will show in which you can edit the details of the property
5. When done press **Save**

### Remove a property
To remove a property:
1. Find the event that you want to edit in the list of events and click the row (by using the search button ![search](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/search.png) on the top left for example)
2. In the list labeled as properties on the bottom of the page find the property that you want to remove
3. Click the ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button for that row
4. Confirm that you want to remove the property in the pop-up

### Publish events to consul
Publishing events to consul means pushing the changes you made through editing to service-native-events, the service responsible for validating events that come in from the client. This is split off in a different function, as the changing of consul means that all servers restart
To publish the events to consul:
1. Check if all the changes listed on the page make sense to you, else find the editor and ask him/her if their changes can be applied
2. When sure click the button with three dots next to the **Create event** button
3. Select **Publish to consul** from the drop down
4. A confirmation pop-up will appear, confirm by clicking ok

#### What's next?
After publishing you should monitor native events logs for errors that may relate to the changes that were just published to consul.