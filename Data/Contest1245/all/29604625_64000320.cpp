#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
using namespace std;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
typedef pair <long long,long long> ii;
// typedef complex<long double> point;

 // a  rock
 // b paper
 // c sc
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	for (int z=0;z<t;z++){
		ll n;
		cin >> n;
		ll a,b,c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		ll count = 0;
		string ans;
		for (int z=0;z<n;z++){
			if (s[z] == 'R'){
				if (b > 0){
					b--; count++;
					ans += "P";
				}
				else ans += "*";
			} else if (s[z] == 'P'){
				if (c > 0){
					c--; count++;
					ans += "S";
				}  else ans += "*";
			} else {
				if (a > 0){
					a--; count++;
					ans += "R";
				} else ans += "*";
			}
		}
		if (count >= ceil(ld(n)/ld(2))){
			cout << "YES" << endl;
			for (int z=0;z<n;z++){
				if (ans[z] == '*'){
					if (a > 0) {
						a--;
						ans[z] = 'R';
					}
					else if (b > 0 ) {
						b--;
						ans[z] = 'P';
					}
					else {
						c--;
						ans[z] = 'S';
					}
				}
			}
			cout << ans << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
 
 