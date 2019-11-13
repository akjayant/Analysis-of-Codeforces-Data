#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
#define vi vector<int>
#define pi pair<int,int>

const int M=1e9+7;
const int MXN=1e5+10;

int32_t main(){
	fast;
	int n,t,k;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(c%2)c--;
		int x,y,ans=0;
		for(x=0;x<=a;++x){
			for(y=0;y<=b;++y){
				if(x<=a && 2*x+y<=b && 2*y<=c)ans=max(ans,3*x+3*y);
			}
		}	
		cout << ans <<endl;
	}
	return 0;
}