#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <stack>
#include <fstream>
#include <random>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int f = (a - 1) / c + 1;
        int s = (b - 1) / d + 1;
        if (f + s <= k) {
            cout << f << " " << s << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}