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

ll powerf(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if(b%2==1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b/=2;
	}
	return res;
}

int main()
{
	FIO;
	ll n, m;
	cin >> n >> m;
	cout << powerf(powerf(2, m)-1, n) << "\n";
	return 0;	
}	