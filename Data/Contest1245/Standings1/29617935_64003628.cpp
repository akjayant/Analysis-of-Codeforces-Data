#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

const int N = 1e6 + 5;

int n, ans = 1, f[N];
std::string str;

int main() {
    std::cin >> str;
    n = str.size(); f[1] = 1;
    for (int i = 2; i <= n + 2; i++) { f[i] = add(f[i - 1], f[i - 2]); }
    str = str + " ";
    char lst = '?'; int cnt = 1;
    for (int i = 0; i <= n; i++) {
        if (lst != str[i]) {
            if (lst == 'u' || lst == 'n') {
                ans = 1ll * ans * f[cnt + 1] % mod;
            }
            if (lst == 'm' || lst == 'w') {
                ans = 0;
            }
            cnt = 0;
        }
        lst = str[i]; cnt++;
    }
    printf("%d\n", ans);
    return 0;
}