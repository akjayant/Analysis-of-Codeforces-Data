#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105;

char str[N];
char ans[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, r, p, s;
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        scanf("%d%d%d", &r, &p, &s);
        scanf("%s", str);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == 'R') if(p) { p--; ans[i] = 'P'; cnt++; }
            if(str[i] == 'P') if(s) { s--; ans[i] = 'S'; cnt++; }
            if(str[i] == 'S') if(r) { r--; ans[i] = 'R'; cnt++; }
        }
        if(cnt >= (n + 1) / 2) {
            printf("YES\n");
            for(int i = 0; i < n; i++) {
                if(!ans[i]) {
                    if(r) { r--; ans[i] = 'R'; }
                    else if(p) { p--; ans[i] = 'P'; }
                    else if(s) { s--; ans[i] = 'S'; }
                }
            }
            printf("%s\n", ans);
        }
        else {
            printf("NO\n");
        }
    }
}
