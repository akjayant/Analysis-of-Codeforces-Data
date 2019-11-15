#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k;
    cin>>k;
    vector<ll> ans(k);
    for (ll t=0; t<k; t++){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for (ll i=0; i<n; i++)
            cin>>v[i];
        sort(v.begin(), v.end());
        ll h=v[n-1];
        ll w=1;
        ll m=1;
        ll mx=1;
        for (ll i=n-2; i>=0; i--){
            w++;
            h=v[i];
            m = min(w, h);
            mx = max(mx, m);
        }
        ans[t]=mx;
    }
    for (ll i=0; i<k; i++)
        cout<<ans[i]<<"\n";
    return 0;
}
