#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}




signed main() {
    accell();
    int q;
    cin >> q;
    while(q--) {
        //cout << q << endl;
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        map<char, int>mp;
        for(int i = 0; i < a.size(); ++i) {
            mp[a[i]]++;
            mp[b[i]]++;
        }
        bool flag = false;
        for(auto it : mp) {
            if (it.S & 1) {
                flag = true;
            }
        }
        if (flag) {
            cout << "No" << '\n';
            continue;
        }
        vector<pair<int, int> > ans;
        for(int i = 0; i < n; ++i) {
            char x = a[i];
            char y = b[i];
            if (x == y)
                continue;
            flag = false;
            for(int j = i + 1; j < n; ++j) {
                char cur = a[j];
                if (cur == x) {
                    flag = true;
                    ans.push_back({j + 1, i + 1});
                    swap(a[j], b[i]);
                    // cout << 1 << " " << j << endl;
                    break;
                }
                cur = b[j];
                if (cur == y) {
                    flag = true;
                    ans.push_back({i + 1, j + 1});
                    swap(b[j], a[i]);
                    // cout << 2 << " " << j << endl;
                    break;
                }
                cur = a[j];
                if (cur == y) {
                    flag = true;
                    ans.push_back({j + 1, j + 1});
                    swap(a[j], b[j]);
                    ans.push_back({i + 1, j + 1});
                    swap(a[i], b[j]);
                   // cout << 3 << " " << j << endl;
                    break;
                }
                cur = b[j];
                if (cur == x) {
                    flag = true;
                    ans.push_back({j + 1, j + 1});
                    swap(a[j], b[j]);
                    ans.push_back({j + 1, i + 1});
                    swap(a[j], b[i]);
                  //  cout << 4 <<" " << j << endl;
                    break;
                }
            }

        }
        cout << "Yes" << '\n';
        cout << ans.size() << '\n';
        for(auto it : ans)
            cout << it.F << " " << it.S << '\n';
    }
    return 0;
}
