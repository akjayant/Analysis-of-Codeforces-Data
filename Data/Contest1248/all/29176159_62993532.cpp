#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dwn(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while('0'>ch || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch && ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
const int mod=1e9+7;
int n,m,f2[100050]={0,4,6,8},f1[100050]={0,2,4,6},f[100005];
signed main(){
    n=read(); m=read();
    if(n>m) swap(n,m);
    rep(i,4,m) f1[i]=(f1[i-1]+f1[i-2]+mod)%mod,f2[i]=(f2[i-1]+f2[i-2]-2+mod)%mod;
    f[1]=f1[m]; f[2]=f2[m];
    rep(i,3,n) f[i]=(f[i-1]+f[i-2]+2-f[1]+mod)%mod;
    printf("%lld",f[n]);
	return 0;
}