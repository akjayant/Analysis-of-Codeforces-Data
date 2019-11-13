#include <bits/stdc++.h>

#define ll long long
#define MAX 300005
#define pp pair<ll, pair<ll, ll>>
#define pb push_back
#define mod 1000000007

using namespace std;

ll power(ll x, ll y);

ll gcd(ll a, ll b);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,min(a[i],n-i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}

ll power(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
