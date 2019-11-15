#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

//gcd
template<typename T>
T gcd(T a, T b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int t;cin >> t;
    REP(i,t) {
        int a,b; cin >> a >> b;
        if (a == 1 || b == 1) {
            puts("Finite");
        }
        else if (gcd(a,b) == 1) {
            puts("Finite");
        }
        else {
            puts("Infinite");
        }
    }
    return 0;
}