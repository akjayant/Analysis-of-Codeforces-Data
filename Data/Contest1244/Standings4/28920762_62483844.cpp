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

struct node{
    vector<node*> links;
    int id;
    bool was = false;
};

void solve() {
    make(int, n);

    VVI c(3, VI(n));
    FOR(color, 3) {
        FOR(i, n) {
            cin >> c[color][i];
        }
    }

    vector<node*> tree(n);
    FOR(i, n) tree[i] = new node;
    FOR(i, n) tree[i]->id = i;
    FOR(i, n-1){
        make(int, v);
        make(int, u);
        tree[--v]->links.push_back(tree[--u]);
        tree[u]->links.push_back(tree[v]);
    }

    FOR(i, n){
        if (tree[i]->links.size() >= 3){
            cout << -1;
            return;
        }
    }

    node* start;
    FOR(i, n){
        if (tree[i]->links.size() == 1){
            start = tree[i];
            break;
        }
    }

    int ans = -1;
    VI ans_v(n);

    FOR(c1, 3){
        FOR(c2, 3){
            if (c1 == c2) continue;

            int c3 = 3-c1-c2;
            VI colors = {c1, c2, c3};
            FOR(i, n) tree[i]->was = false;

            VI ans_now_v(n);
            int sum = 0, pos = 0;
            node* next = start;
            while (1){
                next->was = true;
                sum += c[colors[pos % 3]][next->id];
                ans_now_v[next->id] = colors[pos % 3];

                pos++;
                bool find = false;
                FOR(i, next->links.size()){
                    if (next->links[i]->was == false){
                        next = next->links[i];
                        find = true;
                        break;
                    }
                }

                if (!find){
                    break;
                }
            }

            if (ans == -1 || sum < ans){
                ans = sum;
                ans_v = ans_now_v;
            }
        }
    }

    cout << ans << endl;
    FOR(i, n){
        cout << ans_v[i]+1 << " ";
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