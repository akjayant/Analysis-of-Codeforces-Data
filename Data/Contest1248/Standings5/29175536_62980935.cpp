#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],xsum,ysum,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++){
		xsum+=a[i];
	}
	for(int j=n/2+1;j<=n;j++){
		ysum+=a[j];
	}
	ans=xsum*xsum+ysum*ysum;
	printf("%lld\n",ans);
	return 0;
}