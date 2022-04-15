#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll y = 1;
        vector<ll> vec;
        ll e;
        cin >> e;
        vec.push_back(e);
        ll r = 0;

        if (n == 1)
        {
            cout << e << endl;
        }

        else
        {
            for (ll j = 0; j < n - 1; j++)
            {
                ll a;
                cin >> a;

                vec.push_back(a);

                if (vec.at(y) * vec.at(y - 1) > 0)
                {
                    y += 1;
                    if (j == n - 2)
                    {
                        sort(vec.begin(), vec.begin() + y);
                        r = r + vec.at(y - 1);
                    }
                }

                else if (vec.at(y) * vec.at(y - 1) < 0)
                {
                    sort(vec.begin(), vec.begin() + y);
                    r = r + vec.at(y - 1);

                    ll q = vec.at(y);
                    vec.clear();
                    y = 1;
                    vec.push_back(q);
                }

                if (y == 1 && j == n - 2)
                {
                    r = r + vec.at(0);
                }
            }
            cout << r << endl;
        }
    }
    return 0;
}