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
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        ++m[v];
    }
    while (true) {
        auto it1 = m.begin();
        auto it2 = m.end();
        --it2;
        if (it1 == it2) {
            break;
        }
        if (min(it1->second, it2->second) > k) {
            break;
        }
        if (it1->second < it2->second) {
            auto it = it1;
            ++it;
            int cn = it1->second, cur = it1->first, next = it->first;
            int add = min(next - cur, k / cn);
            m.erase(it1);
            m[cur + add] += cn;
            k -= add * cn;
            //cout << cur + add << ' ' << k << endl;
        } else {
            auto it = it2;
            --it;
            int cn = it2->second, cur = it2->first, next = it->first;
            int add = min(cur - next, k / cn);
            m.erase(it2);
            m[cur - add] += cn;
            k -= add * cn;
            //cout << cur - add << ' ' << k << endl;
        }
    }
    auto it1 = m.begin();
    auto it2 = m.end();
    --it2;
    cout << it2->first - it1->first << endl;
}