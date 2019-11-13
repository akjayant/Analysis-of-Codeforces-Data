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
        string s, t;
        cin >> n >> s >> t;
        set<int> ne;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                ne.insert(i);
            }
        }
        if (ne.size() == 0) {
            cout << "Yes\n";
        }
        if (ne.size() != 2) {
            cout << "No\n";
        }
        else {
            int i1 = *ne.begin();
            ne.erase(i1);
            int i2 = *ne.begin();
            char c1 = s[i1], c2 = s[i2], c3 = t[i1], c4 = t[i2];
            if (c4 == c3 && c1 == c2) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}