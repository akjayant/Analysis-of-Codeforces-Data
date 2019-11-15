#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
#define vi vector<int>
#define pi pair<int,int>

const int M=1e9+7;
const int MXN=1e5+10;

int n;

vi v[1005];

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
	cin>>n;
	int cnt=n*n;

	for(int i=0;i<n;++i){
		for(int j=0;j<n && i%2==0;++j){
			v[j].pb(cnt--);
		}
		for(int j=n-1;j>=0 && i%2;--j){
			v[j].pb(cnt--);
		}

	}
	for(int i=0;i<n;++i){
		for(int j:v[i])cout << j << ' ';
		cout << endl;
	}
	return 0;
}