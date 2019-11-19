#include<bits/stdc++.h> 
using namespace std ; 

#define int long long 

int l , r ; 
int dp[35][2][2][2][2] ; 

int ans(int pos , int l0 , int r0 , int l1 , int r1) {
	if(pos == -1)
		return 1 ; 
	if(dp[pos][l0][r0][l1][r1] != -1)
		return dp[pos][l0][r0][l1][r1] ; 
	vector < int > can0 ; 
	if(l0) { 
		if(r0) { 
			can0.push_back(0) ; 
			can0.push_back(1) ;
		} else { 
			can0.push_back(0) ; 
			if(r >> pos & 1)
				can0.push_back(1) ; 
		}
	} else { 
		if(r0) { 
			if(l >> pos & 1)
				can0.push_back(1) ; 
			else { 
				can0.push_back(0) ; 
				can0.push_back(1) ; 
			}
		} else { 
			int b0 = (l >> pos & 1) ; 
			int b1 = (r >> pos & 1) ; 
			for(int i = b0 ; i <= b1 ; ++i)
				can0.push_back(i) ; 
		}
	}
	vector < int > can1 ; 
	if(l1) { 
		if(r1) { 
			can1.push_back(0) ; 
			can1.push_back(1) ;
		} else { 
			can1.push_back(0) ; 
			if(r >> pos & 1)
				can1.push_back(1) ; 
		}
	} else { 
		if(r1) { 
			if(l >> pos & 1)
				can1.push_back(1) ; 
			else { 
				can1.push_back(0) ; 
				can1.push_back(1) ; 
			}
		} else { 
			int b0 = (l >> pos & 1) ; 
			int b1 = (r >> pos & 1) ; 
			for(int i = b0 ; i <= b1 ; ++i)
				can1.push_back(i) ; 
		}
	}
	int &cur = dp[pos][l0][r0][l1][r1] ; 
	cur = 0 ; 
	for(int x : can0) { 
		for(int y : can1) { 
			if(x == y && x) continue ; 
			int nl0 = l0 | (x > (l >> pos & 1)) ; 
			int nr0 = r0 | (x < (r >> pos & 1)) ; 
			int nl1 = l1 | (y > (l >> pos & 1)) ; 
			int nr1 = r1 | (y < (r >> pos & 1)) ; 
			cur += ans(pos - 1 , nl0 , nr0 , nl1 , nr1) ; 
		}
	}
	return cur ; 
}

void solve() { 
	cin >> l >> r ;
	memset(dp , -1 , sizeof dp) ; 
	cout << ans(33 , 0 , 0 , 0 , 0) << endl ; 
}

int32_t main() { 
	int tc ; 
	cin >> tc ; 
	while(tc--)
		solve() ; 
}
