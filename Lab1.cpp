#include<iostream>
#include<string>
using namespace std;

string Reflex_vacume_agent(string location,string status)
{

    if(location=="A")
    {
        cout<< "right"<<endl;

        if(status=="Dirty")
    {
        return "Suck";
    }
    else
    {
         return "Invalid";
    }

    }
    else if(location=="B")
    {
    cout<<"Left"<<endl;;
        if(status=="Dirty")
    {
        return "Suck";
    }
    else
    {
        return "Invalid";
    }
    }
    else
    {
         return "Invalid";
    }

    }
  /*  }
    else if(location=="A")
    {
        return "right";
    }
    else if(location=="B")
    {
        return "Left";
    }*/




int main()
{
    string location,status;
    int n;
    cout<<"Enter the value you want to work"<<endl;
     cin>>n;
    for(int i=1;i<=n;i++){
    cout<<"enter the location and status"<<endl;
    cin>>location>>status;



    cout<<Reflex_vacume_agent(location,status)<<endl;
     }

}
