#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100005
ll a[M];
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n,sz1=1,sz2=1;
	while(m){
		if(sz1<sz2){
			if(1ll*sz1*(a[l+1]-a[l])>=m){
				a[l]+=m/sz1;
				break;
			}
			else m-=1ll*sz1*(a[l+1]-a[l]),++l,sz1++;
		}
		else{
			if(1ll*sz2*(a[r]-a[r-1])>=m){
				a[r]-=m/sz2;
				break;
			}else m-=1ll*sz2*(a[r]-a[r-1]),--r,sz2++;
		}
		if(l==r)break;
	}
	printf("%lld",a[r]-a[l]);
}