#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;

ll mod = 1e9 + 7;
ll power(ll a, ll b) {
    ll c = 1;
    for (int i = 0; i <= 40; i++) {
        if (b & (1LL << i)) c = (c * a) % mod;
        a = (a * a) % mod;
    }
    return c;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    cout << power(power(2, m) - 1LL + mod, n);


    return 0;
}

