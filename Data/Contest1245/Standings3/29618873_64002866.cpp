/*input
4
10 10
1 10
6 9
7 3

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x firstw
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
#define endl '\n'
using namespace std;
// #define int ll
// #pragma GCC optimize("Ofast")

//coding in car is hard
int32_t main(){
	int t;
	cin >> t;

	int a, b;
	while(t--){
		cin >> a >> b;
		if(__gcd(a, b) == 1){
			cout << "Finite" << endl;
		} else {
			cout << "Infinite" << endl;
		}
	}

}
