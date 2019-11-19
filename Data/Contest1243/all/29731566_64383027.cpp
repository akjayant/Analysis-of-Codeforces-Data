#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
int main(){
	ll n; cin>>n;
	ll tmp=n;
	int cnt=0; ll that;
	for(ll i=2; i*i<=n; i++){
		if(n%i==0){
			cnt++; that=i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1){ cnt++; that=n;}
	if(cnt>1) cout<<1<<endl;
	else if(cnt==1) cout<<that<<endl;
	else cout<<tmp<<endl;
	return 0;
}