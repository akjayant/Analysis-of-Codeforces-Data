#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvvi> vvvvi;

vi DP(1e5+5, -1);
int mod = 1e9 + 7;

ll dp(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    if (DP[n] != -1) return DP[n];
    return DP[n] = (dp(n-1) + dp(n-2)) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vi aux;
    ll ans = 1;
    int cur = 0, lst = 0;
    bool a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'w') a = 1;
        if (s[i] == 'm') b = 1;
    }
    if (a || b) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != lst) {
            if (lst == 'u' || lst == 'n') aux.push_back(cur);
            cur = 0;
            lst = s[i];
        }
        cur++;
    }
    if (lst == 'u' || lst == 'n') aux.push_back(cur);
    for (int i = 0; i < aux.size(); ++i) {
        ans = (ans * dp(aux[i])) % mod;
    }
    cout << ans << "\n";
    return 0;
}