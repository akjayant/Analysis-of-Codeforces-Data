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

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            if (j % 2 == 0) {
                t = j * n + 1 + i;
            } else {
                t = (j+1) * n - i;
            }
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
