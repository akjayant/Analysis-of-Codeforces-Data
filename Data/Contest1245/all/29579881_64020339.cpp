#include <bits/stdc++.h>

using namespace std;
#define taskname "cf1245"

int T, r, p, s, n;

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
        cin >> n >> r >> p >> s;
        string t;
        cin >> t;
        int res = 0;
        string ch = "";
        for (int i = 0; i < t.size(); i++)
            if (t[i] == 'R')
            {
                if (p > 0)
                {
                    p--;
                    res++;
                    ch += 'P';
                }
                else
                    ch += '1';
            }
            else if (t[i] == 'P')
            {
                if (s > 0)
                {
                    s--;
                    res++;
                    ch += 'S';
                }
                else
                    ch += '1';
            }
            else
            {
                if (r > 0)
                {
                    r--;
                    res++;
                    ch += 'R';
                }
                else
                    ch += '1';
            }
        if (res >= (n + 1) / 2)
        {
            cout << "YES\n";
            for (int i = 0; i < ch.size(); i++)
                if (ch[i] == '1')
                {
                    if (s > 0)
                    {
                        s--;
                        ch[i] = 'S';
                    }
                    else if (r > 0)
                    {
                        r--;
                        ch[i] = 'R';
                    }
                    else
                    {
                        p--;
                        ch[i] = 'P';
                    }
                }
            cout << ch << '\n';
        }
        else
            cout << "NO\n";
    }
}
