#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define pb push_back 
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second 
#define debug(x)  do{cerr<<#x<<": "<<x<<"\n";}while(0)
#define debugv(x) do{cerr<<#x<<": ";for(auto&e: (x))cerr<<e<<" ";cerr<<"\n";}while(0)
#define fori(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define RETURN(x) do{cout << x << '\n'; return 0;}while(0)
#define FIRSTWIN do{cout << "Monocarp\n"; return 0;}while(0)
#define SECONDWIN do{cout << "Bicarp\n"; return 0;}while(0)
 
const int MAXN = 54;
const int MOD = 1e9+7;
const int INF = 1e9+1;

LL gcd(LL a, LL b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main() {
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL n;
    cin >> n;
    vector<LL> factors;
    for(LL i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            factors.pb(i);
            if(i*i != n) factors.pb(n/i);
        }
    }

    if(factors.size() == 0) cout << n << endl;
    else if(factors.size() == 1) cout << factors[0] << endl;
    else {
        LL g = gcd(factors[0], factors[1]);
        fore(i,2,factors.size()-1) g = gcd(g, factors[i]);
        cout << g << endl;
    }
    
    return 0;
}

