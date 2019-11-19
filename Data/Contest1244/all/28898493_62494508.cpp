#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stack>
#include<vector>
#include<set>
#define LL long long
using namespace std;
const int inf=0x3f3f3f3f;
const int M=600010;
const int N=1010;
inline LL read(void){
	LL f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
LL n,k,a[M],l,r,lp,rp;
signed main(void){
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	l=1,r=1;
	lp=1,rp=n;
	while (k>0&&lp<rp){
		if (l<r){
			if (k/l<a[lp+1]-a[lp]){
				printf("%I64d",a[rp]-a[lp]-k/l);
				return 0;
			}
			k-=(a[lp+1]-a[lp])*l;l++,lp++;
		}
		else{
			if (k/r<a[rp]-a[rp-1]){
				printf("%I64d",a[rp]-a[lp]-k/r);
				return 0;
			}
			k-=(a[rp]-a[rp-1])*r;r++,rp--;
		}
	}
	printf("%I64d",a[rp]-a[lp]);
	return 0;
}