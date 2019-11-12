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

void solve() {
    cin >> k;
    for (int kk = 0; kk < k; kk++) {
        cin >> n >> s >> t;
        int fi = -1, se = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (fi == -1) fi = i;
                else if (se == -1) se = i;
                else {
                    fi = -1;
                    se = 0;
                    break;
                }
            }
        }
        if (fi != -1 && se != -1) {
            if (t[fi] == t[se] && s[fi] == s[se]) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}
