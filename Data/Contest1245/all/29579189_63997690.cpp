/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
int t, n, a, b, c;
string s;
char ans[102];
int main()
{
    please followmeoninsta
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        cin >> a >> b >> c;
        cin >> s;
        int w = 0;
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'R' && b)
                ans[i] = 'P', --b, ++w;
            if(s[i] == 'P' && c)
                ans[i] = 'S', --c, ++w;
            if(s[i] == 'S' && a)
                ans[i] = 'R', --a, ++w;
        }
        if(w >= n/2 + n%2)
        {
            cout << "YES\n";
            for(int i = 0; i < n; ++i)
            {
                if(ans[i])
                    cout << ans[i];
                else
                    if(a)
                        cout << "R", --a;
                    else
                        if(b)
                            cout << "P", --b;
                        else
                            cout << "S", --c;
            }
            cout << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
