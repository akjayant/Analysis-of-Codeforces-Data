#include <bits/stdc++.h>
using namespace std;

char s[10010];
char t[10010];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        scanf("%s%s", s+1, t+1);
        int id = -1;
        bool ok = true;
        for(int i=1; i<=n; i++) {
            if(s[i]!=t[i]) {
                if(id<0)
                    id = i;
                else if(id==0) {
                    ok = false;
                    break;
                }
                else {
                    if(s[id]!=s[i] || t[id]!=t[i]) {
                        ok = false;
                        break;
                    }
                    id = 0;
                }
            }
        }
        if(id>0)
            ok = false;
        if(ok)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
