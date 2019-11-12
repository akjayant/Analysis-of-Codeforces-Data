#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> getans(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int l = 1, r = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j += 2) {
            ans[i][j-1] = l++;
            ans[i][j] = r--;
        }
    }

    if (n & 1) {
        for (int i = 0; i < n; i++) {
            ans[i][n-1] = l++;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    auto ans = getans(n);
    for (auto v : ans) {
        for (auto x : v) {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}
