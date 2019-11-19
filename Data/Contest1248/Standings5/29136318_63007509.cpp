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
    ll n,m,i;
    cin>>n>>m;
    ll ans[max(n,m)+1];
        int u=0;int v=10;
    ans[0]=ans[1]=1,ans[2]=2;
    f(i,3,max(n,m)+1)
        ans[i]=(ans[i-1]%MOD)+(ans[i-2]%MOD);
    cout<<(ll)(((ans[m]+ans[n]-1)%MOD+MOD)*2)%MOD;

    return 0;
}