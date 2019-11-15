#include <bits/stdc++.h>

int T, n, a, b, c;
std::string s, t;

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> n; // RPS.
        std::cin >> a >> b >> c >> s;
        t = std::string(n, '?');
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R' && b > 0) {
                t[i] = 'P'; b--;    
            }
            if (s[i] == 'P' && c > 0) {
                t[i] = 'S'; c--;    
            }
            if (s[i] == 'S' && a > 0) {
                t[i] = 'R'; a--;    
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i] == '?') {
                if (a > 0) {
                    t[i] = 'R'; a--;
                } else if (b > 0) {
                    t[i] = 'P'; b--;
                } else if (c > 0) {
                    t[i] = 'S'; c--;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R' && t[i] == 'P') { cnt++; }
            if (s[i] == 'P' && t[i] == 'S') { cnt++; }
            if (s[i] == 'S' && t[i] == 'R') { cnt++; }
        }
        if (cnt >= (n + 1) / 2) {
            std::cout << "YES\n";
            std::cout << t << std::endl;
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}