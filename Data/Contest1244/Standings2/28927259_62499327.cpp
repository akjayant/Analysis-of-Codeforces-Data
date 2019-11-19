#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=22e4;

ll a[N];
int main(){
	ios::sync_with_stdio(0);
	int n;
	ll k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	a[n]=1ll<<60;
	int l=0,r=n-1;
	while(l<r){
		while(l<n-1 && a[l]==a[l+1])++l;
		while(r>1 && a[r]==a[r-1])--r;
		if(l+1<=n-r){
			if(ll(l+1)*(a[l+1]-a[l])>k){
				a[l]+=k/(l+1);
				break;
			}
			k-=ll(l+1)*(a[l+1]-a[l]);
			a[l]=a[l+1];
		}
		else {
			if(ll(n-r)*(a[r]-a[r-1])>k){
				a[r]-=k/(n-r);
				break;
			}
			k-=ll(n-r)*(a[r]-a[r-1]);
			a[r]=a[r-1];
		}
	}
	cout<<max(a[r]-a[l],0ll);
	return 0;
}