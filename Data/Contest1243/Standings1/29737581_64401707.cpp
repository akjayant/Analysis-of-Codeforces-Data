#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long n;

int main(){
	cin >> n;
	vector<ll> fact;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			fact.push_back(i);
			if(i!=(n/i))
				fact.push_back(n/i);
		}
	}
	fact.push_back(n);
	
	sort(fact.begin(),fact.end());
	ll g=0;
	for(int i=0;i<fact.size();i++){
		g=__gcd(g,fact[i]);
	}
	cout << g << endl;
	return 0;
}