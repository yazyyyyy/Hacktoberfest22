// username and password example of exception handling

#include<iostream>
using namespace std;

int len_of_num(int b)
{
    int i=0;
    while(b!=0)
    {
        i++;
        b=b/10;
    }
    return i;
}
int main()
{
    string username;
    int password;

    cout<<"Enter a username with more than 3 characters and less than 9 characters:";
    cin>>username;

    cout<<"Enter a integer number password of 6 digits:";
    cin>>password;

    try
    {
        
        if(cin.fail())
        {
            throw 999;
        }
        else if(username.length()<3 || username.length()>9)
        {
            throw string("Please enter required length username!!");
        }
        else if(len_of_num(password)!=6)
        {
            throw 'n';
        }
        else
        {
            cout<<"Thank you for chosing correct username and password!!"<<endl;
        }

    }
    catch(int a)
    {
        cout<<"Error "<<a<<" please enter the password in required format";
    }
    catch(string b)
    {
        cout<<b<<endl;
    }
    catch(char c)
    {
        cout<<"Error "<<c<<" please enter a 6 digit password!!"<<endl;
    }
}