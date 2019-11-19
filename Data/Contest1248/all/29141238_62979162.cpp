#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define MOD 1000000007
#define printclock cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";

ll m(ll a) {
    return ((a%MOD)+MOD)%MOD;
}

ll p(ll a, ll b) {
    if (b==0) return 1ll;
    ll x = p(a, b>>1);
    if (b & 1) return m(x*m(a*x));
    return m(x*x);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (auto &i: a) scanf("%lld", &i);
    sort(a.begin(), a.end());
    int j = 0;
    ll t1 = 0;
    for (; j<n/2; j++) {
        t1 += a[j];
    }
    ll t2 = 0;
    for (; j<n; j++) {
        t2 += a[j];
    }
    printf("%lld\n", t1*t1+t2*t2);
}