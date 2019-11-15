#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;


const int MAXN = 4e5 + 50;
const ll MOD = 1e9 + 7;

void solve() {


    int k;
    cin >> k;
    while (k--){
        int n;
        cin >> n;

        vector<int> inp;

        for (int i = 0; i < n; ++ i){
            int crr;
            cin >> crr;
            inp.push_back(crr);
        }

        sort(inp.begin(), inp.end());

        int answr = 0;

        for (int i  = n - 1; i >= 0; --i){
            answr = max(answr, min(inp[i], n - i));
        }

        cout << min(answr, n) << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(1);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    //cout << '\n' << (double)clock() / CLOCKS_PER_SEC << '\n';
#endif
}