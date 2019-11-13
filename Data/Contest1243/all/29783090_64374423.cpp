//#pragma comment(linker, "/stack:200000000") //  (UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")  // $ (UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define fi first
#define se second
#define vi vector<int>
#define vii vector< vector<int> >
#define vpi vector< pair<int,int> >
#define pair <int, int> pii

typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
    ordered_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<"  ";__f(comma+1, args...);}
#else
#define trace(...)
#endif

template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}

int modpow(int x, int n, int mod)
{
	x %= mod ;
	int res = 1;
	while(n > 0) {
		if(n & 1)
			res = res * x % mod ;
		x = x * x % mod ;
		n >>= 1 ;
	}
	return res;
}

const long long inf = 2e18 ;
const int mod = 1e9+7 ;
// const int mod = 998244353 ;
const int N = 1e5 + 10 ;

signed main()
{
        ios::sync_with_stdio(false) ;
        cin.tie(0) ;
        cout.tie(0) ;
        #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    	#endif

	int q = 1 ; 
	cin >> q ; 

	while(q--) 
	{
		int n ; 
		cin >> n ; 
		int a[n] ; 
		for(int i=0;i<n;i++)
		{
			cin >> a[i] ; 
		}
		sort(a,a+n) ; 
		int cur = 0 ; 
		for(int i=n-1;i>=0;i--) 
		{
			if(a[i]>cur)
			{
				cur++ ; 
			}
			else  break;
		}
		cout<<cur<<endl; 
	}

return 0 ;
}
