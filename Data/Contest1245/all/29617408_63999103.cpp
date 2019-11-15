#include<bits/stdc++.h> 

using namespace std ; 

void solve() { 
	int n , a , b , c ; 
	string s ; 
	cin >> n >> a >> b >> c >> s ; 
	string res = "" ; 
	int score = 0 ; 
	vector < int > ans ; 
	for(auto x : s) { 
		if(x == 'R') { 
			// b 
			if(b) { 
				b-- ; 
				res += "P" ; 
				score++ ; 
			} else 
				res += '?' ;  
		}
		if(x == 'P') { 
			//c 
			if(c) { 
				c-- ; 
				res += "S" ; 
				score++ ; 
			} else 
				res += '?' ;  
		}
		if(x == 'S') { 
			if(a) { 
				a-- ; 
				res += "R" ; 
				score++ ; 
			} else 
				res += '?' ; 
		}
	}
	if(score >= (n + 1) / 2) { 
		cout << "YES" << endl ; 
		for(auto x : res) { 
			if(x == '?') { 
				if(a) { 
					a-- ; 
					cout << "R" ; 

				} else if(b) { 
					b-- ; 
					cout << "P" ; 
				} else { 
					c-- ; 
					cout << "S" ; 
				}
			}else 
				cout << x ; 
		}
		cout << endl ; 
	} else 
		cout << "NO" << endl ; 
}

int32_t main() { 
	int tc ; 
	cin >> tc ; 
	while(tc--) { 
		solve() ; 	
	}
}
