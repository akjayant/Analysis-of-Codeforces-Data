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

ll n;
ll ans;
vector <ll> vec;

int main() {
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL), cout.tie(NULL);
    ///setlocale(0,"RUS");
    ///ifstream cin("input.txt");
    ///ofstream cout("output.txt");
    cin >> n;
    ll sq = sqrt(n);
    for(ll i = 2;i <= sq;i++) {
        if(n % i == 0) {
            vec.pb(i);
            if(n / i > i) {
                vec.pb(n / i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    ans = n;
    for(int i = 0;i < vec.size();i++) {
        bool ok = true;
        for(int j = 0;j < i;j++) {
            if(vec[i] % vec[j] == 0) {
                ok = false;
            }
        }
        if(ok == true && i > 0) {
            ans = 1;
            break;
        }
        if(ok == true) {
            ans = vec[i];
        }
    }
    cout << ans;
}
/**
**/
