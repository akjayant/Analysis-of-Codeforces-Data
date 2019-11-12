#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>

using namespace std;
using ll=long long int;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int a, b, c;
        cin >> a >> b >> c;

        for (int i = 0; i <= min(a, b/2); ++i) {
            int t = min(b - i*2, c/2);
            ans = max(i * 3 + t * 3, ans);
        }

        cout << ans << endl;
    }

    return 0;
}
