#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mod 1000000007
using namespace std;

ll power(ll b,ll x){
	ll res=1;
	while(x>0){
		if(x&1)
			res=(res*b)%mod;
		b=(b*b)%mod;
		x>>=1;
	}
	return res%mod;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	cout<<power((power(2,m)-1),n);

	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}