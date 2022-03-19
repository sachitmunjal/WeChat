#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,n;
    cin>>s>>n;

    int g=0;
    vector <list <int> > dragons;

    for(int i=0; i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        list <int> lst;
        lst.push_back(x);
        lst.push_back(y);
        dragons.push_back(lst);
    }

    sort(dragons.begin(),dragons.end());

    vector <list<int>> :: iterator itr1;
    list <int> :: iterator itr2;

    for (itr1 = dragons.begin(); itr1!= dragons.end(); itr1++)
    {
        itr2 = (*itr1).begin();

        if (s> *itr2)
        {
            itr2++;
            s = s + *itr2;
            g++;
        }
    }

    if(g==n)
    {
        cout<<"YES"<<endl;
    }

    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}