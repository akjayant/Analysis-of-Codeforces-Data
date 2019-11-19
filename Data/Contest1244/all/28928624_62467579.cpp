#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,T;
char s[maxn];
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans=n;
        for (int i=1;i<=n;i++)
            if (s[i]=='1') ans=max(ans,max(2*i,2*(n-i+1)));
        printf("%d\n",ans);
    }
    return 0;
}
