#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	fast;
	ll k;
	cin>>k;
	while(k--){
		string s,t;
		ll n;
		cin>>n>>s>>t;
		ll diff=0;
		ll p1,p2;
		for(ll i=0;i<n;i++){
			if(s[i]!=t[i]){
				diff++;
				if(diff==1)p1=i;
				if(diff==2)p2=i;
			}
		}
		if(diff==2){
			if(s[p1]==s[p2] &&t[p1]==t[p2])cout<<"YES\n";
			else cout<<"NO\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
