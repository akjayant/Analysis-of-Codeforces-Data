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
        for (int j = 0; j < n; j++) {
            if (s[j] != t[j]) {
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    if (t[k] == t[j] && s[j] == s[k]) {
                        swap(s[j], t[k]);
                        break;
                    }
                }
                break;
            }
        }
        if (s == t) std::cout << "Yes"; else cout << "No";
        std::cout << '\n';
    }
}
