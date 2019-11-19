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

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cout.setf(ios::fixed);
    //cout.precision(4);

    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vi V(n);
    for (auto &x : V) cin >> x;
    sort(V.begin(), V.end());
    ll sv = 0;
    ll sh = 0;
    for (ll i=0; i<n; i++) {

        if (i < n/2) sv += V[i];
        else sh += V[i];
    }
    cout << sv*sv + sh*sh << endl;
}
