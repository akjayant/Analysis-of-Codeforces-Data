#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int tests;
	int a,b;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>tests;
	while(tests--){
	    cin>>a>>b;
	    cout<<(__gcd(a,b)==1 ? "Finite" : "Infinite")<<'\n';
	}
	return 0;
}