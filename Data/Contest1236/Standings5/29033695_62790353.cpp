#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
#define vi vector<int>
#define pi pair<int,int>

const int M=1e9+7;
const int MXN=1e5+10;

int power(int a,int b){
	int res=1;
	a%=M;
	while(b){
		if(b&1)res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}

int32_t main(){
	fast;
	int n,m;
	cin>>n>>m;
	int ans = power(2,m)+M-1;
	ans = power(ans,n);
	cout << ans << endl;
	return 0;
}