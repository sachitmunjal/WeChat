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

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> vec;
        char arr[n][m];
        map<pair<int, int>, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char s;
                cin >> s;
                arr[i][j] = s;
                if (s == 'R')
                {
                    mp[{i, j}] = i + j;
                    vec.push_back(i + j);
                }
            }
        }

        if (vec.size() == 0)
        {
            if (arr[0][0] == 'E')
            {
                cout << "NO" << endl;
            }

            else
            {
                cout << "YES" << endl;
            }
        }

        else
        {
            sort(vec.begin(), vec.end());
            vector<int>::iterator itr1 = vec.begin();
            int a = *itr1;
            map<pair<int, int>, int>::iterator itr2 = mp.begin();

            if (vec.size() == 1)
            {
                cout << "YES" << endl;
            }

            else
            {

                if ((*(itr1)) == (*(itr1 + 1)))
                {
                    cout << "NO"
                         << "\n";
                }

                else
                {
                    int x = 0;
                    int y = 0;
                    while (true)
                    {
                        if ((*itr2).second == a)
                        {
                            x = ((*itr2).first).first;
                            y = ((*itr2).first).second;
                            break;
                        }
                        else
                        {
                            itr2++;
                        }
                    }
                    int p = 0;
                    itr2 = mp.begin();

                    for (int i = 0; i < vec.size(); i++)
                    {
                        if (x > (((*itr2).first).first))
                        {
                            p++;
                            break;
                        }
                        else
                        {
                            itr2++;
                        }
                    }
                    itr2 = mp.begin();
                    for (int i = 0; i < vec.size(); i++)
                    {
                        if (y > (((*itr2).first).second))
                        {
                            p++;
                            break;
                        }
                        else
                        {
                            itr2++;
                        }
                    }

                    if (p == 0)
                    {
                        cout << "YES"
                             << "\n";
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
    return 0;
}