#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define allin(x, V) for(auto x : V)

#define endl '\n'
#define debug(vrb) {cerr << #vrb << ": " << vrb << endl;}
#define DEBUG(cnt) {cerr << #cnt << ": "; for(auto vrb : cnt) cerr << vrb << ", "; cerr << endl;}

typedef long long ll;
typedef long double ld;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef vector<char> vc;
typedef vector<vc> vvc;

const ll MOD = 1e9+7;

ll poww(ll a, ll b) {
	if (b == 0) return 1LL;
	ll s = poww(a, b/2);
	if (b%2 == 1) return ((s*s)%MOD * a)%MOD;
	else return (s*s)%MOD;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cout.setf(ios::fixed);
    //cout.precision(4);

    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll sol = poww(poww(2, m) - 1, n);

    cout << (sol%MOD + MOD)%MOD << endl;
}
