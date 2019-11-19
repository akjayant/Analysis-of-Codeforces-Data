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
constexpr ll INF = 1001001001001001001LL;
//constexpr double INF = 1e10;
constexpr double EPS = 1e-10;
using number = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, m;
        ll oddp = 0, evenp = 0, oddq = 0, evenq = 0;
        ll p, q;
        cin >> n;
        rep(i, n) {
            cin >> p;
            if (p % 2) oddp++;
            else evenp++;
        }
        cin >> m;
        rep(i, m) {
            cin >> q;
            if (q % 2) oddq++;
            else evenq++;
        }
        cout << evenp*evenq + oddp * oddq << endl;
    }
}
