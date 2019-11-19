#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int,int>   pii;
typedef vector< pii >  vii;
typedef long long int 	ll;

#define pb push_back
#define fe first
#define se second
#define all(a) (a).begin(),(a).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define scn(n) scanf("%d",&n)
#define prn(n) printf("%d\n",n)
#define scnl(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mset(A, val) memset(A, val, sizeof(A))
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
const ll mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;

int main(){
	
	fast_io;
	ll n;
	cin>>n;
	ll cp=n;
	vector<ll> prms;
	for(ll i=2;i*i<=cp;i++){
		if(n%i==0){
			prms.pb(i);
			while(n%i==0) n/=i;
		}
	}
	if(n!=1) prms.pb(n);
	if(prms.size()>=2) cout<<1<<endl;
	else if(prms.size()==1) cout<<prms[0]<<endl;
	else cout<<n<<endl;
	return 0;
}
