#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
	ll n;
	cin>>n;
	vector<ll> ans;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			ans.push_back(i);
			ans.push_back(n/i);
		}
	}	
	if(ans.size()==0)	cout<<n<<"\n";
	else{
		ll val = 0;
		for(int i=0;i<ans.size();i++){
			val = __gcd(val,ans[i]);
			// cout<<ans[i]<<"\n";
		}
		cout<<val<<"\n";
	}
	return 0;
}