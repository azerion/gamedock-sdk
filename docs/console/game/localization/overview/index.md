# Localization Overview
This page lists all enabled languages for a particular game. 
Per language, the list contains: The game locale code for that language, 4 columns detailing the number of translations that are accepted, drafted, localized and not localized.
Clicking on each cell will get you to the Localization Value listing for that pair of locales.
Lastly a column showing if any change on translation that has been accepted is not published yet.

There are two action buttons, one for publishing a locale, and another for showing information related to that published locale.

A functionality for importing and exporting a locale translation, in CSV format, is also available.

Selecting several rows will allow you to export and publish multiple locales at the same time

## Contents
- [View Translation Status](#view-translation-status)
- [Publish a Locale](#publish-a-locale)
- [Show Locale details](#show-locale-details)
- [Import Locale](#import-locale)
- [Export Locale](#export-locale)
- [Publish several Locales](#publish-several-locales)
- [Unpublished Changes](#unpublished-changes)


### View Translation Status
The data table renders the listing of the Localization Values per Locale as **badge links** ![badge-link](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/badge-link.png) .
Clicking each link will show the Localization Values view for the row's Locale, filtered by the status clicked


### Publish a Locale
Publishing a Locale will make it ready for being retrieved by the game.
To Publish a Language Locale:
1. Click on the action button **Publish Locale** ![ok-circle](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/ok-circle.png) for the Locale to be published
2. Click **Ok** on the confirmation modal that follows

### Show Locale details
1. Click on the action button **Info** ![info-sign](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/info-sign.png)
2. A popup will show details for the Locale published including a link to the actual translation JSON file

### Import Locale
For importing a locale, you'll need to have the data in CSV file with the following format:
**`localization_key, source_locale, target_locale, Description, String Length`**

File example: 
- row 0 : `localization_key, en_US, es_ES, Description, String Length`
- row 1 :`ShopTitleText, Shop, Tienda, Title for the Shop, 25`
- row 2 :`ShopCaptionText, Wonderful Shop, Maravillosa Tienda, Caption for the Shop Header Image, 50`
- row 3 :`ShopButtonBuyText, Buy, Comprar, Buy button on the Shop, 25`
- row 4 : etc...


1. Click on the three vertical dots on the right top to reveal the **Import Localization** option and click it
2. On the popup click **Select File** and select a .csv file
3. If there's no error (shown on the popup), click on **upload** and the file will be imported. Please note that if the locale is not enabled, it will be enabled automatically
4. You will need to refresh the page to view the changes on the table listing

### Export Locale
1. Select, using the checkboxes ![checkbox](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/checkbox.png) on the left, the rows for each Locale you want to export
2. Click on the button **Export Selected Languages** that appears on the top when selecting rows
3. Click **Ok** on the confirmation modal that follows
4. A .ZIP file containing one or several .CSV files (one .CSV per Locale selected for exporting) will be prompted to download. 

### Publish Several Locales
1. Select, using the checkboxes ![checkbox](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/checkbox.png) on the left, the rows for each Locale you want to publish
2. Click on the button **Publish selected** that appears on the top when selecting rows
3. Click **Ok** on the confirmation modal that follows

### Unpublished Changes
In case a Locale has an accepted value that has been changed but it is not published, it will be reflected here with a warning icon ![warning-sign](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/warning-sign.png). It is recommended to publish the Locale in order to see these changes reflected on the localization.