#include <bits/stdc++.h>

const int N = 100 + 5;

char chs[N], ran[N], end;
int n, cr, cp, cs, r, p, s;

int main() {
    int T_T;
    scanf("%d", &T_T);
    while (T_T--) {
        scanf("%d", &n);
        scanf("%d %d %d", &r, &p, &s);
        scanf("%s", chs);
        cr = cp = cs = 0;
        for (int i = 0; i < n; i++) {
            if (chs[i] == 'R') cr++;
            if (chs[i] == 'P') cp++;
            if (chs[i] == 'S') cs++;
        }
        int tmp = std::min(r, cs) + std::min(p, cr) + std::min(s, cp);
        if (tmp >= (n + 1) / 2) {
            puts("YES");
            for (int i = 0; i < n; i++) {
                if (chs[i] == 'R') {
                    cr--;
                    if (p) p--, putchar('P');
                    else {
                        if (r - cs > s - cp) r--, putchar('R');
                        else s--, putchar('S');
                    }
                } else if (chs[i] == 'P') {
                    cp--;
                    if (s) s--, putchar('S');
                    else {
                        if (r - cs > p - cr) r--, putchar('R');
                        else p--, putchar('P');
                    }
                } else if (chs[i] == 'S') {
                    cs--;
                    if (r) r--, putchar('R');
                    else {
                        if (p - cr > s - cp) p--, putchar('P');
                        else s--, putchar('S');
                    }
                }
            }
            puts("");
        } else puts("NO");
    }
    return 0;
}