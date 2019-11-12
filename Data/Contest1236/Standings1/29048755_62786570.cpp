#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int T; cin >> T; 
	for(int t = 0; t < T; t++){
		int a, b, c; cin >> a >> b >> c; 
		int ans = 0; 
		for(int i = 0; i <= 50; i++){
			for(int j = 0; j <= 50; j++){
				if(a < i) continue; 
				if(b < 2 * i + j) continue; 
				if(c < 2 * j) continue; 
				int tmp = 3 * (i + j); 
				ans = max(ans, tmp); 
			}
		}
		cout << ans << endl; 
	}
}