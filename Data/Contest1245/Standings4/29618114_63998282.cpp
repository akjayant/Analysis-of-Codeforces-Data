#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(){
	int a,b;
	cin>>a>>b;
	if(__gcd(a,b)==1)cout<<"finite\n";
	else cout<<"infinite\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}