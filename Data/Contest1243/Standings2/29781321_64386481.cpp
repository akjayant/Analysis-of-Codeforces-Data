#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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

ll n, nn;
vector <ll> v;

int main() {
    scanf("%lld", &n);
    nn=n;
    ll cnt=0;
    for (ll i=2; i*i<=n; ++i) {
        if (nn%i) continue;
        while (nn%i==0) nn/=i;
        v.pb(i);
    }
    if (nn!=1) v.pb(nn);
    if (v.size()==0) {
        printf("%lld\n", n);
        return 0;
    }
    else if (v.size()==1) {
        printf("%lld\n", v[0]);
        return 0;
    }
    printf("1\n");
    return 0;
}
