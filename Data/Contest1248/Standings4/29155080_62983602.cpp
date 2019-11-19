#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll x=0, y=0;
    for(int i=0;i<n/2;i++) x+=a[i];
    y = accumulate(a.begin(),a.end(),0ll) - x;
    cout << x*x + y*y << endl;
    return 0;
}
