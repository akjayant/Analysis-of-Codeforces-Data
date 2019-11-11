#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int n, a, b, c;
        char s[105];
        scanf("%d %d %d %d %s", &n, &a, &b, &c, s);
        char ans[105] = "";
        int win = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (b > 0) {
                    b--;
                    ans[i] = 'P';
                    win++;
                }
            }
            if (s[i] == 'P') {
                if (c > 0) {
                    c--;
                    ans[i] = 'S';
                    win++;
                }
            }
            if (s[i] == 'S') {
                if (a > 0) {
                    a--;
                    ans[i] = 'R';
                    win++;
                }
            }
        }
        if (win * 2 < n) {
            printf("NO\n");
        }
        else {
            for (int i = 0; i < n; i++) {
                if (ans[i] == 0) {
                    if (a > 0) {
                        --a;
                        ans[i] = 'R';
                    }
                    else if (b > 0) {
                        --b;
                        ans[i] = 'P';
                    }
                    else if (c > 0) {
                        --c;
                        ans[i] = 'S';
                    }
                }
            }
            printf("YES\n");
            printf("%s\n", ans);
        }
    }
}