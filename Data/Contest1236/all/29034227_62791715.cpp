#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000];

int main() {
    int n;
    cin >> n;
    int m = n*n;
    for (int i = 0; i < n; ++i) {
        if (i&1) {
            for (int j = 0; j < n; ++j) {
                g[j].push_back(m--);
            }
        } else {
            for (int j = n-1; j >= 0; --j) {
                g[j].push_back(m--);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", g[i][j]);
        }
        puts("");
    }
    return 0;
}