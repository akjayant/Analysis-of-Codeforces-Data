#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cassert>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main() {
    kekek;
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> kek(n);
        for (auto &i : kek) cin >> i;
        sort(kek.begin(), kek.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(n - i, kek[i]));
        }
        cout << ans << '\n';
    }

   // system("pause");
    return 0;
}