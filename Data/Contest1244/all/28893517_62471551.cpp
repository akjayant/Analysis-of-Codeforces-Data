#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,ans=0,tmp=0,c=0;
        cin >> n;
        string s;
        cin >> s;
        s = '4'+s;
        ans = n;
        for(int i=1; i<=n; i++)
        {
            if (s[i]=='1')
            {
                tmp = i + max((ll)i , (ll)n-i+1);
                ans = max(ans , tmp);
            }
        }
        for(int i=n; i>=1; i--)
        {
            if (s[i]=='1')
            {
                tmp = n-i+1 + max((ll)n-i+1 , (ll)i);
                ans = max(ans , tmp);
            }
        }
        cout << ans << "\n";
    }



    return 0;
}
