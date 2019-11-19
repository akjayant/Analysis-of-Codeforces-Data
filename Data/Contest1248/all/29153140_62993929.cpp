#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rg register
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
const int maxn=1e5+10,mod=1e9+7;
int n,m,f[maxn];
int main(){
    read(n),read(m);f[1]=2,f[2]=4;
    for(rg int i=3;i<=max(n,m);i++)f[i]=(f[i-1]+f[i-2])%mod;
    printf("%d\n",(((f[n]+f[m])%mod)-f[1]+mod)%mod);
}
