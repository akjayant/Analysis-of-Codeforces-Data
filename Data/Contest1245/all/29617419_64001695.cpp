#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, n;
        std::string s;
        std::cin >> n >> a >> b >> c >> s;
        std::vector<int> v[3];
        for (int i = 0; i < s.size(); i++) {
            auto cc = s[i];
            if (cc == 'R') v[0].push_back(i);
            else if (cc == 'P') v[1].push_back(i);
            else v[2].push_back(i);
        }
        int ba = v[0].size(), bb = v[1].size(), bc = v[2].size();
        int w = std::min(a, bc) + std::min(b, ba) + std::min(c, bb);
        if (w < (n + 1) / 2) {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
        std::string ret(s.size(), '0');
        for (int i = 0; i < std::min(a, bc); i++) ret[v[2][i]] = 'R';
        for (int i = 0; i < std::min(b, ba); i++) ret[v[0][i]] = 'P';
        for (int i = 0; i < std::min(c, bb); i++) ret[v[1][i]] = 'S';
        auto it = ret.begin();
        for (int i = std::min(a, bc); i < a; i++) {
            while (it != ret.end() && *it != '0') it++;
            *it++ = 'R';
        }
        for (int i = std::min(b, ba); i < b; i++) {
            while (it != ret.end() && *it != '0') it++;
            *it++ = 'P';
        }
        for (int i = std::min(c, bb); i < c; i++) {
            while (it != ret.end() && *it != '0') it++;
            *it++ = 'S';
        }
        std::cout << ret << std::endl;
    }

    return 0;
}
