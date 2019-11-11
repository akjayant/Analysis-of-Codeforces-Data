#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 110;
int T, n, a, b, c;
int ans[maxn];
char str[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        scanf("%s", str);
        memset(ans, -1, sizeof(ans));
        int cnt = 0;
        for (int i = 0;i < n; ++i) {
            if(str[i] == 'S' && a) --a, ++cnt, ans[i] = 0;
            else if(str[i] == 'R' && b) --b, ++cnt, ans[i] = 1;
            else if(str[i] == 'P' && c) --c, ++cnt, ans[i] = 2;
        }
        int m = n+1>>1;
        if(cnt >= m) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                if(ans[i] == -1) {
                    if(a) --a, ans[i] = 0;
                    else if(b) --b, ans[i] = 1;
                    else if(c) --c, ans[i] = 2;
                }
            }
            for (int i = 0; i < n; ++i) {
                if(ans[i] == 0) printf("R");
                else if(ans[i] == 1) printf("P");
                else printf("S");
            }
            puts("");
        } else {
            puts("NO");
        }
    }
    return 0;
}