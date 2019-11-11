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

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin >> n;
	for (int z=0;z<n;z++){
		ll a,b;
		cin >> a >> b;
		if (__gcd(a,b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
}
 
 