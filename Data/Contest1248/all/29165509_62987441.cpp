#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=10000000000000000;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n;
        cin>>n;
        ll arr[n],x=0,sum=0;
        for(ll i=0;i<n;i++) cin>>arr[i],sum+=arr[i];
        sort(arr,arr+n,greater<ll>());
        for(ll i=0;i<(n-(n/2));i++) {
            sum-=arr[i];
            x+=arr[i];
        }
        ll ans = x*x;
        ans+=sum*sum;
        cout<<ans<<endl;


    return 0;
}
