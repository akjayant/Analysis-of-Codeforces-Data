#include <bits/stdc++.h>

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define getfiles ifstream cin("input.txt"); ofstream cout("output.txt");
#define endl '\n'
#define con continue
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()

const ll INF = 2000000005;
const ll BIG_INF = 2000000000000000005;
const ll mod = 1000000007;
const ll P = 31;
const ld PI = 3.141592653589793238462643;
const double eps = 1e-9;

using namespace std;

vector< pair<ll, ll> > dir = {
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        1, 0
    },
    {
        0, -1
    }
};

bool valid(ll x, ll y, ll n, ll m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

mt19937 rng(1999999973);

const ll N = 100000 + 50;
ll a[N], pref[N], suf[N], n, k, ans, sum = 0;

inline ll getPosBiggerOrEqual(ll x) {
    if (x > a[n])
        return n + 1;

    ll l = 1, r = n;
    while(l != r) {
        ll mid = (l + r) / 2;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

inline ll getPosLessOrEqual(ll x) {
    if (x < a[1])
        return 0;

    ll l = 1, r = n;
    while(l != r) {
        ll mid = (l + r + 1) / 2;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

signed main() {
    fast_io;

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (k >= sum) {
        cout << 0;
        return 0;
    }

    sort(a + 1, a + n + 1);

    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    for (ll i = n; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    ans = a[n] - a[1];


    for (ll i = 1; i <= n; i++) {
        ll oper = a[i] * i - pref[i];
        if (oper > k)
            break;
        oper = k - oper;

        ll l = 0, r = 1e9 + 5;

        while(l != r) {
            ll mid = (l + r) / 2;

            ll pos = getPosBiggerOrEqual(a[i] + mid);
            if (suf[pos] - (a[i] + mid) * (n - pos + 1) <= oper)
                r = mid;
            else
                l = mid + 1;
        }
        ans = min(ans, l);
    }

    for (ll i = n; i >= 1; i--) {
        ll oper = suf[i] - a[i] * (n - i + 1);
        if (oper > k)
            break;
        oper = k - oper;

        ll l = 0, r = 1e9 + 5;

        while(l != r) {
            ll mid = (l + r) / 2;

            ll pos = getPosLessOrEqual(a[i] - mid);
            if ((a[i] - mid) * pos - pref[pos] <= oper)
                r = mid;
            else
                l = mid + 1;
        }
        ans = min(ans, l);
    }


    cout << ans;

    return 0;
}
