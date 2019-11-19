#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
	ll t,i,j,k,l,n,m,a,b,x,y,c;
	cin>>n;
	vector<ll> V;
	for(i=0;i<n;++i){
		cin>>l;
		V.push_back(l);
	}
	sort(V.begin(),V.end());
	x=0;y=0;
	for(i=0;i<V.size();++i){
		x+=V[i];
	}
	for(i=0;i<V.size()/2;++i){
		y+=V[i];
	}
	x-=y;
	cout<<x*x+y*y<<"\n";

	return 0;
}