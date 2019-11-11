#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(int i=0;i<(int)n;i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(w,x,y,z) cout<<(w)<<" "<<(x)<<" "<<(y)<<" "<<(z)<<endl
const int mod=1e9+7;
#define ZERO(a) memset(a,0,sizeof(a))
#define Acc(i,n,a) for(int i=0;i<(int)n;i++) cin>>a[i]
#define Acc2(i,n,a,b) for(int i=0;i<(int)n;i++) cin>>a[i]>>b[i]
#define Debug(i,n,a) For(i,n) cout<<a[i]<<" ";cout<<endl;


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
 
main()
{
  fio;
  int T;
  cin>>T;
  while(T--)
  {
    cout<<fixed;
    cout<<setprecision(0);
    int n,m,k;
    cin>>n;
    int r,s,p;
    cin>>r>>p>>s;
    string se;
    cin>>se;
    string opt;
    For(i,n) opt+='B';
    int cnt=n;
    For(i,n)
    {
      if(se[i]=='R' && p>0)
        opt[i]='P', p--;
      else if(se[i]=='S' && r>0)
        opt[i]='R', r--;
      else if(se[i]=='P' && s>0)
        opt[i]='S', s--;
      else
        cnt--;
    }
    if(cnt>=(n+1)/2){
      For(i,n)
      {
        if(opt[i]=='B')
        {
          if(r>0)
            opt[i]='R', r--;
          else if(p>0)
            opt[i]='P', p--;
          else
            opt[i]='S', s--;
        }
      }
      cout<<"YES"<<endl;
      cout<<opt<<endl;
    }
    else
      d1("NO");

  }
    return 0;
}
