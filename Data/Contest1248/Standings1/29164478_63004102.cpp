#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#define int long long
using namespace std;

using ll = long long;

int calc(const vector<int>& v) {
    vector<int> pref = {v[0]};
    for (int  i = 1; i < v.size(); i++) {
        pref.push_back(pref[i-1] + v[i]);
    }
    return count(begin(pref), end(pref), *min_element(begin(pref), end(pref)));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a;
    int balance = 0;
    for (int i =0; i < n; i++) {
        if (s[i] == '(') a.push_back(1);
        else a.push_back(-1);
        balance += a.back();
    }
    if (balance != 0) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    int ans = 0;
    int I = 1, J = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(a[i], a[j]);
            int res = calc(a);
            swap(a[i], a[j]);
            if (res > ans) {
                ans = res;
                I = i + 1;
                J = j + 1;
            }
        }
    }
    cout << ans << endl;
    cout << I << " " << J << endl;
}
