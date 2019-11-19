#include<iostream>
#include<cstdio>
const int N=1005;
int T,n;
char s[N];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%s",&n,s+1);
        int ans=n;
        for(int i=1;i<=n;i++) {
            if(s[i]=='1') {
                int t=std::max(i,n-i+1);
                ans=std::max(ans,t+t);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
