#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("file.in", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        map<char, int> mapa;
        for (int i = 0; i < n; i++) {
            mapa[s[i]]++;
            mapa[t[i]]++;
        }
        bool fl = 1;
        for (auto u : mapa) {
            if (mapa[u.first] % 2 != 0) {
                cout << "No" << "\n";
                fl = 0;
                break;
            }
        }
        if (!fl)
            continue;
        vector<char> arr1(n), arr2(n);
        for (int i = 0; i < n; i++) {
            arr1[i] = s[i];
            arr2[i] = t[i];
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            int ind = i;
            if (arr1[i] == arr2[i])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (arr1[i] == arr1[j]) {
                    ind = j;
                    break;
                }
            }
            if (ind > i) {
                swap(arr1[ind], arr2[i]);
                ans.push_back({ind, i});
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (arr1[i] == arr2[j]) {
                    ind = j;
                    break;
                }
            }
            swap(arr1[i + 1], arr2[ind]);
            ans.push_back({i + 1, ind});
            swap(arr1[i + 1], arr2[i]);
            ans.push_back({i + 1, i});
        }
        cout << "Yes\n" << ans.size() << "\n";
        for (auto i : ans)
            cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}
