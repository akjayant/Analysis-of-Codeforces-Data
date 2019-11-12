//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

void solve(){
	ll x, y, z;
	cin >> x >> y >> z;
	res = 3 * min(y, z / 2);
	y -= min(y, z /  2);
	cout << res + 3 * min(x, y / 2) << "\n";
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
}
// nEro