#include<bits/stdc++.h>
using namespace std;
#define ll long long 


void solve(ll n,ll p,ll w,ll d,ll mw){
	
	map<ll,ll>m;
	
	ll rem=p-mw*w;
	
	while(rem%d){
		
		if(mw<0){
			cout<<-1;
			return ;
		}
		
		rem+=w;
		
		ll j=rem%d;
		if(m[j]==1){
			cout<<-1;
			return ;
		}
		
		m[j]=1;
		mw--;
		
	}
	
	ll n1=mw+rem/d;
	if(n1>n){
		cout<<-1;
		return ;
	}
	
	ll z=n-n1;
	cout<<mw<<" "<<(rem/d)<<" "<<z;
	
	return ;
	
}
	
	
	
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
		
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	
	ll mw=p/w;
	
	if(mw>n){
		cout<<-1;
		return 0;
	}
	
	solve(n,p,w,d,mw);
	
	return 0;
}

