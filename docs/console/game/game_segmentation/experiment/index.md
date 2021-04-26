## Experiments

## Content

- [Table listing](#table-listing)
- [See experiment variant](#see-experiment-variant)
- [Create experiment](#create-experiment)
- [Edit experiment](#edit-experiment)
- [Deactivate experiment](#deactivate-experiment)

## Table Listing

- **Experiment** Experiment id
- **Start** Experiment Start date
- **End** Experiment End date
- **Activated** If it's activated
- **Running** If it's running

## See Experiment variant

1. Click on a row
2. A table listing for that particular experiment will appear:
    - **Table Listing**
        - ***Variant*** Variant type name
        - ***Traffic*** Traffic percentage for this variant. This should be the same for all    variants and cannot be updated anymore
        - ***Segment*** Users will be selected from this segment.
        Should be the same for all variants of a single experiment.
    - **Create experiment variant**
        1. Click **Create experiment variant**
        2. A Create experiment variant modal will appear:
            - **Variant type**
            - **Traffic**
            - **Segment**
        3. Click **Save** to store changes
    - **Edit experiment variant**
        1. Click **Edit experiment variant** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button on the selected row
        2. An Edit experiment variant modal will appear:
            - **Variant type**
            - **Traffic**
            - **Segment**
        3. Click **Save** to store changes
    - **Remove experiment variant**
        1. Click on **Remove experiment variant** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button 
        2. You will be prompted to confirm your action
        This action will delete the experiment variant. Deletion is permanent.

## Create Experiment

1. Click **Create experiment**
2. A Create Experiment modal will appear with the following:
    - **Name** Experiment name
    - **Start date** Experiment Start date
    - **End date** Experiment End date
    - **Only new users** If it's only for new users
    - **Metrics** Selected metrics for the experiment
    - **Dimensions** Selected dimensions for the experiment
3. Click **Save** to store changes

## Edit Experiment

1. Click **Edit experiment** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button on the selected row
2. An Edit Experiment modal will appear with the following:
    - **Name** Experiment name
    - **Start date** Experiment Start date
    - **End date** Experiment End date
    - **Only new users** If it's only for new users
    - **Metrics** Selected metrics for the experiment
    - **Dimensions** Selected dimensions for the experiment
3. Click **Save** to store changes

## Deactivate Experiment

1. Click on **Deactivate experiment** ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) button 
2. You will be prompted to confirm your action
This action will delete the experiment variant. Deletion is permanent.