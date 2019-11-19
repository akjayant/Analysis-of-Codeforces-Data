#include<bits/stdc++.h>
using namespace std;
long long n,a[300000],l,r,k,x;
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    l=1,r=n;
    while(a[l]<a[r]&&k){
	if(l<=n-r+1){
	    if(k>=1ll*(a[l+1]-a[l])*l){
		k=k-1ll*(a[l+1]-a[l])*l;
		l++;
		continue;
	    }
	    a[l]+=k/((long long)l);
	    break;
	}
	long long x=n-r+1;
	if(k>=x*(a[r]-a[r-1])){
	    k-=x*(a[r]-a[r-1]);
	    r--;
	    continue;
	}
	a[r]-=k/x;
	break;
    }
    printf("%lld",a[r]-a[l]);
}