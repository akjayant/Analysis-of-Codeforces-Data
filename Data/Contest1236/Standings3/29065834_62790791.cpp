#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=32e4,P=1e9+7;

ll fp(ll x,ll p){
	ll ans=1;
	for(;p;p>>=1){
		if(p&1)ans=ans*x%P;
		x=x*x%P;
	}
	return ans;
}
int main(){
	ll n,m;
	cin>>n>>m;
	cout<<fp((fp(2,m)-1+P)%P,n);
	return 0;
}