#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

const ll mod = 1000000007;
//const ll mod = 998244353;

const int MAX_N = 100010;
ll fact[MAX_N],fact_inv[MAX_N],inv[MAX_N];

ll pow_mod(ll a,ll b) {
    ll ret;
    if (b < 0) ret = pow_mod(a,mod+b-1);
    else if (b == 0) ret = 1;
    else if (b == 1) ret = a;
    else {
        ll c = pow_mod(a,b/2);
        if (b%2) ret = (c*c)%mod*a%mod;
        else ret = c*c%mod;
    }
    return ret;
}

void generate_table(int x) {
    fact[0] = 1;fact[1] = 1;
    for (int i = 2;i <= x;++i) fact[i] = fact[i-1]*i%mod;
    fact_inv[x] = pow_mod(fact[x],-1);
    for (int i = x;i > 0;--i) fact_inv[i-1] = fact_inv[i]*i%mod;
    for (int i = 1;i <= x;++i) inv[i] = fact_inv[i]*fact[i-1]%mod;
}

ll combi(ll a, ll b) {
    return fact[a]*fact_inv[b]%mod*fact_inv[a-b]%mod;
}

int main() {
    generate_table(100000);
    string s;
    cin >> s;
    s += 'A';
    int n = s.size();
    ll ans = 1;
    int w = 0,m = 0;
    for (int i = 0;i < n;++i) {
        if (w && s[i] != 'u') {
            ll t = 0;
            for (int j = 0;j <= w/2;++j) (t += combi(w-j,j)) %= mod;
            (ans *= t) %= mod;
            w = 0;
        }
        if (m && s[i] != 'n') {
            ll t = 0;
            for (int j = 0;j <= m/2;++j) (t += combi(m-j,j)) %= mod;
            (ans *= t) %= mod;
            m = 0;
        }
        if (s[i] == 'u') w++;
        else if (s[i] == 'n') m++;
        else if (s[i] == 'w' || s[i] == 'm') ans = 0;
    }
    cout << ans << endl;
}