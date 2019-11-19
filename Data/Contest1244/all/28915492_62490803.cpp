//#pragma gcc optimize("Ofast")
//#pragma gcc optimize("unroll-loops")
#include <iostream>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define int long long

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279
#endif

#define mp make_pair
#define mt make_tuple
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define get0 get<0>
#define get1 get<1>
#define get2 get<2>
#define get3 get<3>

#define debug(x) cerr << #x << " = " << x << " line = " << LINE << endl

typedef long long ll;
typedef long double ld;
typedef tuple<long long, long long, long long> tlll;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int SZ = 1e5 + 100;
const int INF = 1e16;
vector<int> g[SZ];
int c[3][SZ];

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[1][i];
    }
        for (int i = 0; i < n; ++i) {
        cin >> c[2][i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int leaf = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            ++cnt;
            leaf = i;
        } else if (g[i].size() > 2) {
            cout << -1;
            return 0;
        }
    }
    if (cnt != 2) {
        cout << -1;
        return 0;
    }
    vector<int> ord;
    int cur = leaf, pred = -1;
    while (true) {
        ord.push_back(cur);
        bool ok = 0;
        for (int u : g[cur]) {
            if (u != pred) {
                pred = cur;
                cur = u;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    vector<int> p = {0, 1, 2};
    vector<int> res;
    int best = INF;
    do {
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            sm += c[p[i%3]][ord[i]];
        }
        if (sm < best) {
            best = sm;
            res = p;
        }
    } while (next_permutation(all(p)));
    vector<int> col(n);
    for (int i = 0; i < n; ++i) {
        col[ord[i]] = res[i % 3];
    }
    cout << best << endl;
    for (int i = 0; i < n; ++i) {
        cout << col[i] + 1<< ' ';
    }
    cout << endl;
}