#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<=t-1;i++)
    {
        int a;
        cin>>a;

        if (360.0/(180.0-a)-360/(180-a)==0)
        {
            cout<<"YES"<<endl;
        }

        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}