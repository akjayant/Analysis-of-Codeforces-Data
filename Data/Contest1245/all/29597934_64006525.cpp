#include<bits/stdc++.h>
using namespace std;
long test, n, a, b, c;
string s;
char t[105];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--)
    {
        cin >> n >> a >> b >> c;
        cin >> s;
        long res = 0;
        for (long i = 0; i < n; i++) t[i] = '@';
        for (long i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R' && b > 0)
            {
                res++, b--;
                t[i] = 'P';
                continue;
            }
            if (s[i] == 'P' && c > 0)
            {
                res++, c--;
                t[i] = 'S';
                continue;
            }
            if (s[i] == 'S' && a > 0)
            {
                res++, a--;
                t[i] = 'R';
                continue;
            }
        }
        if (res >= n / 2 + (n % 2 != 0))
        {
            cout << "YES" << '\n';
            for (long i = 0; i < n; i++)
            {
                if (t[i] == '@')
                {
                    if (a > 0)
                    {
                        cout << 'R';
                        a--;
                        continue;
                    }
                    if (b > 0)
                    {
                        cout << 'P';
                        b--;
                        continue;
                    }
                    if (c > 0)
                    {
                        cout << 'S';
                        c--;
                        continue;
                    }
                }
                else cout << t[i];
            }
            cout << '\n';
        }
        else cout << "NO" << '\n';
    }
}
