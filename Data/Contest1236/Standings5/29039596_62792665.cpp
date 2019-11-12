#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
using ll=long long;


ll power(ll a,ll b){
	if(b==1)return a%M;
	ll t=power(a,b/2);
	t%=M;
	if(b&1){
		return (((t*t)%M)*a)%M;
	}
	else{
		return (t*t)%M;
	}
}
int main(){
	

	ll n,m;
	cin>>n>>m;
	ll temp=power(2,m);
	temp%=M;
	temp--;
	if(temp<0)temp+=M;
	temp=power(temp,n);
	temp%=M;
	cout<<temp;
}