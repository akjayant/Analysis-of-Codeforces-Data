#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
int main(){
    int T, n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s+1); int ans=n;
        for(int i=1;i<=n;i++){
            if(s[i]=='1') ans=max(ans,max(i,n-i+1)+max(i,n-i+1));
        }
        printf("%d\n",ans);
    }
    return 0;
}
