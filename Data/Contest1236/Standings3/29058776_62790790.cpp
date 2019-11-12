#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
const int mo=1e9+7;
int n,m;
inline int ksm(int x,int y)
{
	int res=1;
	while(y) { if(y&1) res=1ll*res*x%mo; x=1ll*x*x%mo; y>>=1; }
	return res;
}
int main()
{
	n=read(),m=read();
	printf("%d\n",ksm((ksm(2,m)-1+mo)%mo,n));
	return 0;
}