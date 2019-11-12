#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=1e5+10,mod=1e9+7;
int n,m,ans;
int mi(int a,int b){
    int ans=1;
    while(b){
	if(b&1)ans=1ll*ans*a%mod;
	b>>=1,a=1ll*a*a%mod;
    }
    return ans;
}
int main(){
    read(n),read(m);
    printf("%d\n",mi(mi(2,m)-1,n));
}
