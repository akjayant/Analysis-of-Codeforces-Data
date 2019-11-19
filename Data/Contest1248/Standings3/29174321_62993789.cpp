#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
const int mod=1e9+7;
int n,m,f[N];
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
signed main(){
    n=read(),m=read();
    f[1]=2,f[2]=4;
    for(int i=3;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%mod;
    printf("%lld\n",(f[n]+f[m]-2)%mod);
    return 0;
}
