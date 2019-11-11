#include <bits/stdc++.h>
#define E 0.000000000001
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll;

const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 1;

vector <ll> F(maxn);
void precalc() {
    F[0] = F[1] = 1;
    for(ll i = 2; i < maxn; i++) {
        F[i] = F[i - 1] + F[i - 2];
        F[i]%=mod;
    }
}

int main() {
    ios_base:: sync_with_stdio(false);
    precalc();
    string s;
    cin >> s;
    for(auto i: s) {
        if(i == 'm' || i == 'w') {
            cout << 0;
            return 0;
        }
    }
    ll n = s.size();
    ll res = 1;
    char ch = '*';
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] == ch && (ch == 'n' || ch == 'u')) {
            cnt++;
        }
        else {
            res *= F[cnt];
            res %= mod;
            cnt = 1;
        }
        ch = s[i];
    }
    if(ch == 'n' || ch == 'u') {
        res *= F[cnt];
        res %= mod;
    }
    cout << res;
}
 