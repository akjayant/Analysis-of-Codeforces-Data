#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 10;

ll a[MAXN];

int main()
{
    int n;
    cin>>n;
    for (int i = 1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l = 1,r = n;
    ll x = 0,y = 0;
    while (r > l)
    {
        x += a[l];
        y += a[r];
        l++; r--;
    }
    ll ans = 1;
    if (l == r)
    {
        ans = max((x + a[l]) * (x + a[l]) + y * y,(y + a[l]) * (y + a[l]) + x * x);
    }
    else ans = x * x + y * y;
    cout<<ans;
    return 0;
}