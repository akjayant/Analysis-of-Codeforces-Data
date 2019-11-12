#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
#define MOD 1000000007
template<typename T> void printList(std::initializer_list<T> li) { 
    for (const auto & value: li) 
        std::cout << value << " "; } 

#define ifr(i,n) for(ll i=0;i<n;++i)
#define dfr(i,n) for(ll i=n-1;i>=0;--i)
#define ifrd(i,s,n,d) for(ll i=s;i<n;i+=d)
#define dfrd(i,n,d) for(ll i=n-1;i>=0;i-=d)

main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ifr(i,n) cin>>a[i];
        sort(a,a+n);
        ll x =-1;
        ifrd(i,1,n+1,1)
        {
            if(a[n-i]>=i)
            {
                x = max(x,i);
            }
            else{
                break;
            }
        }
        cout<<x<<endl;

    }
}
