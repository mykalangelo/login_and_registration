#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool IsLoggedIN()
{
    string username, password, un, pw;
    cout<<"Enter Username :";
    cin>>username;
    cout<<"Enter password :";
    cin>>password;
    ifstream read("C:\\Users\\sanju\\login_and_registration\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    
    }
}
int main()
{
    int choice;
    cout<<"1: Register\n2: Login\n Your choice:";
    cin>>choice;
    

    if (choice == 1)
    {
        string username, password;
        cout<<"Select a Username: ";cin>>username;
        cout<<"Select a Password: ";cin>>password;

        ofstream file;
        file.open("C:\\Users\\sanju\\login_and_registration\\" + username + ".txt");

        file << username << endl << password;
        file.close();
        main();
    }
    else if(choice == 2)
    {
        bool status = IsLoggedIN();
        if(!status)
        {
            cout<< "False Login!" << endl;
            system("Pause");
            return 0;
        }
        else
        {
            cout<< "Successfully logged in!"<<endl;
            system("Pause");
            return 1;
        }
        
    }
}