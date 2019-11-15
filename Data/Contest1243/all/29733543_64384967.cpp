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
        string s,a;
        cin>>s;
        cin>>a;
        ll x =0;
        ll h1[26]={0},h2[26]={0};
        ll j[n];
        ifr(i,n)
        {
            if(s[i]!=a[i])
            {                    
                j[x]=i;
                x++; 
            }
        }
        if(x==0)
        {
            cout<<"Yes"<<endl;
        }
        else if(x==1)
        {
            cout<<"No"<<endl;
        }
        else if(x==2)
        {
            if(s[j[0]] == s[j[1]] && a[j[1]]==a[j[0]])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }
        else{
            cout<<"No"<<endl;
        }

    }
}
