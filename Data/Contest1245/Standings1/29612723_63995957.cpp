#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		ll x,y;cin >> x >> y;
		x=gcd(x,y);
		if(x==1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
}