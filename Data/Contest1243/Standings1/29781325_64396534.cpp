#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < _n; ++i)
#define FJ(_n) for(int j = 0; j < _n; ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int l;
    cin >> l;
    while (l--)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<int> k(26);
        FI(n)
        {
            k[s[i] - 'a']++;
            k[t[i] - 'a']++;
        }
        bool e = false;
        FI(26)
            if (k[i] & 1)
            {
                e = true;
                cout << "No" << endl;
                break;
            }
        if (e)
            continue;
        vector<pair<int, int>> ans;

        FI(n)
        {
            if (s[i] == t[i])
                continue;

            bool found = false;
            int pos = -1;

            for (int j = i + 1; j < n; ++j)
            {
                if (t[j] == t[i])
                {
                    found = true;
                    pos = j;
                    if (s[i] == s[j])
                        break;
                }
            }

            if (!found)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (s[j] == t[i])
                    {
                        found = true;
                        pos = j;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "No" << endl;
                    e = true;
                    break;
                }

                ans.pb(mp(pos + 1, pos + 1));
                swap(s[pos], t[pos]);
                ans.pb(mp(i + 1, pos + 1));
                swap(s[i], t[pos]);
                continue;
            }
            ans.pb(mp(i + 1, pos + 1));
            swap(s[i], t[pos]);
        }
        if (e)
            continue;

        if (ans.size() <= 2 * n)
        {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (auto it : ans)
                cout << it.first << ' ' << it.second << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}
