#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,k,i,u;
int main(){
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>a>>b>>c>>d>>k;
		u=(a-1)/c+1;
		if(u<k && (k-u)*d>=b) cout<<u<<" "<<k-u<<endl;
		else cout<<"-1"<<endl;
	}
}