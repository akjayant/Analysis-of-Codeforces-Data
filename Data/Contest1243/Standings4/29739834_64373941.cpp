#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <stack>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void io_optimize() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    io_optimize();
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> a (n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        int st = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[st] > st) {
                st++;
            }
            else {
                break;
            }
        }
        cout << st << '\n';
    }
    return 0;
}