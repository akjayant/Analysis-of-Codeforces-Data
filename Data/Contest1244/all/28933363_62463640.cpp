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
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int cnt1 = a / c;
    if (a % c != 0) cnt1++;
    int cnt2 = b / d;
    if (b % d != 0) cnt2++;
    if (cnt1 + cnt2 > k) {
        cout << -1 << "\n";
        return ;
    } else {
        cout << cnt1 << " " << cnt2 << "\n";
    }
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
