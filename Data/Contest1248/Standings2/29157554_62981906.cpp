// Volgograd STU: Zeber
#pragma GCC optimize ("O3")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <random>
#include <ctime>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef unsigned char si;

#define mp make_pair
#define pb push_back

using namespace std;
#define PI acos(-1.0)

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(auto& it : x) {
        cin >> it;
    }

    sort(x.rbegin(), x.rend());

    LL res1 = 0, res2 = 0;
    for(int i = 0; i < n / 2; ++i) {
        res1 += x[i];
        res2 += x[n - i - 1];
    }
    if(n & 1) {
        res1 += x[n / 2];
    }
    //cout << res1 << ' ' << res2 << endl;
    cout << res1 * res1 + res2 * res2 << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //test(); return 0;
    //cout.setf(ios::fixed);
    //cout.precision(2);

    //time_t cur = time(NULL);
    //freopen("wifi.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //srand(time(NULL));
    int test = 1;
    //cin >> test;
    //scanf("%d", &test); int n = test;
    while (test-- > 0) {
        //cout << "Case #" << n - test << ": ";
        solve();
    }

    //cerr << (time(NULL) - cur) << endl;

    return 0;
}