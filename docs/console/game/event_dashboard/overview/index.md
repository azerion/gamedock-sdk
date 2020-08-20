# Overview
On this page you can see an overview of which events have been sent in a period of time. The listing will show the last occurance of the event and how many times this event has been sent.

## Contents
- [Viewing the overview](#viewing-the-overview)
- [Explanation of columns](#explanation-of-columns)

### Viewing the overview
To view the overview for a device:
1. Check the statusses you want to see (most of the time you will want all)
2. Select the daterange and the device you want to see
3. Press the **Save** button
4 You'll now see events that have been sent in the period in the table below, more on that.

### Explanation of columns
There are some columns that may not be clear intially. See the columns and what their value means below:
* Event: the name of the event
* Configured: when false it indicates that this is an event that games should manually configure in the game's event page.
* Status: there are three statusses: 
    * OK indicates everything was ok
    * WARNING indicates the event had to be altered or something wasn't alright during event validation but the event still could be sent through
    * ERROR the event had serious validation issues and was dropped because of that, error events should always be checked as these events won't get anywhere in the system
* Validation result: the result of the validation, this gives more insight if the status was not OK
* Total: total amount of events received in the given timeframe
* Last seen: when was the event last seen
* Action: in the action field is an info button, when pressed it'll pop up a window with the event and its response
