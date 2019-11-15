#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define left  (2*idx)+1
#define right (2*idx)+2
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()
 

const ll MOD = (ll)(1e9 + 7); 
const ll N = 0;

int main()
{
	FIO;
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		if(__gcd(a, b)==1) {
			cout << "Finite\n";
		} else {
			cout << "Infinite\n";
		}
	}
	return 0;	
}	