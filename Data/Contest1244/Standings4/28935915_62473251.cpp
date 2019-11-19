#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        char s[1001];
        int n,ans=0;
        scanf("%d",&n);
        scanf("%s",s);
        for (int i=0;i<strlen(s);i++) {
            if (s[i]=='1') ans=max(max(ans,(i+1)<<1),(n-i)<<1);
        }
        if (ans==0) printf("%d\n",n);
        else 
        printf("%d\n",ans);
    }
    return 0;
}
