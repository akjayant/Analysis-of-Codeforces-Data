/* 	* Author: ReSi
 	* Time: 2019-10-17 17:07:08
**/

#include <bits/stdc++.h>

using namespace std;

#define mP make_pair
#define ll long long
#define pB push_back
#define X first
#define Y second

int main(){
	int t;
	cin >> t;
	while(t--){
		int ans = 0;
		int a, b, c;
		cin >> a >> b >> c;
		while(b >= 1 && c >= 2){
			b--;
			c -= 2;
			ans += 3;
		}
		while(a >= 1 && b >= 2){
			a--;
			b -= 2;
			ans += 3;
		}
		cout << ans << endl;
	}
	

	return 0;
}
