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
vector<ll> pr;
void primeFactors(ll n)  
{  
    while (n % 2 == 0)  
    {  
	    if(pr.size() == 0) pr.push_back(2);
	    else if(pr[pr.size()-1]!=2) pr.push_back(2);  
        n = n/2;  
    }  
  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            if(pr.size() == 0) pr.push_back(i);
            else if(pr[pr.size()-1]!=i) pr.push_back(i);  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        pr.push_back(n);
}  

int main(){
	long long n;lsc(n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	primeFactors(n);
	if(pr[pr.size()-1] == n) lpr(n)
	else{
		ll ans = 0;
		if(pr.size()>1) printf("1\n");
		else printf("%lld\n", pr[0]);
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


