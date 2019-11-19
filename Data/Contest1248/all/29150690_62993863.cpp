#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
const int N=1e5+28,p=1e9+7;
int n,m,f[N];
signed main(){
    n=read(),m=read();
    f[1]=2,f[2]=4;
    for(int i=3;i<=max(n,m);i++)f[i]=(f[i-1]+f[i-2])%p;
    int ans=(f[n]+f[m]+p-f[1])%p;
    printf("%lld",ans);
    return 0;
}
/*
2 3
*/
