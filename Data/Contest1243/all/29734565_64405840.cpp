#include"bits/stdc++.h"
using namespace std;
#define ld long double
#define int long long
#define pb push_back 
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
 
  //Take care of duplicates

  const int mod=1000000007;
  const int mod2=998244353;
  const int INF=(1LL<<50)-1;
  const int N=2e5+25; 
  
  void bheja_fry()
  { 
     int n,m; cin>>n>>m;

     map<pii,int> hh;

     rep(i,0,m){
      int x,y;
      cin>>x>>y;
      hh[{x,y}]=hh[{y,x}]=1;
     }

     queue<int> q;
     set<int> s;
     q.push(1);
     rep(i,2,n+1) s.insert(i);
     
     int ans=0;
     while(!s.empty())
     {
       int tp=q.front(); q.pop();
       vi v;
       tr(i,s)
       {
         if(hh[{tp,i}]!=1)
         v.pb(i);
       }
       if(Z(v)==0)
       { 
        if(q.empty())
       {  ans++;
         q.push(*s.begin());
         s.erase(s.begin());
       }
         continue;
       }
       tr(i,v)
       {
         s.erase(i);
         q.push(i);
       }

     }

     cout<<ans;

  }

signed main()
{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r", stdin); 
   freopen("output.txt","w", stdout);
   freopen("error.txt","w", stderr);
   #endif

  
   int t=1;                         
//   cin>>t;
  rep(i,1,t+1)
  { // cout<<"Case #"<<i<<": ";
   bheja_fry();
   if(i<t)
   cout<<nl;
  }
  
  #ifndef ONLINE_JUDGE
  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
  #endif
 return 0; 
}