#include <bits/stdc++.h>

using namespace std;
#define taskname "cf1243"

int T, n;
string s, t;

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    for (cin >> T; T--;)
    {
        cin >> n >> s >> t;
        if (s == t)
        {
            cout << "YES\n";
            continue;
        }
        int cnt = 0, pos = -1, pos2 = -1;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
            {
                if (pos == -1)
                    pos = i;
                cnt++;
            }
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                pos2 = i;
        if (cnt > 2 || cnt == 1)
        {
            cout << "NO\n";
            continue;
        }
        if ((s[pos] == s[pos2] && t[pos] == t[pos2]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
