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

    LL cntCh[2][2] = {0};
    vector<int> x(n);
    for(auto& it : x) {
        cin >> it;
        ++cntCh[0][it & 1];
    }

    int m;
    cin >> m;
    vector<int> y(m);
    for(auto& it : y) {
        cin >> it;
        ++cntCh[1][it & 1];
    }

    cout << cntCh[0][1] * cntCh[1][1] + cntCh[0][0] * cntCh[1][0] << endl;
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
    cin >> test;
    //scanf("%d", &test); int n = test;
    while (test-- > 0) {
        //cout << "Case #" << n - test << ": ";
        solve();
    }

    //cerr << (time(NULL) - cur) << endl;

    return 0;
}