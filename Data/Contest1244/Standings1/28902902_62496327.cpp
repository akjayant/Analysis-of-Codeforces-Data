#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],ans=1e9;
long long h[N],t[N],s;
long long k;
bool ck(int x){
	int l=a[1],r=a[n]-x,mid;
	long long rs=1e18;
	while(l<=r){
		mid=l+r>>1;
		int n1=upper_bound(a+1,a+n+1,mid)-a-1,n2=lower_bound(a+1,a+n+1,mid+x)-a;
		rs=min(rs,1ll*mid*n1-h[n1]+t[n2]-1ll*(mid+x)*(n-n2+1));
//		printf("%d %d %d %d %lld\n",mid,mid+x,n1,n2,rs);
		if(rs<=k)return 1;
		if(n1>n-n2+1)r=mid-1;
		else l=mid+1;
	}
	return 0;
}
int main(){
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	s=0;
	for(int i=1;i<=n;++i){
		h[i]=h[i-1]+a[i];
	}
	s=0;
	for(int i=n;i;i--){
		t[i]=t[i+1]+a[i];
	}
	int l=0,r=a[n]-a[1];
	while(l<=r){
		int mid=l+r>>1;
		if(ck(mid)){
			ans=mid;r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",ans);
}
