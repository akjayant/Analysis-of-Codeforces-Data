#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD 1000000007

int main() {
    int n; cin >> n;
    vector<vector<int>> groups;
    for(int i = 0; i < n; ++i) groups.push_back(vector<int>());
    int curr = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i % 2 == 0) {
                groups[j].push_back(curr);
            } else {
                groups[n - 1 - j].push_back(curr);
            }
            curr += 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j : groups[i]) cout << j << " ";
        cout << endl;
    }
}
