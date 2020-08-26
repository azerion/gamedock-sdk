# Live stream
On this page the events that have been sent to our system can be seen and evaluated. This happens through a live stream that almost directly shows events as they come into our system. 

## Contents
- [Starting up the live stream](#starting-up-the-live-stream)
- [Stopping/continuing the live stream](#stopping-continuing-the-live-stream)
- [Event list](#event-list)
    - [Statuses](#statuses)
    - [Event details](#event-details)
- [Testing with multiple devices](#testing-with-multiple-devices)

### Starting up the live stream
Before starting up the live stream you wil need to set up your device in the devices tab. If no devices have yet been set up the page will direct you there. Assuming you have set up your device starting the live stream is easy:
1. To start streaming press the **+** button
2. Select the device you want to track
3. The interface changes and you see the stream view
4. When sending events through the SDK, from the device on this game, you should now see them appear in the event list

### Stopping/continuing the live stream
To stop the live stream just click the **Listening** button on the right. To continue the stream press the same button that has now the **Play** text.

### Event list

#### Statuses
Events on the events list are marked in different colors. Green, orange (yellow in the list) and red. The color indicates if the event passed the event validation (ok, green), the event validation had minor issues which it could correct (warning, orange) or the event was not accepted and dropped (error, red). Note that errors are serious and should be investigated and builds containing them should be fixed before release.

On the top right is a pie chart that shows how many error, ok and warning events came in.

#### Event details
When clicking on an event in the event list on the right you will see the details of the event. It'll show the:
 * **Warnings** and **errors** that the event had
 * **Event** that was sent itself
 * **Response** that was sent back (if it is too long the data part may be shortened, but can be seen in the full response, except for responses to requestUserData where the gamestate part is removed before storing the event)
 * **Complete Event Data** which holds everything that was stored for this event, the event, the full response and the validation result. If in the **Response** part some data has been shortened it can be seen here. 

### Testing with multiple devices
On this page it is possible to perform tests on multiple devices at once.
At the top where you can select a device the **+** button will stay if multiple devices are added for the game, so you can keep adding more devices after you selected the first one.

When you are testing multiple devices the numbers next to the device name indicate how many occurances of the events were ok, warning and errors on **inactive** tabs. This is so you can easily see if one device fails where others succeed while testing.
