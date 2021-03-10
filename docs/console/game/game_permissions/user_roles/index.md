# User Roles

This page shows the existing User Roles defined. Listing the user email, a set of roles and potentially inherited roles.


## Contents
- [Table listing](#table-listing)
- [Create a new User Role](#create-a-new-user-role)
- [Edit a User Role](#edit-a-user-role)
- [Delete a User Role](#delete-a-user-role)


## Table listing

This table lists the following data for the all the User Roles defined for the selected game:

- **Uid** The unique Id of the user - This is based on the email
- **Roles** Roles assigned to the user
- **Inherited Roles** Inherited roles

## Create User Role

To create a new User Role:

1. Click on the button **Create new**.
2. A modal will appear with the create Game Config form, the form contains the following fields:
    - **email**: User mail used as identifier
    - **Game Role**: The different roles available in the system. They are as follows:"
      - **Gamedock Admin**: Admin role for selected game
      - **Game Owner**: Owner role for selected game
      - **Game Editor**: Editor role for selected game
      - **Game Viewer**: Viewer role for selected game
      - **Custom**: Custom permissions per section :
          - **Sections**:
            - Game Options
            - Content
            - Monetization
            - Users
            - Reporting
            - Marketing
            - Corporate
            - Release Management

            with two levels of access: 
        - ***Viewer***, with only permission to view data
        - ***Editor***, that has permission to edit the data

Please note that a user with Editor role has also by default Viewer role included

## Edit a User Role

At the right, on the action column, click the **Edit User roles** ![pencil](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/pencil.png) button for the row to edit, a modal will appear with the edit user roles form. The form has the same fields than Create User roles

## Delete a User Role

To delete the roles and permissions associated to a user:
1. Clock on the **Remove User Roles** button ![trash](https://github.com/azerion/gamedock-sdk/raw/master/docs/console/_images/trash.png) 
2. You will be prompted to verify your action.
This action will delete all the User Roles for the selected user. Deletion is permanent.
