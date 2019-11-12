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

vector<pair<int,int>> ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input" , "r" , stdin );
		freopen("output" , "w" , stdout );
	#endif
	int k ;
	cin >> k;
	while(k--){
		ans.clear();
		int n;
		string s , t ;
		cin >> n >> s >> t;
		for(int i = 0 ; i < n ; ++i){
			if(s[i] != t[i]){
				int b = false; 
				for(int j = i + 1 ; j < n ; ++j)
					if(s[i] == s[j]){
						b = j ;
						break;
					}
				if(b) ans.push_back({b , i}) , swap(s[b] , t[i]);
				else{
					for(int j = i + 1 ; j < n ; ++j)
						if(s[i] == t[j]){
							b = j ;
							break;
						}
					if(b){
						ans.push_back({i , i}) , swap(s[i] , t[i]);	
						ans.push_back({i , b}) , swap(s[i] , t[b]);	
					}else{
						break;
					}
				}
			}
		}
		cout << (s == t ? "yes" : "no") << endl;
		if(s == t){
			cout << ans.size() << endl;
			for(auto x : ans)
				cout << x.first + 1 << ' ' << 1 + x.second << endl;
		}
	}
}