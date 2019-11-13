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
vector<pair<int, int> > ans;
int main(){
	int t;sc(t);
	string a,b;
	while(t--){
		int n;sc(n);
		cin >> a;
		cin >> b;
		int fl=1;
		ans.clear();
		for(int i=0;i<n;i++){
			if(a[i]==b[i]) continue;
			int fnd=0;
			for(int j=(i+1);j<n;j++){
				// trace(a[i], a[j], b[j]);
				if(a[j] == a[i]){
					ans.push_back({j, i});
					swap(a[j], b[i]);
					fnd=1;
					break;
				}
				else if(b[j] == a[i]){
					ans.push_back({j, j});
					ans.push_back({j, i});
					swap(b[j], a[j]);
					swap(a[j], b[i]);
					fnd=1;
					break;
				}
			}
			if(!fnd){
				fl=0;
				break;
			}
			// trace(a, b);
		}
		if(!fl) printf("No\n");
		else{
			printf("Yes\n");
			pr((int)ans.size());br;
			for(int i=0;i<ans.size();i++){
				printf("%d %d\n", ans[i].first+1, ans[i].second+1);
			}
		}
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


