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
void multiply(int F[2][2], int M[2][2]); 
  
/* Helper function that calculates F[][] raise to the power n and puts the 
  result in F[][] 
  Note that this function is designed only for fib() and won't work as general 
  power function */
void power(int F[2][2], int n); 
  
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]; 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
  
void power(int F[2][2], int n) 
{ 
  int i; 
  int M[2][2] = {{1,1},{1,0}}; 
  
  // n - 1 times multiply the matrix to {{1,0},{0,1}} 
  for (i = 2; i <= n; i++) 
      multiply(F, M); 
} 
main()
{
  fio;
  int T;
  //cin>>T;
  T=1;
  while(T--)
  {
    cout<<fixed;
    cout<<setprecision(0);
    string s;
    cin>>s;

    For(i,s.size())
    {
      if(s[i]=='m' || s[i]=='w')
      {
        cout<<"0"<<endl;
        return 0;
      }
    }
    string s1="x";
    s1+=s;
    s1+='y';
    s=s1;
    vi frn;
    vi fru;

    For(i,s.size()-1){
      if(s[i]!='n' && s[i+1]=='n')
        frn.pb(1);
      else if(s[i]=='n' && s[i+1]=='n')
        frn[frn.size()-1]++;
    }
    For(i,s.size()-1){
      if(s[i]!='u' && s[i+1]=='u')
        fru.pb(1);
      else if(s[i]=='u' && s[i+1]=='u')
        fru[fru.size()-1]++;
    }

    int dp[100005];
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<100005; i++){
      dp[i]=dp[i-1]+dp[i-2];
      dp[i]%=mod;
    }
    int ans=1;
    For(i,frn.size()){
        ans*=dp[frn[i]+1];
        ans%=mod;
    }
    For(i,fru.size()){
        ans*=dp[fru[i]+1];
        ans%=mod;
    }
    cout<<ans<<endl;
        

  }
    return 0;
}
