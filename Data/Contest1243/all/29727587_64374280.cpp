#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        ll ans=0,cnt=1,mn=1e18;
        for(int i=n-1;i>=0;i--){
            mn=min(mn,a[i]);
            ans=max(ans,min(mn,cnt));
            cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
