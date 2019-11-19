#include <bits/stdc++.h>

#define fi first
#define se second
#define m_p make_pair
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;

const int MAXN = 1123456;
const int MAXINT = 2147483098;
const ll MAXLL = 9223372036854775258LL;
const ll MOD = 1e9 + 7;

ll fib[MAXN];
ll st[MAXN];

int main()
{
    fast_io;

    int n, m;

    st[1] = 2LL;
    st[2] = 4LL;
    for (int i = 3; i <= 200000; ++i) st[i] = (st[i - 1] +  st[i - 2]) % MOD;

    fib[1] = fib[2] = 2LL;
    for (int i = 3; i <= 200000; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    cin >> n >> m;
    ll start = st[n];

    for (int i = 1; i < m; ++i) {
        start = (start + fib[i]) % MOD;
    }
    cout << start << endl;


    return 0;
}
