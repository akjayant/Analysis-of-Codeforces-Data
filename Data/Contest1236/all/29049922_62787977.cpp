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


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    for (ll i = 0; i<t; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll val1 = min(a, b/2), val2 = min(b, c/2);
        ll na = a-val1, nb = b-2*val1;
        ll p1 = 3*val1+3*min(nb, c/2);
        nb = b-val2;
        ll nc = b-2*val2;
        ll p2 = 3*val2+3*min(a, nb/2);
        cout << max(p1, p2) << "\n";
    }
    return 0;
}



