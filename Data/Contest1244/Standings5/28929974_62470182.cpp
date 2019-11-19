#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <cstring>

using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 1e5;


void solve() {
    int t;

    cin >> t;

    while (t--){

        int n;
        cin >> n;

        int answr;

        string s;

        int maxx = 0;
        cin >> s;

        int ws = 0;

        for (int i = 0; i < n; ++ i) {

            if (s[i] == '1') {
                maxx = max(maxx, max(i + 1, n - i));
                ws = 1;
            }
        }

        if (ws == 0){
            cout << n << '\n';
            continue;
        }

        answr = 2*  maxx;

        cout << answr << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(20);
#ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    solve();
}