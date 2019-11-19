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
constexpr double EPS = 1e-10;
using number = long long;

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int a = -1, b = -1;
        rep(i, n) {
            if (s[i] == '1') {
                a = i;
                break;
            }
        }
        rep(i, n) {
            if (s[n - 1 - i] == '1') {
                b = n - 1 - i;
                break;
            }
        }
        if (a == -1) cout << n << endl;
        else cout << max(2 * n - 2 * a, 2 * n - 2 * (n - 1 - b)) << endl;
    }

}