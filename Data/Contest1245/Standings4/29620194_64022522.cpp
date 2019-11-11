/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Str(x) to_string(x)
#define len(s) (int)s.size()

typedef long long ll;
typedef long double lld;
typedef string str;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, cnt = 0;
        cin >> n >> a >> b >> c;
        vector <char> s(n, '?');
        for (int i = 0; i < n; i++) {
            char ch;
            cin >> ch;
            if (ch == 'R') {
                if (b) {
                    b--;
                    cnt++;
                    s[i] = 'P';
                }
            }
            if (ch == 'P') {
                if (c) {
                    c--;
                    cnt++;
                    s[i] = 'S';
                }
            }
            if (ch == 'S') {
                if (a) {
                    a--;
                    cnt++;
                    s[i] ='R';
                }
            }
        }
        for (auto &it : s) {
            if (it == '?') {
                if (a) {
                    a--;
                    it = 'R';
                } else if (b) {
                    b--;
                    it = 'P';
                } else {
                    c--;
                    it = 'S';
                }
            }
        }
        if (cnt >= (n + 1) / 2) {
            cout << "YES\n";
            for (auto cc : s)
                cout << cc;
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
