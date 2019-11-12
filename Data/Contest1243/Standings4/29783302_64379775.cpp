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
const ll oo = 1e9 + 7 ;
const double PI = acos(-1) ;
const ll M = 1e9 + 7  ;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input" , "r" , stdin );
		freopen("output" , "w" , stdout );
	#endif
	int k ;
	cin >> k;
	while(k--){
		int n;
		string s , t , ans = "yes" ;
		cin >> n >> s >> t;
		char a , b ;
		int co = false ;
		for(int i = 0 ; i < n ;++i){
			if(s[i] != t[i] && co == 2){
				ans = "no";
				break;
			}else if(s[i] != t[i] && co == 1 && (a != s[i] || b != t[i])){
				ans = "no";
				break;
			}else if(s[i] != t[i] && co == 1 && (a == s[i] && b == t[i])){
				co = 2;
			}else if(s[i] != t[i] && !co) a = s[i] , b = t[i] , co = 1;
		}
		if(co == 1) ans = "no";
		cout << ans << endl;
	}
}