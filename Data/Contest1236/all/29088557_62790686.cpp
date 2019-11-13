#include<bits/stdc++.h>
using namespace std;
#define int long long
int M=1e9+7;

int power(int a, int b){
	int r=1;int x=a;
	while(b){
		if(b&1){
			r=(r*x)%M;
		}
		x=(x*x)%M;
		b/=2;

	}
	return r;
}

int32_t main(){
	int n,m;cin>>n>>m;
	int a=power(2,m);
	a=(a+M-1)%M;
	int ans=power(a,n);
	cout<<ans<<endl;







	return 0;
}