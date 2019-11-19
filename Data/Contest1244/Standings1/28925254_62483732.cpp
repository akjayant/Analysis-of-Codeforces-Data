#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=1e5+5;

int n;
i64 m;
int a[N];

bool chk(int x){
	i64 s=0;int l,r;
	for(l=1,r=n;a[r]-a[l]>x;)
		if(l<=n+1-r)s+=1ll*(a[r]-a[l+1]<=x?(a[r]-x-a[l]):(a[l+1]-a[l]))*l,++l;
		else s+=1ll*(a[r-1]-a[l]<=x?(a[r]-x-a[l]):a[r]-a[r-1])*(n-r+1),--r;
	//cout<<x<<" "<<s<<endl;
	return s<=m;
}

int bnsr(int l,int r){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}

int main()
{
	int i;
	scanf("%d%I64d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d",bnsr(0,a[n]-a[1]));
	return 0;
}