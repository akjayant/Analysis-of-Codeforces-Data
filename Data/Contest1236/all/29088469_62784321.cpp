#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <deque>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cassert>
#include <cstring>
#include <queue>
#include <random>

#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define mp(x, y) make_pair((x), (y))

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                if ((a - i >= 0) && (b - 2 * i - j >= 0) && (c - 2 * j >= 0)) {
                    ans = max(ans, 3 * (i + j));
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}