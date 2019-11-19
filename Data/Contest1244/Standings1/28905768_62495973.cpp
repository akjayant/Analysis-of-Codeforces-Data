#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,k,a[N],pref[N];
int sum(int l,int r){
	if(r<0||l<0||l>=n||r>=n)return 0;
	return pref[r]-(l?pref[l]:0);
}
int cmin(int x){
	int y=lower_bound(a,a+n,x)-a;
	y--;
	return (y+1)*x-sum(0,y);
}int cmax(int x){
	int y=upper_bound(a,a+n,x)-a;
	return sum(y-1,n-1)-(n-y)*x;
}
bool check(int d){
	int op=2e18;
	for(int i=0;i<n;++i){
		int l=a[i],r=a[i]+d;
		op=min(op,cmax(r)+cmin(l));
		l=a[i]-d,r=a[i];
		op=min(op,cmax(r)+cmin(l));
	}
	return op<=k;
}
signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	pref[0]=a[0];
	for(int i=1;i<n;++i)pref[i]=pref[i-1]+a[i];
	int l=0,r=2e9,med;
	while(r-l>1){
		med=(r+l)/2;
		if(check(med))r=med;
		else l=med;
	}
	if(check(l))cout<<l;
	else cout<<r;
}