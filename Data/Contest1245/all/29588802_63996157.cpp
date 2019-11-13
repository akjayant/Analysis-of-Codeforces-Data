#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define sync ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define fr(x, n) for (int x = 0; x < n; x++)
#define int long long
#define pb push_back
#define y1 fadasdsadassa
#define random mt19937 rng(time(nullptr));

using namespace std;

const double eps = 1e-9;
const double EPS = 1e-17; 
const int M = 1e5 + 1;
const int INF = 1e17 + 7;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e5 + 1;

int n, m;
vector <int> v;

signed main () { sync;
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a  >> b;
        if (__gcd(a, b) > 1) cout << "Infinite\n";
        else cout << "Finite\n";
    }
}
