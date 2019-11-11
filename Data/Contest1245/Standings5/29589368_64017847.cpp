#include <bits/stdc++.h>

#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 1;
const ll mod = 1e9 + 7;

int n;
ll dp[maxN];

char s[maxN];

vector <pair<char, int> > rp;

ll res = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1);
    n = strlen(s + 1);
    for1(i, n)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            cout << 0;
            return 0;
        }
    }
    dp[0] = dp[1] = 1;
    fore(i, 2, 1e5)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
    rp.eb(s[1], 1);
    fore(i, 2, n)
    {
        if (s[i] == rp.back().fi)
        {
            ++rp.back().se;
        }
        else
        {
            rp.eb(s[i], 1);
        }
    }
    for (auto &p: rp)
    {
        if (p.fi == 'u' || p.fi == 'n')
        {
            res *= dp[p.se];
            res %= mod;
        }
    }
    cout << res;
    return 0;
}
