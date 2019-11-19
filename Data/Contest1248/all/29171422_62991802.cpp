#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int A[1010][1010], fib[1000010], fib2[1000100];
int brute(int n, int m){
	int x =  n * m;
	int ans = 0;
	for(int mk = 0; mk < (1 << x); mk++){
		int ctr = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mk & (1 << ctr))
					A[i][j] = 1;
				else A[i][j] = 0;
				ctr++;
			}
		}
		int mkr = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int ans = 0;
				for(int k =0 ;k < 4; k++){
					int p = i + dir[k][0];
					int q = j + dir[k][1];
					if(p >= 0 && p < n && q >= 0 && q < m && A[p][q] == A[i][j])
						ans++;
				}
				if(ans > 1)
					mkr = 1;
			}
		}
		if(!mkr)
			ans++;
	}
	//cout << ans << '\n';
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	//cout << brute(n, m) << '\n';
	fib[1] = 2;
	fib[2] = 4;
	for(int i = 3; i <= 100010; i++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	}
	if(m == 1){
		cout << fib[n] << '\n';
	}
	else if(m == 2){
		cout << (fib[n] + 2) % MOD << '\n';
	}
	else if(m == 3){
		cout << (fib[n] + 4) % MOD << '\n';
	}
	else{
		m--;
		fib2[1] = 2;
		fib2[2] = 4;
		for(int i = 3; i <= m; i++){
			fib2[i] = (fib2[i - 1] + fib2[i - 2] + 2) % MOD;
		}
		
		//cout << fib2[m] << '\n';
		cout << (fib[n] + fib2[m]) % MOD << '\n';
	}


}