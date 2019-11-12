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

int a[10010];

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
		cin >> n;
		for(int i = 0 ; i < n ; ++i) cin >> a[i];
		sort(a , a + n);
		int ans = 0 ;
		for(int i = n ; i > 0 ; --i){
			if(a[n - i] >= i){
				ans = i ;
				break;
			}
		}
		cout << ans << endl;
	}
}