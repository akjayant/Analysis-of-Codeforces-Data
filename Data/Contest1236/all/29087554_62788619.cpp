#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <pii, int> ppi;

const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;

ll n, m;

ll mul(ll x, ll y) {
    return (x*y)%MOD;
}

ll add(ll x, ll y) {
    return (x+y+MOD)%MOD;
}

ll pot(ll x, ll y) {
    ll sol=1;
    while (y) {
        if (y%2) sol=mul(sol, x);
        x=mul(x, x);
        y/=2;
    }
    return sol;
}

int main() {
    scanf("%I64d%I64d", &n, &m);
    printf("%I64d\n", pot(add(pot(2LL, m), -1), n));
    return 0;
}
