/*----Author:HenryHuang----*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	ll ans=0;
	for(ll i=2;i<=sqrt(n);++i){
		if(n%i==0){
			ans=gcd(ans,i);
			ans=gcd(ans,n/i);
		}
	}
	cout<<gcd(ans,n)<<'\n';
	return 0;
}

