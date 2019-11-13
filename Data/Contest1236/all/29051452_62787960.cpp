#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;     
 
#define vi vector
#define pb push_back
#define ll long long int
/*
#define pii pair< int, int>
#define ff  first
#define ss  second
#define sort(a)	sort(a.begin(),a.end())
#define rev(a)	reverse(a.begin(),a.end())
#define fo(i,a,b)	for( ll i=a; i<b; i++)
#define Fo(i,a,b)	for( ll i=a; i<=b; i++)
#define rfo(i,a,b)	for( ll i=a; i>b; i--)
#define rFo(i,a,b)	for( ll i=a; i>=b; i--)
*/
#define fio	ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

 
int main(){		
 
	fio;
	
	ll t;
	cin >> t;
	
	while(t--){
		
		ll a, b, c;
		cin >> a >> b >> c;
		
		ll t = min(b,c/2);
		b = b - t;
		c = c - 2*t;
		
		ll ans = t + 2*t;
		
		t = min(a,b/2);
		ans += t + 2*t;
		
		cout << ans << "\n";
	}

 
	return 0;
}