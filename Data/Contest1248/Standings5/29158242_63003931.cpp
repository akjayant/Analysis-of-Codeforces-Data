#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	ll int fb[100002];
	fb[0] = 1;
	fb[1]=1;
	int i;
	for(i=2;i<100002;i++){
		fb[i] = (fb[i-1]%mod + fb[i-2]%mod)%mod; 
	}
	ll int n,m;
	cin>>n>>m;
	m--;
	ll int row_start = fb[n]%mod;
	ll int col_start = 0;
	for(i=0;i<m;i++){
		col_start = (col_start%mod + fb[i]%mod)%mod;
	}
	ll int ans = ((row_start%mod + col_start%mod)*2)%mod;
	cout<<ans<<endl;
	return 0;
}