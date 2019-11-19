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
    int n,i;
    cin>>n;
    ll a[n],la=0,s=0;
    f(i,0,n)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=n-1;i>=n-1-i;i--)
    {
        la+=a[i];
        if(i!=n-1-i)
            s+=a[n-1-i];
    }
    cout<<s*s+la*la<<'\n';

    return 0;
}