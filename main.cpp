#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isLoggedIn()
{
    string username, passwd, un, pw;  
    cout<<"Enter username: "; cin>>username;
    cout<<"Enter password: "; cin>>passwd;

    ifstream in1(".username.txt");
    ifstream in2(".passwd.txt");
    getline(in1, un);
    getline(in2, pw);
    in1.close();
    in2.close();

    if(username == un && passwd == pw)
        return true;
    else
        return false;
}

int main()
{
    int choice;

    cout<<"1: Register\n2: Login\nEnter your choice: "; cin>>choice;

    if(choice == 1)
    {
        string username, passwd;
        cout<<"Select a username: "; cin>>username;
        cout<<"Select a password: "; cin>>passwd;

        ofstream out1(".username.txt");
        ofstream out2(".password.txt");
        out1<<username;
        out2<<passwd;
        out1.close();
        out2.close();

        main();
    }
    else if(choice == 2)
    {
        bool status = isLoggedIn();

        if(!status)
        {
            cout<<"False Login!"<<endl;
            return 1;
        }
        else
        {
            cout<<"Login Successful"<<endl;
            return 0;
        }
    }
}
