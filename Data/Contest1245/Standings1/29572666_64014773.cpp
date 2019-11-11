#include<bits/stdc++.h>
using namespace std;
const int N=100010,p=1000000007;
int n,f[N],ans=1;
char s[N];
int main(){
    f[0]=f[1]=1;f[2]=2;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=3;i<=n;++i)f[i]=(2LL*f[i-2]+f[i-3])%p;
    for(int i=1,t=0;i<=n+1;++i){
        if(i>n||s[i]!=s[i-1]){
            ans=1LL*ans*f[t]%p;
            t=0;
        }
        if(s[i]=='n'||s[i]=='u')++t;
        if(s[i]=='m'||s[i]=='w'){
            printf("0");
            return 0;
        }
    }
    printf("%d",ans);
}