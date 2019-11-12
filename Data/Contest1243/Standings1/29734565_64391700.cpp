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
     int n; cin>>n; string s,t; cin>>s>>t;
     
     vi a,b;
     vi id;
     rep(i,0,n)
     {
        if(s[i]!=t[i])
        { id.pb(i);
          a.pb(s[i]-'a');
          b.pb(t[i]-'a');
        }
     }
    int ct[26]={0};
    tr(i,a) ct[i]++;
    tr(i,b) ct[i]++;

    rep(i,0,26){
      if(ct[i]%2) { cout<<"No"<<nl; return;}
    }
     
   cout<<"Yes"<<nl;

    vp ans;

    while(Z(id))
 {    
      if(a[0]==b[0])
      { 
      a.erase(a.begin());
      b.erase(b.begin());
      id.erase(id.begin());
        continue;
      }
     int idx=-1;
     for(int i=1;i<Z(b);i++)
        if(a[0]==b[i])
          { idx=i; break; }
      if(idx!=-1)
    {
        swap(a[idx],b[idx]);
        swap(b[0],a[idx]);
      ans.pb({id[idx],id[idx]});
      ans.pb({id[idx],id[0]});
     
    }
    else
    {
      for(int i=1;i<Z(a);i++)
        if(a[0]==a[i])
          { idx=i; break; }
        assert(idx!=-1);
       swap(a[idx],b[0]);
       ans.pb({id[idx],id[0]});
    }
    a.erase(a.begin());
    b.erase(b.begin());
    id.erase(id.begin());
  }

    cout<<Z(ans)<<nl;
    
   tr(i,ans) cout<<i.F+1<<" "<<i.S+1<<nl;

  }

signed main()
{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r", stdin); 
   freopen("output.txt","w", stdout);
   freopen("error.txt","w", stderr);
   #endif

  
   int t=1;                         
  cin>>t;
  rep(i,1,t+1)
  { // cout<<"Case #"<<i<<": ";
   bheja_fry();
//   if(i<t)
//   cout<<nl;
  }
  
  #ifndef ONLINE_JUDGE
  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
  #endif
 return 0; 
}