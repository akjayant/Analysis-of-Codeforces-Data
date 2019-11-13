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

ll power(int a,int n){
	if(n==0) return 1;
	ll x=power(a,n/2);
	x=(x*x)%mod;
	if(n&1) return (x*a)%mod;
	return x;
}


int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	cout<<power( (power(2,m)-1+mod)%mod ,n );
	
    yogeshk972();
}
