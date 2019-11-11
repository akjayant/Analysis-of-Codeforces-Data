#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:(gcd(b,a%b));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(gcd(a,b)!=1)cout<<"Infinite"<<endl;
		else cout<<"Finite"<<endl;
	}
	return 0;
}
