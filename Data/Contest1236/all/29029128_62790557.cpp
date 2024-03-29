// BROWNIE TK
 
#include <bits/stdc++.h>
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#define pb push_back
#define popb pop_back
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
 
#define forz(i, n) for (int i = 0; i < n; i++)
#define bui(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define mui(i, m, n) for (int i = n - 1; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
 
using namespace std;
 
/*STD fucntions*/
 
void pairsort(int a[], int b[], int n)
{
    pair<int, int> pairt[n];
 
    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
 
    // Sorting the pair array.
    sort(pairt, pairt + n);
 
    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

void pairsortlli(lli a[], lli b[], lli n)
{
    pair<lli, lli> pairt[n];
 
    // Storing the respective array
    // elements in pairs.
    for (lli i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
 
    // Sorting the pair array.
    sort(pairt, pairt + n);
 
    // Modifying original arrays
    for (lli i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
  lli binomialCoeff(lli n, lli k) 
{ 
    lli C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (lli i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (lli j = min(i, k); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%mod; 
    } 
    return C[k]; 
} 
lli power(lli x,lli y,lli p)
{
  lli res=1;
  x=x%p;
  while(y>0)
  {
    if(y&1)
      res=(res*x)%p;
    //y must be even now
    y=y>>1; //y=y/2
    x=(x*x)%p;
  }
  return res;
}
lli gcd(lli a, lli b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
lli lcm(lli a, lli b)
{ return a * b / gcd(a, b); }
lli max(lli a, lli b)
{
  if (a > b)
    return a;
  return b;
}
lli min(lli a, lli b)
{
  if (a < b)
    return a;
  return b;
}
  
  int main() 
  {
    kira;
   lli n,m;
   cin>>n>>m;
   lli p=power(2,m,mod);
   p-=1;
   if(p<0)
   p+=mod;
   lli ans=power(p,n,mod);
   cout<<ans<<endl;
  }