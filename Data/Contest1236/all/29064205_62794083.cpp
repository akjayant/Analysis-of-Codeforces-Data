//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];


vector<ll> v[505];

void solve(){
	ll n, cur = 1;
	cin >> n;
	for(int i = 0; i < n; ++i){
		if(i & 1){
			for(int i = 0; i < n; ++i){
				v[i].push_back(cur);
				++cur;	
			}
		}
		else{
			for(int i = n - 1; i >= 0; --i){
				v[i].push_back(cur);
				++cur;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(auto j: v[i])	cout << j << " ";
		cout << "\n";
	}
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
}
// nEro