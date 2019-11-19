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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll odd=0,odd1=0,even=0,even1=0;
        for(ll i=0;i<n;i++) {
            ll a;
            cin >> a;
            if(a&1)odd++;
            else even++;
        }
        ll m;
        cin >> m;
        for(ll i=0;i<m;i++) {
            ll a;
            cin >> a;
            if(a&1)odd1++;
            else even1++;
        }
        cout << (odd*odd1) + (even1*even) << endl;
    }
}