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

ll a[MAXN];

ll r(ll x, ll y) {
    return x * x + y * y;
}

int main()
{
    fast_io;

    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    ll X = 0, Y = 0;
    int u1 = 0, u2 = n - 1;
    int who = 0;

    while(u1 <= u2) {
        if (!who) X += a[u2], u2--;
        else Y += a[u1], u1++;
        who = 1 - who;
    }
    cout << r(X, Y) << endl;


    return 0;
}
