#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        std::string s, t;
        std::cin >> n;
        std::cin >> s >> t;
        std::vector<pair<int, int>> ans;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[j]) {
                for (int x = j + 1; x < n; x++) {
                    if (s[j] == s[x]) {
                        ans.push_back({x, j});
                        swap(s[x], t[j]);
                        break;
                    }
                }

                if (s[j] != t[j])
                for (int x = j + 1; x < n; x++) {
                    if (t[x] == s[j]) {
                        ans.push_back({n - 1, x});
                        swap(s[n - 1], t[x]);
                        ans.push_back({n - 1, j});
                        swap(s[n - 1], t[j]);
                        break;
                    }
                }

                if (s[j] != t[j]) {
                    break;
                }
            }
        }
        if (s != t) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
            std::cout << ans.size() << '\n';
            for (auto j : ans) {
                std::cout << j.first + 1 << " " << j.second + 1 << '\n';
            }
        }
    }
}
