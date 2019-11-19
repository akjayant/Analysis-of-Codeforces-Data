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
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> p(n);
        for (int &i: p) scanf("%d", &i);
        int m;
        scanf("%d", &m);
        vector<int> q(m);
        for (int &i: q) scanf("%d", &i);
        int o1 = 0, o2 = 0, e1 = 0, e2 = 0;
        for (int i: p) {
            if (i&1) o1++;
            else e1++;
        }
        for (int i: q) {
            if (i&1) o2++;
            else e2++;
        }
        printf ("%lld\n", 1ll*o1*o2+1ll*e1*e2);
    }
}