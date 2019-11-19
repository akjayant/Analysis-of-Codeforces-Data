#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pet pair<int,int>
#define one first
#define two second
using namespace std;
const int N = 1000001; 
ll factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
ll fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 


void solve()
{
	ll p=1e9+7;
	int n,m;
	cin >> n >> m;
	
	int ans=0;
	for(int i=1;n-i>=i;i++)
	{
		ans=ans+Binomial(n-i,i,p);
		ans=ans%p;
	}
	
	for(int i=1;m-i>=i;i++)
	{
		ans=ans+Binomial(m-i,i,p);
		ans=ans%p;
	}
	
	ans++;
	ans=2*ans;
	ans=ans%p;
	
	cout << ans << endl;
}

main()
{
    ll p = 1000000007; 
    InverseofNumber(p); 
    InverseofFactorial(p); 
    factorial(p); 
    
	int t=1;
	//cin >> t;
	
	while(t--)
	solve();
}

