# Table Input Field
This page demonstrates GDC's `TableInput` fields.

## Usage
The TableInputField is a field that consists of a collection all fields, where the user is able to add miltiple rows of that collection.
A simple example would be a list of Virtual goods that are gifted by the DailyBonus.

## Implementation
All you have to do is create a Form with the fields that you want to be included and bind it to the TableInputField, then the TableInputField 
will use Django's formset and functionality and a ton of JavaScript to handle multiple instances of that form on both the backend and the frontend.

### The Widgets
There are five widgets that can be used with the TableInputField each have it's own design and functionality but all of them in the end would return the data in the same format.

#### TableInput
This is also the default template for the TableInputField, it shows the data in a table format and uses a modal window to show the add/edit forms, removing rows also happens upon 
saving the form which means that you can undo if you remove a row by accident.

#### RowInput
This widget does not support adding new rows and you can only edit the data of the existing rows.

#### InlineTableInput
In this widget every row is a self contained form that can be edit on the fly, very usefull if you have self explanatory fields and not very complicated conditional forms 
e.g. if the user has to enter an amount of some Virtual goods, then the form would consist of three drop downs "Virtual Goods type" -> "Instance" -> "Amount".

#### ExpandingTableInput
In this widget the forms are expandable on edit/create and when minized they show part of the forms data. It also supports ordering.

#### TableWithSideFormInput
This widget consists of a list all the saved data where by clicking on a row you get the form on the side.
