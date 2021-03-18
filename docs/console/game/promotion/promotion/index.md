# Promotions
On this page you see a list of existing campaign Promotions

## Content
- [Table listing](#table-listing)
- [Create promotion](#create-promotion)
- [Edit promotion](#edit-promotion)

## Table listing

- **Id** Promotion id
- **Enabled** If the promotion has been enabled or not
- **Status** The current status of the promotion: finished or running
- **Name** Promotion name
- **StartDate** Promotion start date
- **EndDate** Promotion end date

## Create promotion

To create a new promotion:

1. Click on **Create Promotion**
2. A modal will appear with the create promotion form, the form contains the following fields:
    - **Name** Name for the promotion
    - **Enabled** If it's going to be enabled
    - **Label** Label for the promotion
    - **Start Date** Start date for the promotion to be active
    - **End Date** End date for the promotion to be not active anymore
    - **Send at** Based on UTC or Users Local time
    - **Duration** Duration of the Promotion
    - **Duration unit** Unit for the duration of the Promotion
    - **Max purchases** Maximum amount that this promotion can be purchased
    - **Affected entities** The affected entities the promotion is aiming at
    - **Price override** Price override for the affected entities
    - **Extra entities** Extra entities that can be affected by the promotion
    - **Platforms** Platforms and versions where the promotion will be available
    - **Segment data** Segments where the promotion will be active
    - **Rule groups** Filter the promotion based on groups
    - **Conditions** Condition for triggering the promotion
3. Click save to store your changes

## Edit Promotion

To edit a promotion , click the **Edit Promotion** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button. A form will appear with the same fields than **Create promotion**, plus an option for Add Game Integration and an option to Create a Campaign based on the edited promotion.