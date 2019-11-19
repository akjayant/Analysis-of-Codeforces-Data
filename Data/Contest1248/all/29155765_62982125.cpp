#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> v;
    ll s=0;
    for(int i=0;i<n;i++)
    {
        ll j; cin>>j;
        s+=j;
        v.pb(j);
    }
    sort(v.begin(),v.end());
    ll a=0,b=0;
    for(int i=0;i<n/2;i++) a+=v[i];
    b=s-a;
    cout<<a*a+b*b;
}
