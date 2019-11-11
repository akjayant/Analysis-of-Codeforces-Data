#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;

ll f[N];
char s[N];

vector <ll> V;

int main() {
    //freopen("1245C.INP", "r", stdin);
    //freopen("1245C.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s + 1; ll n = strlen(s + 1);
    for (ll i = 1; i <= n; i++)
        if (s[i] == 'w' or s[i] == 'm') cout << 0, exit(0);
    //********************
    f[1] = 1; f[0] = 1;
    for (ll i = 2; i <= n; i++)
        f[i] = (f[i - 2] + f[i - 1]) % mod;
    for (ll i = 1; i <= n; ) {
        ll j = i;
        if (s[i] == 'n' || s[i] == 'u')
            while (j + 1 <= n && s[j + 1] == s[i]) j++;
        V.push_back(f[j - i + 1]);
        i = j + 1;
    }
    //********************
    ll kq = 1;
    for (auto it : V) kq = (kq * it) % mod;
    cout << kq;
    return 0;
}
