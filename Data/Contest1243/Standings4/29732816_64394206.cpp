/*================= *\
|  ID : aman__guta__ |
|      LANG: C++     |
\*==================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define fs first
#define sc second 
#define mod 1000000007
#define JOKER ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
main()
{
    JOKER
    ll n;
    cin>>n;
    set <ll> s;
    s.insert(n);
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            s.insert(n/i);
            s.insert(i);
        }
    }
    if(s.size()==1)
    {
        cout<<n<<endl;
        return 0;
    }
    if(n%2==0)
    {
        for(auto it=s.begin(); it!=s.end(); it++)
        {
            if(*it%2!=0)
            {
                cout<<1<<endl;
                return 0;
            }
        }
        cout<<2<<endl;
        return 0;
    }
    ll b=*s.begin();
    for(auto it=s.begin(); ; )
    {
        it++;
        if(it==s.end())
        {
            break;
        }
        b=__gcd(b,*it);
    }
    if(b!=1) 
    {
        cout<<*s.begin()<<endl;
        return 0;
    }
    cout<<1<<endl;
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}