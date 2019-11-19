/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
int main()
{
    please followmeoninsta
    int t;
    cin >> t;
    for(; t; --t)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int ans = n;
        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
                ans = max(ans, i + 1 + 1 + max(i, n - i - 1));
        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
                ans = max(ans, n - i + 1 + max(i, n - i - 1));
        cout << ans << '\n';
    }

    return 0;
}
