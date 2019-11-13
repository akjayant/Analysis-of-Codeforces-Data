#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void solve() {
    arr.clear();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int ans = 1;
    for (int i = n-1; i >= 0; i--) {
        ans = max(ans, min(n-i, arr[i]));
    }
    printf("%d\n", ans);
}

int main() {
    int qt;
    scanf("%d", &qt);
    for (int q = 0; q < qt; q++) solve();
}
