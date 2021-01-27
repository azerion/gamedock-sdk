# Create Push Notification

In this page you can create new Push Notifications

## Contents

### Name

The name should be something detailed and meaningful that will help the users identify/search the specific push
notification.

### Min/Max inactive days

This defines the minimum and maximum days a user should be inactive to receive the push notification.

e.g. you want to send to the users that are inactive from three to five days a notification that says “Don’t give up so
easily!” and to the users that are from seven to fifteen days a different one that says “We miss you (”

> The reason that this is a range and not just a single number is that if it was a single number it would be either “exactly”
> or “above of”, where in the first case the notifications would be sent to the users that match the inactivity at the
> moment the notification is being sent, and in the second case it would send it to almost all inactive users,
> both of the cases defeat the purpose in both the examples that we gave above.

### Test group id

If set, the notification will be sent only in the specific test group.

### Platforms

Here you can set the platforms and version range that the notification should be targeted to. An empty version would be
handled as "any".

### Notification Data

JSON data that will be sent along with the notification. This data can be read by the game when the notification is
received.

### Messages

Here you can add the content of the notification. You can set different content per locale.

#### The message form

##### Locale

The target locale.

##### Title

The title of the notification.

##### Body

The body of the notification, on Android devices, if the body exceeds 35 characters, the notification will be
expandable.

##### Type

There are three types of notifications Normal, Custom, and with image.

###### Normal

The default notification style.

###### Custom

Here you can set the background image and also the text color (black or white), make sure to choose a background-text
color combination that would make enough contrast with the background for users to be able to read it.

###### With Image

Here you can set an image to show along with the notification, this is different from the custom, since in the custom
option the image is a background

### Schedule type

There are two types of schedules, repeating and one-time in both cases you can add multiple schedules - but all of them
of the same type - you can also enable/disable schedules individually.

#### Repeating

The repeating schedules are sent periodically depending on the frequency that is set to the schedule.

##### Date Range

The date range in which the notification schedule will be active. Here you can also set if the range is in users local
time or UTC.

##### Send time

The time that you want to send the push notification to the user, you can set the time in fifteen minute intervals.

##### Frequency

You can set the frequency to Daily, Weekly - where you can also choose which days of the week, and Monthly - where you
can choose which days of the month.

#### One Time

The one time schedules are sent to the user a single time at the defined time, here you can also define if it will be
send on local or UTC time.

> #### About “Users Local Time” and UTC
> Let’s say that we set the notification to be sent at 17:00, if it is to be sent at “Users Local Time”, then the users
> will get the notification when it is 17:00 in their country/time zone, if it is to be sent at UTC, all the users all
> over the world will get the notification at the same time when it is 17:00 UTC - you will probably wake up some people.
