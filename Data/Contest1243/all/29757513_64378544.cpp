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
int idx[3];
int main(){
	int t;sc(t);
	string a,b;
	while(t--){
		int n;sc(n);
		cin >> a;
		cin >> b;
		int k=0;
		if(a==b){
			printf("Yes\n");
			continue;
		}
		int fl=1;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				idx[k++] = i;
				if(k==3){
					break;
				}
			}
		}
		if(k!=2){
			printf("No\n");
			continue;			
		}
		else if(a[idx[0]] == a[idx[1]] and b[idx[0]] == b[idx[1]]){
			printf("Yes\n");
		}
		else printf("No\n");
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


