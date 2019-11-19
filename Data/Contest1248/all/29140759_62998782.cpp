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

int n, m;
ll f[maxN];
ll res = 2;

void init()
{
    f[1] = f[2] = 1;
    fore(i, 3, 1e5)
    {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    for1(i, n - 1)
    {
        res += f[i] * 2;
        res %= mod;
    }
    for1(i, m - 1)
    {
        res += f[i] * 2;
        res %= mod;
    }
    cout << res;
    return 0;
}
