#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define debug(i) cout << i << endl;
#define debugarr(a) for(auto i : a) cout << i << " ";

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>

#define MOD 1000000007

using namespace std;

ll add(ll a, ll b) {
    return ((a % MOD)+(b%MOD))%MOD;
}
ll init[1000011];
int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    init[1] = 2;
    ll fibA=2;
    ll fibB=0;
    for(int i = 2; i <= 1000000; i++) {
        init[i] = add(init[i-1], fibA);
        ll aux=fibA;
        fibA = add(fibA,fibB);
        fibB=aux;
    }
    init[1] = 2;

    ll ans = init[n];
    fibA=2;
    fibB=0;
    for(int i = 2; i <= m; i++) {
        ans = add(ans, fibA);
        ll aux=fibA;
        fibA = add(fibA, fibB);
        fibB=aux;
    }
    cout << ans << endl;
}
