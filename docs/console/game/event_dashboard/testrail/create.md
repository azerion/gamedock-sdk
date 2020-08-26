# Create Test Case
In this page you can create new Testrail test cases.

## Contents
- [What is a test case?](#what-is-a-test-case)
- [Title](#title)
- [Section Id](#section-id)
- [Steps](#steps)
    - [Creating/Editing a step](#creatingediting-a-step)
        - [Description](#description)
        - [SDK Method](#sdk-method)
        - [Event Name](#event-name)
        - [Event Data](#event-data)
        
        
### What is a test case?
A test case is a series of steps that have be done in order to complete the test case. Every step includes an event that have to be triggered with a specific set of data in order for the step to be considered complete.


### Title
A descriptive title of the test case

### Section Id
The section that the test case will belong to

### Steps
A list of the steps that the the Test Case consist from. You can add steps by clicking on the **Add Step** button, edit them by clicking on their name in the list, and remove them by pressing the bucket button next to them.

#### Creating/Editing a step
A step consists of:
* A Description
* An SDK Method
* An Event Name
* Event data

##### Description
The description should be a small description of the step, it should be enough to give details to the reader of the actions that they have to take.

##### SDK Method
The SDK Method that will be triggered on said action.

##### Event Name
The name of the Event that will be triggered after said action. After selecting the event, the form will change to include the relevant Event Data that are supported by the event.

##### Event Data
The data that the event needs to have in order for the event to be considered valid.
