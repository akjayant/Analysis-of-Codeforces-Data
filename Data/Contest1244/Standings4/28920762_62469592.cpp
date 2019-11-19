#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <regex>
#include <math.h>
#include <map>
#include <iterator>
#include <climits>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <array>
#include <valarray>
#include <complex>
#include <random>
#include <functional>

#define _AUTOTEST
#ifdef AUTOTEST
    #include "autotest.h"
#endif

using namespace std;

vector<string> split(string s, string border);

#define int long long
#define double long double
#define make(type, n) type n; cin >> n
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORIT(p) for(auto it = p.begin(); it != p.end(); it++)
#define FOR(i, count) for(int i = 0; i < (count); i++)
#define FORE(i, l, r) for(int i = (l); i < (r); i++)
#define NFOR(i, n) for(int i = (((int) n)-1); i >= 0; i--)
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define SUM(x) accumulate(ALL(x), 0LL)
#define makev(a, n) VI a(n); FOR(i, n) cin >> a[i]
#define get_bit(mask, pos) ((mask >> pos) & 1)
#define set_bit_0(mask, pos) (mask &= (~(1 << pos)))
#define set_bit_1(mask, pos) (mask |= (1 << pos))
#define sqrt(x) sqrtl(x)
#define dis(x1, y1, x2, y2) hypotl((x2-x1), (y2-y1))
#define sqr(x) ((x)*(x))
#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))
#define endl '\n'
#define MOD7 ((int) 1e9+7)
#define MOD9 ((int) 1e9+9)

void solve() {
    make(int, t);
    FOR(test, t){
        make(int, n);
        make(string, s);
        int first = -1, last = -1;
        FOR(i, n){
            if (s[i] == '1' && first == -1){
                first = i;
            }
            if (s[i] == '1') last = i;
        }

        if (first == -1){
            cout << n << endl;
            continue;
        }

        int max_len = max(last, n-first-1);
        cout << max_len*2 + 2 << endl;
    }
}

signed main(signed argc, char* argv[]) {
#ifdef AUTOTEST
    autotest tests(&solve);
        return 0;
#endif

    ios_base::sync_with_stdio(0);
    cin.tie();

    cout.setf(cout.fixed);
    cout.precision(10);

    if (argc > 1 && (string) argv[1] == "file") {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        int number_sample = 1;
        do {
            cout << "Sample #" << number_sample << ":" << endl;
            cerr << "Sample #" << number_sample << ":" << endl;

            solve();
            number_sample++;

            cout << endl;
            cerr << endl;
        } while (!cin.eof());
    } else {
        cerr.clear(ios_base::badbit);
        solve();
    }
}

vector<string> split(string s, string border){
    vector<string> ans;
    int pos_end;

    while((pos_end = s.find(border)) != string::npos){
        if (pos_end) ans.push_back(s.substr(0, pos_end));
        s = s.substr(pos_end + border.size());
    }

    return ans;
}