#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define INF 0x3f3f3f3f
#define show(x) cerr<<#x<<" : "<<x<<'\n';
#define yogeshk972() cerr<<"\nTime Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
clock_t time_p=clock();

using namespace std;
const int N=2e5+1, mod= 1e9+7;


int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int a,b,c,res=0;
		cin>>a>>b>>c;
		
		for(int i=0;i<=a && b-2*i>=0 ;i++){
			int  y= b-2*i;
			if( 2*y<=c ) res=max( res, 3*i+y+2*y );
			else res=max(res, 3*i + c/2 + 2*(c/2) );
		}
		
		cout<<res<<"\n";
	}
	
    yogeshk972();
}
