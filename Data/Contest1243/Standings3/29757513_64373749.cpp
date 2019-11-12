#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

const int N = 3e5+5;

#define pr(a) printf("%d",a); 
#define sc(a) scanf("%d",&a); 
#define lpr(a) printf("%lld",a); 
#define lsc(a) scanf("%lld",&a); 
#define br printf("\n");
#define INF 2e16
#define ll long long
#define pb push_back
#define MOD 1000000007

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int arr[N];
int main(){
	int t;sc(t);
	while(t--){
		int n;sc(n);
		for (int i = 0; i < n; ++i)
		{
			sc(arr[i]);
		}
		sort(arr, arr+n);
		int ans = 0;
		for(int i=n-1;i>=0;i--){
			if(n-i <= arr[i]) ans = n-i;
			else break;
		}
		pr(ans);br;
	}
	return 0;
}
ll power(ll a,ll b)
{
	ll r=1;
	while(b){
		if(b & 01) r=(r*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return r;
}


