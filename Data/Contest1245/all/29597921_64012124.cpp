#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
const int N=1e5+28,p=1e9+7;
char s[N];
int f[N];
signed main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='w'||s[i]=='m'){
            puts("0");
            return 0;
        }
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(s[i]==s[i-1]){
            if(s[i]=='u'||s[i]=='n'){
                f[i]=(f[i]+f[i-2])%p;
            }
        }
    }
    printf("%d",f[n]);
    return 0;
}
