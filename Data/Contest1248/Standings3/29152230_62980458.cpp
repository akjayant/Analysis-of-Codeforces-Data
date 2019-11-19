#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, m, t;
vector<int> a;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    long long b = 0, c = 0;
    for (int i = 0; i < n / 2; i++) {
        b += a[i];
    }
    for (int i = n / 2; i < n; i++) {
        c += a[i];
    }
    long long ans = b *b  + c *c;
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}