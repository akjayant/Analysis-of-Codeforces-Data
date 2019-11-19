//In the name of God
#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long double ld;
typedef pair<int, int> pii;


ld dp[10][10];
int c[10][10];

pii nxt(pii p){	
	int i = p.first, j = p.second;
	if(i&1){
		if(j == 9)
			i --;
		else
			j ++;
	}
	else{
		if(j == 0)
			i --;
		else
			j --;
	}
	return {i, j};	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 0; i < 10; i ++)
		for(int j = 0; j < 10; j ++)
			cin >> c[i][j];
	for(int i = 0; i < 10; i ++){
		if(i&1)
			for(int j = 9; ~j; -- j){
				pii p = {i, j};
				for(int k = 1; k <= 6; k ++){
					p = nxt(p);
					ld now = min((ld)dp[p.first][p.second], (ld)dp[p.first - c[p.first][p.second]][p.second]);
					dp[i][j] += (ld)1 / (ld)6 * now;
				}
				dp[i][j] += (ld)1;
			}
		else
			for(int j = 0; j < 10; j ++){
				if(i == 0 && j == 0)	continue;
				pii p = {i, j};
				int k;
				for(k = 1; k <= 6; k ++){
					p = nxt(p);
					if(p.first == -1)	break; 
					ld now = min((ld)dp[p.first][p.second], (ld)dp[p.first - c[p.first][p.second]][p.second]);
					dp[i][j] += (ld)1 / (ld)6 * now;
				}
				dp[i][j] += (ld)1;
				if(k <= 6)
					dp[i][j] *= 6 / (ld)j;
			}
	}
	cout << fixed << setprecision(8) << dp[9][0];
	return 0;
}
