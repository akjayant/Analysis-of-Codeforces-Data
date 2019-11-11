#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
//#define int long long

using namespace std;

const int N = (1e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);

void solve(){
	int a, b;
	cin >> a >> b;
	if(__gcd(a, b) == 1){
		cout << "Finite\n";
	}
	else{
		cout << "Infinite\n";
	}
}
main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
