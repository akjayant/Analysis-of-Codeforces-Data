#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vi vector<int>
#define left  (2*idx)+1
#define right (2*idx)+2
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()
 
const ll MOD = (ll)(1e9 + 7); 
const ll N = 100007;

int main()
{
	FIO;
	int t;
	cin >> t;

	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int x, y;
		x = y = 0;
		y = min(b, c/2);
		int ans = 0;
		ans = 3*y;
		b-=y;
		x = min(a, b/2);
		ans = ans + (3 * x);
		cout << ans << "\n";
	}
	return 0;	
}	