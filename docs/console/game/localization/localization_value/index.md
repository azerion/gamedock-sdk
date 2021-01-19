# Localization Values
This page shows the Localization Values for each Localization Key per Locale.
You can select the Source Locale and the Target Locale to be displayed.
You can edit the draft value for a particular key in a Locale and also accept that value to change its status


## Contents
- [Table Listing](#table-listing)
- [Select Source/Target Locale](#select-source-target-locale)
- [Edit Localization Value](#edit-localization-value)
- [Accept Localization Value](#accept-localization-value)
- [Accept Several Localization Values](#accept-several-localization-values)


### Table Listing
This table lists the following data for each Localization Value that exists :
- **Key** : Localization Key (which is unique)
- **Source** : The **accepted value** from the selected **Source Locale** (This row will not be shown if the Source Locale and Target Locale are the same)
- **Draft** : the **Draft value** for the selected **Target Locale**, if any
- **Accepted** : The **Accepted value** for the selected **Target Locale**, if any

### Select Source/Target Locale
In order to be able to change a particular Locale you'll need to select them properly on the locale dropdown selectors
1. Select the Source Locale from the first Dropdown control at the top of the Table
2. Select the Target Locale from the second Dropdown control at the top of the Table
3. The Table will be rendered with the Localization Values based on the two Locales selected

### Edit Localization Value
1. At the right, on the action column, click **Edit localization value** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for the row to edit
2. On the popup , details for the selected Localization Key will be displayed:
	- Key 
	- Accepted value for the Target Locale selected (if any)
	- Draft Value an input field where the user can input the new value for the Draft of the Localization Value for the selected Key and Target Locale
	- Max length field that indicates the maximum characters length for the Localization Value for that Target Locale
3. Fill in Draft Value field and optionally Max Length field
4. Press **Save** to reflect the changes

### Accept Localization Value
If you want to accept a draft value and mark it as accepted value:

1. On the row where you want to accept the value, at the right, on the action column, click **Accept draft value** ![ok-circle](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/ok-circle.png)
2. On the confirmation popup that appears press **OK**.
3. It will accept the value and it will remove the contents of draft value

### Accept Several Localization Values
1. Select, using the checkboxes on the left, the rows for each Locale you want to accept
2. Click on the button **Accept selected** that appears on the top when selecting rows
3. Click **ok** on the confirmation modal that follows