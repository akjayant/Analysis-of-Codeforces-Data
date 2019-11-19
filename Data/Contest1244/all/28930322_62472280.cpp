# include <bits/stdc++.h>

///using namespace __gnu_pbds;
using namespace std;

# define ll long long
# define ld long double
# define pb push_back
# define ppb pop_back

const ll N = 1e5 + 10;
const ll M = 1e7 + 1000;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const ll inf = -1e18;

///typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> void_set;

bool isprime(ll x) {
    if(x == 1) return false;
    ll y = sqrt(x);
    for(ll i = 2;i <= y;i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

ll bin_pow(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    if(a == 0) return 0;
    if(a == 1) return a % mod;
    if(b % 2 == 0) {
        ll pw = bin_pow(a, b / 2) % mod;
        return (pw * pw) % mod;
    } else {
        return (bin_pow(a, b - 1) * a) % mod;
    }
}

const ld pi = acos(-1);

ll t, n;
ll ans;
ll p[N];
char a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ///setlocale(0,"RUS");
    ///ifstream cin("input.txt");
    ///ofstream cout("output.txt");
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for(int i = 1;i <= n + 1;i++) p[i] = 0;
        for(int i = n;i >= 1;i--) {
            if(a[i] == '1' && p[i + 1] == 0) {
                p[i] = i;
            } else {
                p[i] = p[i + 1];
            }
        }
        ans = n;
        for(int i = 1;i <= n;i++) {
            if(a[i] == '1') {
                if(p[i + 1] != 0) {
                    ans = max(ans, 2 * 1ll * i);
                    ans = max(ans, i + 2 * (p[i + 1] - i + 1) - 1);
                    ans = max(ans, i + (p[i + 1] - i + 1) + (n - p[i + 1] + 1));
                }
                ans = max(ans, 2 * 1ll * i);
            }
        }
        reverse(a + 1, a + n + 1);
        for(int i = n;i >= 1;i--) {
            if(a[i] == '1' && p[i + 1] == 0) {
                p[i] = i;
            } else {
                p[i] = p[i + 1];
            }
        }
        for(int i = 1;i <= n;i++) {
            if(a[i] == '1') {
                if(p[i + 1] != 0) {
                    ans = max(ans, 2 * 1ll * i);
                    ans = max(ans, i + 2 * (p[i + 1] - i + 1) - 1);
                    ans = max(ans, i + (p[i + 1] - i + 1) + (n - p[i + 1] + 1));
                }
                ans = max(ans, 2 * 1ll * i);
            }
        }
        cout << ans << '\n';
    }
}
/**
**/
