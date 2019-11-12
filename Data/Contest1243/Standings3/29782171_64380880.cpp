#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define MOD1 998244353
#define miN min_element
#define maX max_element
#define vi vector <int>
#define vll vector <ll>
#define pii pair <int,int>
#define pll pair <ll,ll>
#define pq priority_queue <ll>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); srand(time(NULL));
#define pcout(x) cout<<setprecision(15)<<x<<'\n';

ll GCD( ll x, ll y) { if(y==0) return x; return GCD(y,x%y);}
ll LCM( ll x, ll y) { return (x*y)/GCD(x,y);}
ll MPOW( ll a, ll b, ll m) { if(b==0) return 1; ll x=MPOW(a,b/2,m); x=(x*x)%m; if(b%2==1) x=(x*a)%m; return x;}
ll MINV( ll a, ll m) { return MPOW(a,m-2,m);}
ll MFACT( ll n, ll m){ if(m<=n) return 0; else if(n==0) return 1; else return ((MFACT(n-1,m)*n)%m);}
inline ll max( ll a, ll b) { return (a>b)?a:b;}
inline ll min( ll a, ll b){ return (a<b)?a:b;}
inline void swap( ll &a, ll &b){ ll temp=a; a=b; b=temp; return;}
inline ll max3( ll a, ll b, ll c){ return max(a,max(b,c));}
inline ll min3( ll a, ll b, ll c){ return min(a,min(b,c));}

using namespace std;


int main()
{
    FASTIO
    ll t=1;
    cin>>t;
    while(t--)
    {
      ll n;
      cin>>n;
      ll pos1=-1,pos2=-1,count=0;
      string s,t;
      cin>>s>>t;
      for(ll i=0;i<n;++i)
      {
        if(s[i]!=t[i])
        {
          count++;
          if(pos1==-1)
            pos1=i;
          else if(pos2==-1)
            pos2=i;
        }
      }
      if(count==2&&s[pos1]==s[pos2]&&t[pos1]==t[pos2])
        cout<<"Yes\n";
      else
        cout<<"No\n";
    }
    return 0;
}
