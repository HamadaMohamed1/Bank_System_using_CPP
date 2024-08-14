#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "Enter FirstName: " << endl;
        User.FirstName = clsInputValidate::ReadString();

        cout << "Enter LastName: " << endl;
        User.LastName = clsInputValidate::ReadString();

        cout << "Enter Email: " << endl;
        User.Email = clsInputValidate::ReadString();

        cout << "Enter Phone: " << endl;
        User.Phone = clsInputValidate::ReadString();

        cout << "Enter Password: " << endl;
        User.Password = clsInputValidate::ReadString();

        cout << "Enter Permessions: " << endl;
        User.Permissions = _ReadPermessionsToSet();
    }

    static void _PrintUserCard(clsUser User)
    {
        cout << "******************************************************************" << endl;
        cout << "                          User Card                             " << endl;
        cout << "******************************************************************" << endl;
        cout << "User Name      : " << User.GetUserName() << endl;
        cout << "Full Name      : " << User.GetFullName() << endl;
        cout << "Email          : " << User.GetEmail() << endl;
        cout << "Phone          : " << User.GetPhone() << endl;
        cout << "Password       : " << User.Password << endl;
        cout << "Permissions    : " << User.Permissions << endl;
        cout << "******************************************************************\n" << endl;
    }

    static int _ReadPermessionsToSet()
    {
        int permessions = 0;
        char answer;
        cout << "Do you want to give full access ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions = -1;
            return permessions;
        }

        cout << "Do you want to give access to :" << endl;

        cout << "Show Client Lists ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pListClients;
        }

        cout << "Add New Client ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pAddNewClient;
        }

        cout << "Delete Client ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pDeleteClient;
        }

        cout << "Find Client ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pFindClient;
        }

        cout << "Update Client ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pUpdateClient;
        }

        cout << "Transactions ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pTransactions;
        }

        cout << "Manage Users ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pManageUsers;
        }

        cout << "Show Login Register Screen ? y/n" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permessions += clsUser::enPermessions::pLoginRegister;
        }

        return permessions;
    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("   Update User Screen");
        string UserName = "";
        cout << "Please Enter UserName: " << endl;
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUserCard(User);

        cout << "\n\nUpdate User Info:";
        cout << "\n____________________\n";

        _ReadUserInfo(User);

        clsUser::enSaveResults SaveResult;

        SaveResult = User.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Updated Successfully :-)\n";
            _PrintUserCard(User);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }

        }
    }

};

