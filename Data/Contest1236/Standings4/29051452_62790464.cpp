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

const ll mod = 1e9+7;

ll ffe( ll a, ll b){
	if(b==0){
		return 1;
	}else{
		if(b%2)	return (a*ffe((a*a)%mod,b/2))%mod;
		else	return 	ffe((a*a)%mod,b/2);
	}
}
 
int main(){		
 
	fio;
	
	ll t;
	t=1;
	
	while(t--){
	
		ll n, m;
		cin >> n >> m;
		m = ffe(2,m);
		m = (m -1 + mod)%mod;
		n = ffe(m,n);
		cout << n << "\n";
		
	}

 
	return 0;
}