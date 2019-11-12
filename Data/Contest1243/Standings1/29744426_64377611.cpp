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


void dof() {

    int n;
    cin >> n;

    string s1;
    string s2;
    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << "Yes\n";
        return;
    }

    int i1 = -1;
    int i2 = -1;

    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {

            if (i2 != -1) {
                cout << "No\n";
                return;
            }
            if (i1 == -1) {
                i1 = i;
            } else
                i2 = i;
        }
    }


    if (s1[i1] == s1[i2] && s2[i1] == s2[i2]) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

void solve() {


    int k;
    cin >> k;
    while (k--){
        dof();
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