/*
░░░░██████████████████
░░▄███████▀▀▀▀▀▀███████▄
░▐████▀▒mohammad▒▀██████▄
░███▀▒▒▒▒alaa▒▒▒▒▒▒▀█████
░▐██▒▒▒alwrawrah▒▒▒▒▒████▌
░▐█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
░░█▒▄▀▀▀▀▀▄▒▒▄▀▀▀▀▀▄▒▐███▌
░░░▐░░░▄▄░░▌▐░░░▄▄░░▌▐███▌
░▄▀▌░░░▀▀░░▌▐░░░▀▀░░▌▒▀▒█▌
░▌▒▀▄░░░░▄▀▒▒▀▄░░░▄▀▒▒▄▀▒▌
░▀▄▐▒▀▀▀▀▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒█
░░░▀▌▒▄██▄▄▄▄████▄▒▒▒▒█▀
░░░░▄██████████████▒▒▐▌
░░░▀███▀▀████▀█████▀▒▌
░░░░░▌▒▒▒▄▒▒▒▄▒▒▒▒▒▒▐
░░░░░▌▒▒▒▒▀▀▀▒▒▒▒▒▒▒▐
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll ;
const ll oo = 1e13 ;
const double PI = acos(-1) ;
const ll M = 1e9 + 7  ;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input" , "r" , stdin );
		freopen("output" , "w" , stdout );
	#endif
	ll n  ;
	cin >> n;
	ll n1 = n , ans = n , co = 0 ;
	for(ll i = 2 ; i * i <= n ; ++i){
		if(n % i == 0){
			ans = i;
			co++;
			while(n % i == 0) n /= i;
		}
	}
	if(co > 1) ans = 1 ;
	if(n1 != n && n != 1) ans = 1 ;
	cout << ans << endl;
}