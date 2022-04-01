#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int BinarySearch(long int arr[], long int n, long int key)
{
    long int s=0;
    long int e=n;

    while(s<=e)
    {
        long int mid = (s+e)/2;
        if (key == arr[mid])
        {
            return mid;
        }

        if (arr[mid] > key)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    long int n;
    cin>>n;
    long int arr[n];
    long int e =0;
    for (long int i=0; i<n;i++)
    {
        long int u;
        cin>>u;
        e = e + u;
        arr[i]=e;
    }

    long int m;
    cin>>m;
    long int arr1[m];
    long int arr2[m];
    for (long int i = 0; i < m; i++)
    {
        long int w;
        cin>>w;
        arr1[i]=w;
        arr2[i]=w;
    }

    sort(arr1, arr1 + m);
    long int arr3[m];
    long int j=0;

    for (long int i=0; i<n;i++)
    {
        if (arr1[j]<=arr[i])
        {
            arr3[j] = i+1;
            j+=1;
            i--;
        }
    }

    for (long int i=0; i<m;i++)
    {
        cout<<arr3[BinarySearch(arr1,m,arr2[i])]<<endl;;
    }
    return 0;
}