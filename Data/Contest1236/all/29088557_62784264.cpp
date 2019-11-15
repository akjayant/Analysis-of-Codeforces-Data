#include<bits/stdc++.h>
using namespace std;
#define int long long
int M=1e9+7;


int32_t main(){
	int t;cin>>t;
	while(t--){
		int a,b,c;cin>>a>>b>>c;
		int ans=0;
		int x=c/2;
		int y=min(x,b);
		ans+=y+2*y;
		b-=y;
		x=b/2;
		y=min(x,a);
		ans+=y+2*y;
		cout<<ans<<endl;
	}







	return 0;
}