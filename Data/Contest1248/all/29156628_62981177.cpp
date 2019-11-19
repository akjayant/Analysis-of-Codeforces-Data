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
int n,a[100010];
signed main(){
	n=gi();
	for(int i=1;i<=n;i++)a[i]=gi();
	sort(a+1,a+n+1);
	int l=1,r=n,ret=0,L=0,R=0;
	while(ret+2<=n){
		L+=a[l];R+=a[r];l++;r--;ret+=2;
	}
	if(l==r){
		if(L<R)R+=a[r];
		else L+=a[r];
	}
	printf("%lld\n",1ll*L*L+1ll*R*R);
	return 0;
}
