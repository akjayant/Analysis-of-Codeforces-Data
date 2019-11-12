#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    vector <ll> a;
    ll i;
    for(i=0; i<n; i++)
    {
        ll q;
        cin>>q;
        a.push_back(q);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll cnt = 0;
    for(i=0; i<n; i++)
    {
        if (a[i]>=i+1) cnt++;
    }
cout<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
        solve();
    return 0;
}

