/**akshaykumar01**/
 
#include<bits/stdc++.h>
using namespace std;
 
#define f(i,x,n) for(i=x;i<n;i++)
#define pu push_back           
#define pp pop_back
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define IOS() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const long long MOD=1e9+7 ;
const long long INF=INT_MAX;
const long long LINF=LLONG_MAX;
const long long N=5e5+1;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> ivc;
typedef pair<ll,ll> ipr;

int main()
{
    IOS();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t;

    cin>>t;
    while(t--)
    {
        ll n,m,i,j,x,aa=0,bb=0;
        cin>>n;
        f(i,0,n)
        {    cin>>x;
                    if(x%2==0)
                        aa++;
                }
        ll a=n-aa;
        cin>>m;
        f(i,0,m)
        { 
            cin>>x;
                    if(x%2==0)
                        bb++;
                }
        ll b=m-bb;
        cout<<aa*bb+a*b<<'\n';

    }

    return 0;
}