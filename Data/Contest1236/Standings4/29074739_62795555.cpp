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
	
	int n;
	cin>>n;
	vector<int> g[n];
	for(int i=0;i<n*n;i+=n){
		if( (i/n)&1 ){
			int k=0;
			for(int j=i+n-1;j>=i;j--){
				g[k++].pb(j+1);
			}
		}else{
			for(int j=0;j<n;j++){
				g[j].pb(i+j+1);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(auto x:g[i])cout<<x<<" ";
		cout<<"\n";
	}
	
    yogeshk972();
}
