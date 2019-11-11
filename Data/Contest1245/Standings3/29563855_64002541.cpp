#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

//const int maxn = 100005;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//
    int t;
    cin >> t;
    for(int ii = 0; ii < t; ++ii)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c; //R, P, S
        string s;
        cin >> s;
        string ans;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
            {
                if (b > 0)
                {
                    --b;
                    ans += 'P';
                    ++cnt;
                }
                else
                {
                    ans += 'K';
                }
            }
            if (s[i] == 'P')
            {
                if (c > 0)
                {
                    --c;
                    ans += 'S';
                    ++cnt;
                }
                else
                {
                    ans += 'K';
                }
            }
            if (s[i] == 'S')
            {
                if (a > 0)
                {
                    --a;
                    ans += 'R';
                    ++cnt;
                }
                else
                {
                    ans += 'K';
                }
            }
        }
        for(int i = 0; i < n; ++i)
            if (ans[i] == 'K')
        {
            if (a > 0)
            {
                ans[i] = 'R';
                --a;
            }
            else
                if (b > 0)
                {
                    ans[i] = 'P';
                    --b;
                }
                else
                    {
                        ans[i] = 'S';
                        --c;
                    }
        }
        if (cnt * 2 >= n)
        {
            cout << "YES\n";
            cout << ans << '\n';
        }
            else         cout << "NO\n";
    }
    return 0;
}
