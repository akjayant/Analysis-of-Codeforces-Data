#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <bitset>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>

using namespace std;
using namespace __gnu_pbds;



void solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    solve();
    return 0;
}

#define int long long

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int k, n;
string s, t;
vector < pair < int, int > > ans;

void solve() {
    cin >> k;
    for (int kk = 0; kk < k; kk++) {
        cin >> n >> s >> t;
        ans.clear();
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == s[j]) {
                        swap(s[j], t[i]);
                        ans.push_back({j + 1, i + 1});
                        break;
                    }
                    if (s[i] == t[j]) {
                        swap(s[n - 1], t[j]);
                        swap(s[n - 1], t[i]);
                        ans.push_back({n, j + 1});
                        ans.push_back({n, i + 1});
                        break;
                    }
                }
            }
        }
        if (s != t) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << " " << ans[i].second << '\n';
            }
        }
    }
}
