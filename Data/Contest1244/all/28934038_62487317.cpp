#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;

int n, u, v;
ll c[3][1001001];
vi G[1001001];

int main() {
    cin >> n;
    rep(i, 3) rep(j, n) cin >> c[i][j];
    rep(i, n - 1) {
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    int start;
    bool can = true;
    rep(i, n) {
        if (G[i].size() >= 3) {
            can = false; break;
        }
        if (G[i].size() == 1) start = i;
    }

    if (!can) {
        cout << -1 << endl;
        return 0;
    }

    vi order;
    order.pb(start); order.pb(G[start][0]);
    for (int k = 1; k < n - 1; k++) {
        for (auto x : G[order[k]]) {
            if (x == order[k - 1]) continue;
            else {
                order.pb(x);
                break;
            }
        }
    }

    ll ans = INF;
    int a, d;
    rep(i, 3) rep(j, 2) {
        ll tmp = 0;
        rep(k, n) {
            tmp += c[(i + (j + 1) * k) % 3][order[k]];
        }
        if (chmin(ans, tmp)) {
            a = i; d = j;
        }
    }

    cout << ans << endl;
    vi b(n,0);
    rep(k,n){
        b[order[k]] = (a + (d + 1) * k) % 3 + 1;
    }
    rep(k,n) cout << b[k] << " ";
    cout << endl; 

}