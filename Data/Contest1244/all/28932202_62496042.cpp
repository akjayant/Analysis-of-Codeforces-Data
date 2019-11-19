#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100005;

int n,a[N];
LL L[N],R[N];
LL k;

int BS(int val) {
	int l=1,r=n+1,mid;
	while(l+1<r) {
		mid=(l+r)>>1;
		if(a[mid]<=val)
			l=mid;
		else r=mid;
	}
	return l;
}
bool Check(int d) {
	for(LL i=1;i<=n;i++) {
		LL j=BS(a[i]+d);
		LL sl=a[i]*(i-1)-L[i-1];
		LL sr=R[j+1]-(n-j)*(a[i]+d);
		if(sl+sr<=k) return true;
	}
	for(LL j=n;j>=1;j--) {
		LL i=BS(a[j]-d);
		LL sl=(a[j]-d)*i-L[i];
		LL sr=R[j+1]-(n-j)*a[j];
		if(sl+sr<=k) return true;
	}
	return false;
}
int main() {
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		L[i]=L[i-1]+a[i];
	for(int i=n;i>=1;i--)
		R[i]=R[i+1]+a[i];
	int l=-1,r=1e9,mid;
	while(l+1<r) {
		mid=(l+r)>>1;
		if(Check(mid))
			r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
