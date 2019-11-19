#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
#define MOD 1000000007
template<typename T> void prllList(std::initializer_list<T> li) { 
    for (const auto & value: li) 
        std::cout << value << " "; } 

#define ifr(i,n) for(ll i=0;i<n;++i)
#define dfr(i,n) for(ll i=n-1;i>=0;--i)
#define ifrd(i,s,n,d) for(ll i=s;i<n;i+=d)
#define dfrd(i,n,d) for(ll i=n-1;i>=0;i-=d)


vector<ll> primeFactors(ll n)  
{  
    vector<ll> v;
    // Prll the number of 2s that divide n  
    if(n%2==0)
         v.push_back(2);
    while (n % 2 == 0)  
    {  
        n = n/2;  
    }  
  
    // n must be odd at this poll. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        if(n%i==0)
            v.push_back(i);
        // While i divides n, prll i and divide n  
        while (n % i == 0)  
        {  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
          v.push_back(n);
    return v;
}
main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    ll t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v = primeFactors(n);

        if(v.size()==1)
        {
            cout<<v[0]<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
}
