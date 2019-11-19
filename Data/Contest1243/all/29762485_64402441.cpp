#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define show(x) cout << "[debug " << __LINE__ << "] " << #x << " = " << x << endl
#define shows() cout << "=========================" << endl
#define debug cout << "[debug_scope " << __LINE__ << "]" << endl;
#else
#define show(x) ((void)0)
#define shows() ((void)0)
#define debug if (false)
#endif

vector<ll> del(ll n) {
    vector<ll> ans;

    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ans.pb(i);
            ans.pb(n / i);
        }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    if (n == 2) {
        cout << "2\n";
        return 0;
    }

    auto d = del(n);
    if (d.size() == 0) {
        cout << n << "\n";
        return 0;
    }

    auto lowest = d[0];
    for (auto dd : d) {
        if (dd % lowest != 0) {
            cout << "1\n";
            return 0;
        }
    }

    cout << lowest << "\n";
    return 0;
}
