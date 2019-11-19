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

int t, n, ans;
string s;

void solve() {
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n >> s;
        ans = n;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') ans++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ans = max(ans, max(i + 1, n - i) * 2);
            }
        }
        cout << ans << '\n';
    }

}
