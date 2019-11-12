#pragma comment(linker, "/STACK:134217728") //128mb
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;


typedef long long ll;
const long long MOD = 1000000007; //1e9+7
const long long MAXN = 100000 + 100; //1e5


ll binpow(ll a, ll p) {
    if (p == 0) return 1;
    if (p == 1) return a%MOD;
    if (p&1) {
        return (a*binpow(a,p-1))%MOD;
    }
    ll t = binpow(a, p/2);
    return (t*t)%MOD;
}


int main() {
    ll n,m;
    cin >> n >> m;
    ll pp = binpow(2, m);
    pp--;
    if (pp < 0) pp+=MOD;
    pp %= MOD;
    cout << binpow(pp, n);
    return 0;
}
