//Author: gkashish

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define mod 1000000007
#define x first
#define y second


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long int o1 = 0, e1 = 0, o2 = 0, e2 = 0;
        int n;
        cin >> n;
        while (n--) {
            int tmp;
            cin >> tmp;
            if (tmp & 1)
                o1++;
            else
                e1++;
        }
        cin >> n;
        while (n--) {
            int tmp;
            cin >> tmp;
            if (tmp & 1)
                o2++;
            else
                e2++;
        }
        cout << o1 * o2 + e1 * e2 << "\n";
    }

    return 0;
}
