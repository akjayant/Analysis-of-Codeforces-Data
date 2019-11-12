#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    vector<vector<int>> groups;

    cin >> n;
    groups.resize(n);
    int pos = 1;
    for (int x = 0; x < (n - 1) / 2 + 1; ++x) {
        for (int i = 0; i < n; ++i) {
            groups[i].emplace_back(pos);
            ++pos;
        }
    }
    for (int x = (n - 1) / 2 + 1; x < n; ++x) {
        for (int i = n - 1; i >= 0; --i) {
            groups[i].emplace_back(pos);
            ++pos;
        }
    }

    for (auto group : groups) {
        for (auto i : group)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}