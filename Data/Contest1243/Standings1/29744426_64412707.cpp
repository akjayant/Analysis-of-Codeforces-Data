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


char ff[55];
char ss[55];

void dof() {

    int n;
    cin >> n;

    string s1;
    string s2;
    cin >> s1 >> s2;

    for (int i = 0; i < n; ++i) {
        ff[i] = s1[i];
        ss[i] = s2[i];
    }

    vector<pair<int, int>> answr;

    bool was_bad = false;

    for (int i = 0; i < n; ++i) {


        if (ff[i] != ss[i]) {

            bool ok = false;

            for (int j = i + 1; j < n; ++j) {
                if (ff[j] == ff[i]) {
                    ok = true;

                    swap(ff[j], ss[i]);
                    answr.push_back({j, i});

                    break;
                }

            }

            if (!ok) {

                for (int j = i + 1; j < n; ++j) {
                    if (ss[j] == ff[i]) {
                        ok = true;

                        swap(ss[j], ff[j]);
                        swap(ff[j], ss[i]);
                        answr.push_back({j, j});
                        answr.push_back({j, i});

                        break;
                    }

                }
            }

            if (!ok)
                was_bad = true;
        }

    }

    if (was_bad) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << answr.size() << "\n";

        for (auto el : answr) {
            cout << el.first + 1 << " " << el.second + 1 << "\n";
        }
    }
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