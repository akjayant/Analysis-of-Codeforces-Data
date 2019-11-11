#include <iostream>
#include <cmath>
#include <random>
#include <cassert>
#include <iomanip>
#include <set>
#include <map>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define int long long
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;
int F[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (char c: s) {
        if (c == 'w' || c == 'm') {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 1;
    int n = s.length();
    F[0]  =1;
    F[1] = 1;
    for (int i = 2; i < MAXN; i++) F[i] = (F[i-1] + F[i-2]) % MOD;
    int l = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            if ((s[i-1] == 'u' || s[i-1] == 'n') && l > 1) {
                ans = (ans * F[l]) % MOD;
            }
            l = 1;
        } else {
            l++;
        }
    }
    if ((s[n-1] == 'u' || s[n-1] == 'n') && l > 1) {
        ans = (ans * F[l]) % MOD;
    }
    cout << ans << endl;
}