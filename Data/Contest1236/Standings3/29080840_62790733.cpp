#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

ll pow2m(ll m) {
    if (m==0) return 1;
    ll tmp = pow2m(m/2);
    tmp = tmp*tmp%MOD;
    if (m%2==1) return tmp*2%MOD;
    else return tmp;
}

ll powm(ll m, ll n) {
    if (n==0) return 1;
    ll tmp = powm(m, n/2);
    tmp = tmp*tmp%MOD;
    if (n%2==1) return tmp*m%MOD;
    else return tmp;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    ll m2 = pow2m(m)-1;
    if (m2 < 0) m2 += MOD;
    cout << powm(m2, n) << '\n';
    return 0;
}
