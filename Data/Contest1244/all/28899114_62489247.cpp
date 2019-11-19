#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector <int> num(n);
    set <int> all, all1;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        all.insert(num[i]);
        all1.insert(-num[i]);
    }
    sort(num.begin(), num.end());
    map <int, int> smth;
    for (auto el : num)
        smth[el]++;
    int min_el = num[0], max_el = num.back();
    int i = 0, j = n - 1;
    int k1 = smth[min_el], k2 = smth[max_el];
    while (true) {
        if (max_el == min_el) {
            cout << "0\n";
            return 0;
        }
        if (k1 > k && k2 > k) {
            cout << max_el - min_el << "\n";
            return 0;
        }
        if (k1 < k2) {
            int kek = *all.upper_bound(min_el);
            //cout << kek << endl;
            int diff = kek - min_el;
            if (diff * k1 <= k) {
                k -= k1 * diff;
                min_el += diff;
                k1 += smth[min_el];
            }
            else {
                min_el += k / k1;
                cout << max_el - min_el << "\n";
                return 0;
            }
        }
        else {
            int kek = *all1.upper_bound(-max_el);
            kek *= -1;
            //cout << kek << endl;
            int diff = max_el - kek;
            if (diff * k2 <= k) {
                k -= k2 * diff;
                max_el -= diff;
                k2 += smth[max_el];
            }
            else {
                max_el -= k / k2;
                cout << max_el - min_el << "\n";
                return 0;
            }
        }
    }
    return 0;
}
