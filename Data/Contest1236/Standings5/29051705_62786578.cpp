/*input
3
3 4 5
1 0 5
5 3 2

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int a[3];
		cin >> a[0];
		cin >> a[1];
		cin >> a[2];

		int ans = 0;
		while(true){
			if(a[1] > a[2] && a[0] > 0 && a[1] > 1){
				a[0]--;
				a[1]-=2;
				ans += 3;
			} else if(a[2] > 1 && a[1] > 0){
					a[2] -= 2;
					a[1]--;
					ans += 3;
			} else {
				break;
			}
		}
		cout << ans << endl;
	}
}
