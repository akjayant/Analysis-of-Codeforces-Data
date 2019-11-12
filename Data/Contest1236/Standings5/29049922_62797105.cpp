#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <assert.h>
#include <limits>
#include <cstdio>
using namespace std;

//#define RDEBUG 1
#ifdef RDEBUG
#define D(x) x
#else
#define D(x)
#endif
#define inf 0x7fffffff
#define MOD 1000000007

typedef long long ll;


ll add(ll a, ll b) {
    a += b;
    if(a >= MOD) {
        a -= MOD;
    }
    return a;
}
ll sub(ll a, ll b) {
    a -= b;
    if(a < 0) {
        a += MOD;
    }
    return a;
}

ll mul(ll a, ll b) {
    return (a * b)%MOD;
}

void add_self(ll& a, ll b) {
    a = add(a, b);
}
void sub_self(ll& a, ll b) {
    a = sub(a, b);
}
void mul_self(ll& a, ll b) {
    a = mul(a, b);
}


const ll MAXN = 200010;

ll ans[310][310];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    ll curr = 1;
    for (ll j = 0; j<N; j++) {
        if (j%2 == 0) {
            for (ll i = 0; i<N; i++) {
                ans[i][j] = curr;
                curr++;
            }
        } else {
            for (ll i = N-1; i>=0; i--) {
                ans[i][j] = curr;
                curr++;
            }
        }
    }
    for (ll i = 0; i<N; i++) {
        for (ll j = 0; j<N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}



