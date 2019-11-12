#include <bits/stdc++.h>
using namespace std;

char s[10010];
char t[10010];
int a[20010][2];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        scanf("%s%s", s+1, t+1);
        int cnt = 0;
        bool ok = true;
        for(int i=1; i<=n; i++) {
            if(s[i]==t[i])
                continue;
            int j;
            for(j=i+1; j<=n; j++) {
                if(t[i]==t[j]) {
                    break;
                }
            }
            if(j<=n) {
                cnt++;
                a[cnt][0] = i;
                a[cnt][1] = j;
                swap(s[i], t[j]);
            }
            else {
                for(j=i+1; j<=n; j++) {
                    if(s[j]==t[i]) {
                        break;
                    }
                }
                if(j>n) {
                    ok = false;
                    break;
                }
                cnt++;
                a[cnt][0] = j;
                a[cnt][1] = j;
                swap(s[j], t[j]);
                cnt++;
                a[cnt][0] = i;
                a[cnt][1] = j;
                swap(s[i], t[j]);
            }
        }
        if(!ok)
            printf("No\n");
        else {
            printf("Yes\n");
            printf("%d\n", cnt);
            for(int i=1; i<=cnt; i++)
                printf("%d %d\n", a[i][0], a[i][1]);
        }
    }
    return 0;
}
