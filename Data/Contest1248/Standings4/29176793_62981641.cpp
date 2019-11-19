#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
typedef pair<ll,ll> ipair;
#define F first
#define S second

/*
//functions from gfg

long long int power(long long int x,long long int y,long long  int p)
{
    long long int res = 1;     // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            {//d=(long double)x/p;
            res = (res*x) % p;
            }
 
        // y must be even now
        y = y>>1; // y = y/2
        x=(x*x)%p;
        
    }
    return res%p;
}

long long int gcd(long long int a,long long int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

long long int binomialCoeff(long long int n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (ll i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 


*/

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
	ll n,i,j,k=0,m=0,ans=0;
    cin>>n;
    vector<ll> a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n%2==0)
    {
        for(i=0;i<n/2;i++)
        {
            m+=a[i];
        }
        for(i=n/2;i<n;i++)
        {
            k+=a[i];
        }
        cout<<m*m+k*k<<endl;;
    }
    else
    {
        for(i=0;i<n/2;i++)
        {
            m+=a[i];
        }
        for(i=n/2;i<n;i++)
        {
            k+=a[i];
        }
        cout<<m*m+k*k<<endl;;
    }
    
    
    
    
    // for(i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
	return 0;
}
