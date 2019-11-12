
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    bool flag=true;
    vector<P> res;
    rep(i,n){
      if(s[i]==t[i]) continue;
      bool p=false;
      FOR(j,i+1,n){
        if(t[i]==t[j]){
          res.PB(P(i+1,j+1));
          swap(s[i],t[j]);
          p=true;
          break;
        }
      }
      if(p)continue;
      FOR(j,i+1,n){
        if(s[i]==t[j]){
          res.PB(P(j+1,j+1));
          res.PB(P(j+1,i+1));
          swap(s[j],t[j]);
          swap(s[j],t[i]);
          p=true;
          break;
        }
      }
      if(p) continue;
      FOR(j,i+1,n){
        if(t[i]==s[j]){
          res.PB(P(j+1,j+1));
          res.PB(P(i+1,j+1));
          swap(s[j],t[j]);
          swap(s[i],t[j]);
          p=true;
          break;
        }
      }
      if(p) continue;



      flag=false;
    }

    if(flag){
      Yes(true);
      cout<<res.size()<<endl;
      rep(i,res.size()){
        cout<<res[i].F<<' '<<res[i].S<<endl;
      }
    }else{
      Yes(false);
    }
  }

}
