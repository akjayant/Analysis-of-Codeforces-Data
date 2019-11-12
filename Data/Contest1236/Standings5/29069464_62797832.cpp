#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int mod=1e9+7;
inline int ksm(int x,int k){
	int s=1;
	for(;k;k>>=1,x=1ll*x*x%mod)if(k&1)s=1ll*s*x%mod;
	return s;
}
int main(){
	int n=read(),m=read();
	cout<<ksm(ksm(2,m)-1,n)<<"\n";
	return 0;
}
