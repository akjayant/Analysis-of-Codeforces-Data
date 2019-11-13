// CF B
// DeP
#include <cstdio>
#include <cstring>

const int MAXN = 105;

int a, b, c, n;
char S[MAXN], Ans[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(Ans, 0, sizeof Ans);
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", S+1);
        int win = 0;
        for (int i = 1; i <= n; ++i) {
            if (S[i] == 'R') {
                if (b) --b, Ans[i] = 'P', ++win;
            }
            if (S[i] == 'P') {
                if (c) --c, Ans[i] = 'S', ++win;
            }
            if (S[i] == 'S') {
                if (a) --a, Ans[i] = 'R', ++win;
            }
        }
        if (win >= (n + 1) / 2) {
            puts("YES");
            for (int i = 1; i <= n; ++i) {
                if (Ans[i]) putchar(Ans[i]);
                else {
                    if (a) --a, putchar('R');
                    else if (b) --b, putchar('P');
                    else --c, putchar('S');
                }
            }
            putchar('\n');
        } else puts("NO");
    }
    return 0;
}
