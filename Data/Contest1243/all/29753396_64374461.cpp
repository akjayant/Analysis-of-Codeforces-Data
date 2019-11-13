#include<bits/stdc++.h>
#define Timewarp ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD2 998244353
#define MOD 1000000007
#define ll long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define pb push_back
#define xp first
#define yp second
#define vll vector<pl>
#define sl set<ll>
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(a);i<=(b);i++)
#define rdp(i,a,b) for(i=(a);i>=(b);i--)
#define lb(v,z) lower_bound(all(v),z)
#define ub(v,z) upper_bound(all(v),z)
#define trvl(c,it) for(vl::iterator it=(c).begin();it!=(c).end();it++)
#define trvll(c,it) for(vll::iterator it=(c).begin();it!=(c).end();it++)
#define trsl(c,it) for(sl::iterator it=(c).begin();it!=(c).end();it++)
#define fill(a,z) memset(a,z,sizeof(a))
#define INF 1000000000000000000
#define MAXN 100007
using namespace std;

ll n,m,i=0,k=0,j=0,l=INF,r=INF,q=INF,x=0,y=0,ans=0;

int main()
{
    Timewarp;
    cin>>q;
    while(q--){
        cin>>n;
        ll a[n+1];
        rep(i,1,n) cin>>a[i];
        sort(a+1,a+n+1);
        rdp(i,n,1){
            ll cnt=0;
            rdp(j,n,1){
                if(a[j]>=i) cnt++;
                else break;
            }
            if(cnt>=i) break;
        }
        cout<<i<<'\n';
    }

}
