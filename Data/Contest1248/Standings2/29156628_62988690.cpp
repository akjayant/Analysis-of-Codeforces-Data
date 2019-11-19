#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define int ll
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=100010,Mod=1e9+7;
int n,m,a[N],b[N];
signed main(){
	n=gi();m=gi();
	a[1]=2;a[2]=4;b[1]=0;b[2]=2;
	for(int i=3;i<=n;i++)a[i]=(a[i-1]+a[i-2])%Mod;
	for(int i=3;i<=m;i++)b[i]=(b[i-1]+b[i-2])%Mod;
	a[1]=a[n];
	for(int i=2;i<=m;i++)a[i]=(a[i-1]+b[i])%Mod;
	printf("%lld\n",a[m]);
	return 0;
}
