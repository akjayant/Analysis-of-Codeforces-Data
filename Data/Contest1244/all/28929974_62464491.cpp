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

        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int ans_i = -1;
        int ans_j = -1;

        int minn = 10001;

        for (int i = 0; i <= k; ++ i){
            for (int j = 0; j <= k; ++ j){
                if (i + j <= k){

                    if (i * c >= a && j * d >= b){

                        if (i + j <= minn){
                            minn = i + j;
                            ans_i = i;
                            ans_j = j;
                        }

                    }

                }
            }
        }

        if (ans_i == -1){
            cout << "-1\n";
        }else{
            cout << ans_i  << " " << ans_j << "\n";
        }
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