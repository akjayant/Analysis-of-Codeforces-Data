#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		
		ll a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		
		ll a1=a/c;
		if(a%c){
			a1++;
		}
		
		ll b1=b/d;
		
		if(b%d){
			b1++;
		}
		
		if(a1+b1<=k){
			cout<<a1<<" "<<b1<<" "<<endl;
		}else{
			cout<<-1<<endl;
		}
		
	}
	
	
	return 0;
}
