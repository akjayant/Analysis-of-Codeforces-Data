#include <bits/stdc++.h>
using namespace std;
#define ld long long double
#define ll long long
#define mod 1000000007
#define scl(x) scanf("%lld",&x)
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll power(ll a,ll b) {
    ll res=1LL;
    while(b>0){
        if(b&1) res = mul(res,a);
        b/=2;
        a = mul(a,a);
    }
    return res%mod;
}


int main(){
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    ll sum1=0,sum2=0;
    ll a = (n-1)/2;
    if(n%2==0) {
        a++;
    }
    for(ll i=n-1;i>=0;i--) {
        if(i>=a)sum1+=arr[i];
        else sum2+=arr[i];
    }
    ll ans = (sum1*sum1) + (sum2*sum2);
    // cout << ans << endl;
    sum1=0,sum2=0;
    for(ll i=n-1;i>=0;i--) {
        if(i>=a)sum2+=arr[i];
        else sum1+=arr[i];
    }
    ll ans2 = (sum1*sum1) + (sum2*sum2);
    cout << max(ans,ans2) << endl;
}