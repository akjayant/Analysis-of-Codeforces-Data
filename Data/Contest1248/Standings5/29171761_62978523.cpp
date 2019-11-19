#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
	ll t,i,j,k,l,n,m,a,b,x,y,c;
	cin>>t;
	while(t--){
		cin>>n;
		ll odd=0,even=0;
		ll odd1=0,even1=0;
		for(i=0;i<n;++i){
			cin>>l;
			if(l%2)
				even++;
			else
				odd++;
		}
		cin>>n;
		for(i=0;i<n;++i){
			cin>>l;
			if(l%2)
				even1++;
			else
				odd1++;
		}

		cout<<odd*odd1 + even1*even<<"\n";
	}


	return 0;
}