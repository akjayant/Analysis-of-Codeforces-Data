#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define pb push_back
#define int long long

const LL mod = 1e9 + 7;


template<class T>
istream& operator >> (istream& in, vector<T>& v){ for (auto &x : v) { in >> x; } return in; }

template<class T>
istream& operator >> (istream& in, pair<T, T> & v){ in >> v.X >> v.Y;return in; }

template<class T>
ostream& operator << (ostream& out, pair<T, T> & v){ out << v.X << " " << v.Y;return out; }

void chkmax(int &a, int b) {
    a = max(a, b);
    return;
}

void chkmin(int &a, int b) {
    a = min(a, b);
    return;
}

LL ppow (LL x, LL s) {
    if (!s) return 1;
    if (!(s - 1)) return x % mod;
    if (s % 2) return (x * ppow (x, s - 1)) % mod;
    LL b = ppow (x, s / 2);
    return (b * b) % mod;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("ILUXA.in", "r", stdin);
    string s;
    cin >> s;
    map<char, int> m;
    for (auto x : s) {
        m[x]++;
    }
    if (m['m'] || m['w']) {
        cout << "0";
        return 0;
    }
    char prev = '.';
    int cnt = 0;
    vector<int> gg;
    s += '.';
    for (auto x : s) {
        if (x == prev) {
            cnt++;
        }else {
            if (prev == 'u' || prev == 'n') {
                gg.pb(cnt);
                cnt = 1;
            }else {
                cnt = 1;
            }
        }
        prev = x;
    }
    int MAXN = 1e5 + 100;
    int dp[MAXN];
    dp[0] = dp[1] = 1;
    for (int i = 2;i < MAXN;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
        /*if (i < 10) {
            cout << dp[i] << '\n';
        }*/
    }
    int ans = 1;
    for (auto x : gg) {
        //cout << x << '\n';
        ans *= dp[x];
        ans %= mod;
    }
    cout << ans;
    return 0;
}
