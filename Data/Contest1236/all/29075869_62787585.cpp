#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define M ll(1e9 + 7)
#define maxn 200001

using namespace std;
typedef long long ll;

ll n, m;

ll power(ll a, ll b){
    if (b == 0) return 1;
    if (b&1) return power(a, b - 1) * a % M;
    ll tg = power(a, b / 2);
    return tg * tg % M;
}

int main(){
    BASE
    cin >> n >> m;
    cout << (power(power(2, m) - 1, n) + M) % M;
    return 0;
}
