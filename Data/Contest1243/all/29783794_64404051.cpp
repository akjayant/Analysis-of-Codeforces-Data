#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define re(n) for (int i = 0; i < (n); ++i)
#define rej(n) for (int j = 0; j < (n); ++j)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <pair <int, int>> vii;
typedef vector <vector <int>> vvi;

const ld PI = acos((ld)-1);

int main() {
    #ifndef LOCALDEBUG
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #endif  // LOCALDEBUG
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    ll g = 0;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            g = __gcd(g, i);
            n /= i;
        }
    }
    if (n > 1) {
        g = __gcd(g, n);
    }
    cout << g;
    return 0;
}
