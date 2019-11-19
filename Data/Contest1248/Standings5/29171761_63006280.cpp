#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll solve(ll n){
	ll i,j;
	ll M[n+1]={0};
	for(i=0;i<=n;++i)M[i]=0;
	ll even = 0;
	ll odd = 0;
	for(i=1;i<=n;++i){
		if(i%2==1){
			M[i] = (M[i] + even + (i/2))%MOD;
			odd = (M[i] + odd)%MOD;
		}else{
			M[i] = (M[i] + odd + (i/2))%MOD;
			even = (M[i] + even)%MOD;
		}
	}
	return M[n];
}


int main(){
	ll t,i,j,k,l,n,m,a,b,x,y,c;
	
	cin>>n>>m;

	cout<<(2*(solve(n)+solve(m) + 1))%MOD;


	return 0;
}