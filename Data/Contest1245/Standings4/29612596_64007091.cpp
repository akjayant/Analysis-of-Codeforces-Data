//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

char str[105];
int n;

bool solve(int r, int p, int s, string &ans) {
    ans = string(str);
    for (auto &x:ans) x = '-';
    int w = 0;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == 'R' && p) {
            --p;
            ++w;
            ans[i] = 'P';
        } else if (str[i] == 'P' && s) {
            --s;
            ++w;
            ans[i] = 'S';
        } else if (str[i] == 'S' && r) {
            --r;
            ++w;
            ans[i] = 'R';
        }
    }
    if (w * 2 < n) return 0;
    for (auto &x:ans) {
        if (x == '-') {
            if (r) {
                x = 'R';
                --r;
            } else if (s) {
                x = 'S';
                --s;
            } else if (p) {
                x = 'P';
                --p;
            }
        }
    }
    return 1;
}

int main() {
    //freopen("in.txt", "rt", stdin);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        scanf("%s", str);
        string ans;
        if (solve(a, b, c, ans)) {
            printf("YES\n%s\n", ans.c_str());
        } else puts("NO");
    }
}