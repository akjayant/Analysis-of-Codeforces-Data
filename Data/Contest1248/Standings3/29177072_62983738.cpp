#include<bits/stdc++.h>
#define FIN freopen("./B.in","r",stdin)
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
ll T,n,a[maxn],ans;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	ans=pow(a[n/2],2)+pow(a[n]-a[n/2],2);
	cout<<ans<<"\n";
}
