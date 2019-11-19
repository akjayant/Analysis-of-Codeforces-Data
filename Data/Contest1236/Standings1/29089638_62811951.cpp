#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
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
constexpr int INF = 1001001001;
//constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;



int main() {
    ll n, m, k; cin >> n >> m >> k;
    vector<set<ll>> row(n + 1), col(m + 1);
    ll x, y;
    rep(i, k) {
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }
    rep(i, n + 1) {row[i].insert(0); row[i].insert(m + 1);}
    rep(i, m + 1) {col[i].insert(0); col[i].insert(n + 1);}

    ll moved = 1;
    x = 1; y = 1;
    vll u(4); u[0] = 1; u[1] = m + 1; u[2] = n + 1; u[3] = 0;
    rep(funi, 201010) {
        if (funi % 4 == 0) {
            ll ny = min(*row[x].upper_bound(y), u[1]) - 1;
            if (funi > 1 && ny <= y) break;
            moved += ny - y;
            y = ny;
            u[1] = ny;
        }
        else if (funi % 4 == 2) {
            ll ny = max(*(--row[x].upper_bound(y)), u[3]) + 1;
            if (funi > 1 && ny >= y) break;
            moved += y - ny;
            y = ny;
            u[3] = ny;
        }
        else if (funi % 4 == 1) {
            ll nx = min(*col[y].upper_bound(x), u[2]) - 1;
            if (funi > 1 && nx <= x) break;
            moved += nx - x;
            x = nx;
            u[2] = nx;
        }
        else {
            ll nx = max(*(--col[y].upper_bound(x)), u[0]) + 1;
            if (funi > 1 && nx >= x) break;
            moved += x - nx;
            x = nx;
            u[0] = nx;
        }
        // cout << "(funi,moved) = " << funi << " " << moved << endl;
        // cout << "(x,y) = " << x << " " << y << endl;
    }
    cout << (n * m - moved == k ? "Yes" : "No") << endl;
}