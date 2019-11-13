#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    string s, t;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> n >> s >> t;

        vector <pair <char, char>> pos;

        for (int j = 0; j < n; j++)
        {
            if (s[j] != t[j])
            {
                pos.push_back({s[j], t[j]});
            }
        }

        if (pos.size() > 2 || pos.size() == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (pos.size() == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                if (pos.size() == 2)
                {
                    if (pos[0].first == pos[1].first && pos[0].second == pos[1].second)
                    {
                        cout << "YES" << endl;
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
