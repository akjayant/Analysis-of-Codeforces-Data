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

//#define int long long

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

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = n + 1, r = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
                if (i < l) {
                    l = i;
                }
                if (i > r) {
                    r = i;
                }
            }
        }
        int ans1 = n + cnt;
        int ans2 = max(2 * (n - l), 2 * (r + 1));
        cout << max(ans1, ans2) << endl;
    }
}