#include"bits/stdc++.h"
using namespace std;
#define ld long double
#define int long long
#define pb push_back 
#define mod 1000000007
#define mod2 998244353
#define Z(c) (int)(c).size()
#define L(c) c[Z(c)-1]
#define F first
#define S second
#define nl "\n"
#define mii map<int,int> 
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define rep(i,iv,n) for(int (i)=(iv);(i)<(n);(i)++)
#define D1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<nl
#define D2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<nl
#define D3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<nl
#define tr(it,ct) for(auto &(it) : (ct))
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > pii;
typedef vector< pii > vp;
void swap(int &a,int &b)
{ auto tm=a; a=b; b=tm; }
 
 const int N=1e5+1;   //Take care of duplicates
 const int INF=1e16;
 int power(int a,int n,int lelo)
 {
         if(n==0)
                 return 1;
         if(n==1)
                 return a;
         if(n==2)
                 return (a*a)%lelo;
         if(n%2)
                 return (a*power(a,n-1,lelo))%lelo;
         else
                 return power(power(a,n/2,lelo),2,lelo)%lelo;
 }
  void bheja_fry()
{  
  int n; cin>>n;
  vi v[n];
  int t=1;
  rep(i,0,n)
  {
    if(i%2==0)
   { rep(j,0,n)
     v[j].pb(t),t++;
   }
   else
   {
     for(int j=n-1;j>=0;j--)
       v[j].pb(t),t++;
   }
  }
//  rep(i,0,n) if(i%2) reverse(all(v[i]));
  rep(j,0,n)
  {
    rep(i,0,n)
    cout<<v[j][i]<<" ";
    cout<<nl;
  }
}


signed main()
{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout);
   freopen("error.txt","w", stderr);
   #endif
  int t=1;                         
//    cin>>t;
  rep(i,1,t+1)
  { // cout<<"Case "<<i<<": ";
   bheja_fry();
   if(i<t)
   cout<<nl;
  }
 #ifndef ONLINE_JUDGE
  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
 #endif  
 return 0; 
}