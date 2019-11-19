#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

int n;
string s;

int solve() {
    cin >> n >> s;
    if (s == string(n, '0'))
        return n;
    int i = 0;
    while (s[i] != '1') ++i;
    reverse(all(s));
    int j = 0;
    while (s[j] != '1') ++j;
    return 2 * n - 2 * min(i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";

    return 0;
}
