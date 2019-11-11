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

map<char,char> convert;

int solve() {
    int n, a, b, c;
    string s;
    cin >> n >> a >> b >> c >> s;
    vector<int> good, bad;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'R') {
            if (b) {
                b--;
                good.pb(i);
            }else {
                bad.pb(i);
            }
        }
        if (s[i] == 'P') {
            if (c) {
                c--;
                good.pb(i);
            }else {
                bad.pb(i);
            }
        }
        if (s[i] == 'S') {
            if (a) {
                a--;
                good.pb(i);
            }else {
                bad.pb(i);
            }
        }
    }
    for (auto x : good) {
        if (s[x] == 'P') {
            s[x] = 'S';
            continue;
        }
        if (s[x] == 'S') {
            s[x] = 'R';
            continue;
        }
        if (s[x] == 'R') {
            s[x] = 'P';
        }
    }
    for (auto x : bad) {
        if (a) {
            a--;
            s[x] = 'R';
            continue;
        }
        if (b) {
            b--;
            s[x] = 'P';
            continue;
        }
        if (c) {
            c--;
            s[x] = 'S';
        }
    }
    n++;
    n /= 2;
    if (good.size() >= n) {
        cout << "YES\n" << s << '\n';
    }else {
        cout << "NO\n";
    }
    return 0;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        //freopen("ILUXA.in", "r", stdin);
    int t;
    cin >> t;
    convert['R'] = 'P';
    convert['P'] = 'S';
    convert['S'] = 'R';
    while (t--) {
        solve();
    }
    return 0;
}
