#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
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

long long int binomialCoeff(long long int n,long long int k) 
{ 
    long long int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; //add percent mod if want nCk percent mod;
    } 
    return C[k]; 
} 


*/

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,m,i,j,k,l,ans=0,ans1=0;
        cin>>n;
        string s;
        cin>>s;
        ans=n;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            ans++;
        }
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='1'||s[s.length()-1-i]=='1')
            break;
        }
        ans1=2*n;
        ans1-=2*i;
        
        cout<<max(ans1,ans)<<endl;
        
        
        
        // for(i=0;i<n;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
    }
	return 0;
}
