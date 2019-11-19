#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
int n,m;ll f[300000];
const ll mod=1e9+7;
inline int read(){
	int x=0;scanf("%d",&x);return x;
} 
int main(){
	n=read(),m=read();
	f[0]=f[1]=1;
	for(int i=1;i<=max(n,m);i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	printf("%lld",(f[n]+f[m]-1)%mod*2%mod);
	return 0;
}