#include<iostream>
using namespace std;

void Del(int q[] , int e , int f)
{
    int t=0;
    for(int i=0;i<=f-1;i++)
    {
        if(q[i]==e)
        {
            break;
        }

        else
        {
            t++;
        }
    }

    for (int j=t;j<=f-2;j++)
    {
        q[j]=q[j+1];
    }
}

int main()
{
   int n;
   cin>>n;
   int b =n;

   int l[n];

   for (int i=0; i<=n-1 ; i++)
   {
       int a;
       cin>>a;
       l[i]=a;
   }

   int d[b];
   int z=0;
   int x=0;
   int g=0;

if (b==1)
{
    cout<<l[0]<<endl;
}

else
{
    while(x<b-1)
    {
       for (int i =0 ; i<=n-1; i++)
       {
           for (int j=0 ; j<=n-1;j++)
           {
               if(l[i]<=l[j])
               {
                  z++;
                  if(z==n)
                  {
                      break;
                  }
                }
            }

        if(z==n)
        {
           if (g>=1)
           {
               x++;
           }
           g++;
           d[x]=l[i];
           Del(l,l[i],n);
           n--;
        }
        z=0;
    } 
}
    for (int i=0 ; i<=b-1 ; i++)
    {
        cout<<d[i]<<" ";
    }
}
    return 0;
}

