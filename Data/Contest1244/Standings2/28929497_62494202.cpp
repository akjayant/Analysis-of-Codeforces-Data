#include<bits/stdc++.h>
#define re register
#define LL long long
using namespace std;
inline int read() {
	char c=getchar();int x=0;while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-48,c=getchar();return x;
}
const int maxn=1e5+5;
int a[maxn],n,sz;LL k;
int b[maxn],c[maxn],d[maxn];
inline int find(int x) {
	int l=1,r=sz;
	while(l<=r) {
		int mid=l+r>>1;
		if(a[mid]==x) return mid;
		if(a[mid]<x) l=mid+1;else r=mid-1;
	}
	return 0;
}
int main() {
	n=read();cin>>k;
	for(re int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	std::sort(a+1,a+n+1);sz=std::unique(a+1,a+n+1)-a-1;
	for(re int i=1;i<=sz;i++) c[i]=a[i];
	for(re int i=1;i<=n;i++) d[find(b[i])]++;
	if(sz==1) {puts("0");return 0;}
	int Mn=d[1],Mx=d[sz],lp=2,rp=sz-1;
	while(1) {
		if(c[lp-1]==c[rp+1]) {
			puts("0");return 0;
		}
		if(Mn<Mx) {
			LL tot=1ll*(c[lp]-c[lp-1])*Mn;
			if(tot>k) {
				std::cout<<c[rp+1]-c[lp-1]-k/Mn;
				return 0;
			}
			Mn+=d[lp];lp++;k-=tot;
		}
		else {
			LL tot=1ll*(c[rp+1]-c[rp])*Mx;
			if(tot>k) {
				std::cout<<c[rp+1]-k/Mx-c[lp-1];
				return 0;
			}
			Mx+=d[rp];rp--;k-=tot;
		}
	}
	return 0;
}