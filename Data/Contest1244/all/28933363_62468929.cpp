#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <math.h>
#include <iomanip>
typedef long long ll;
using namespace std;
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize "-O3"
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    fori(s.size()) s[i] -= '0';
    vector < int > cnt;
    fori(s.size()) if (s[i] == 1) cnt.pb(i);
    if (cnt.size() == 0) {
        cout << n << "\n";
        return ;
    }
    int k = cnt.back() + 1;
    int ans = k * 2;
    int k2 = n - cnt[0];
    cout << max(ans, k2 * 2) << "\n";
    return ;

}
int main() {
    int t;
    cin >> t;
    fori(t) solve();
}


/*


10 100
2 1
3 1
4 1
5 2
6 2
7 3
8 4
9 4
10 4
1 2 3 4 5 6 7 8 9 10
*/
