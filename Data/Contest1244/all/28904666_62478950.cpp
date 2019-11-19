/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
ll n, v[100002], k, sp[100002];
int main()
{
    please followmeoninsta
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    ll ps = 1;
    ll pd = n;
    ll ans = v[n] - v[1];
    while(k && ps < pd)
    {
        if(ps <= n - pd + 1)
        {
            ll dd = min(v[ps+1] - v[ps], k / ps);
            if(dd == 0 && v[ps+1] != v[ps])
                break;
            ans -= dd;
            k = k - dd * ps;
            if(dd == v[ps+1] - v[ps])
                ps++;
            else
                break;
        }
        else
        {
            ll dd = min(v[pd] - v[pd-1], k / (n - pd + 1));
            if(dd == 0 && v[pd] != v[pd-1])
                break;
            ans -= dd;
            k = k - dd * (n - pd + 1);
            if(dd == v[pd] - v[pd-1])
                pd--;
            else
                break;
        }
    }
    cout << ans;
    return 0;
}
