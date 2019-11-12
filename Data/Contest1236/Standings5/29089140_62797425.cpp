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
const ll N = 307;

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
	int n;
	cin >> n;
	vector<int> ans[N];
	int j = 1;
	int o = 1;
	for(int i=1; i<=(n*n); i++) {
		ans[j].pb(i);

		if(i%n == 0) {
			if(o == 1) {
				o = 0;
			}
			else {
				o = 1;
			}
		} else {
			if(o == 1) {
				j++;
			} else {
				j--;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(auto j : ans[i]) {
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;	
}	