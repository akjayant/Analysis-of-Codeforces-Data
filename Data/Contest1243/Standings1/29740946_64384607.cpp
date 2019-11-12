#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define nl '\n'

#define boost ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

const ll INF=1e18;
const int inf=1e9;
const ld eps=1e-7;
const ld pi=acos(-1);
const int dx[8]={0,0 ,1,-1,1,1,-1,-1};
const int dy[8]={1,-1,0,0,1,-1,1,-1};
const int mod1=998244353;
const int mod=1e9+7;
const int N=1111;
int cnt[26];

int main(){
  boost;
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;i++){
      cnt[s[i]-'a']++;
    }
    int ok=1;
    for(int i=0;i<sz(t);i++){
      cnt[t[i]-'a']++;
    }
    for(int i=0;i<26;i++){
      if(cnt[i]%2){
        ok=0;
        break;
      }
    }
    if(!ok)cout<<"No\n";
    else{
      vector<int>pos;
      for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
          pos.pb(i);
        }
      }
      vector<pii>ans;
      for(int i=0;i<sz(pos);i++){
        int l=pos[i];
        int w=0;
        if(s[l]==t[l])continue;
        for(int j=i+1;j<sz(pos);j++){
          int r=pos[j];
          if(s[l]==s[r]){
            ans.pb(mp(r,l));
            swap(t[l],s[r]);
            w=1;
            break;
          }
          if(t[l]==t[r]){
            ans.pb(mp(l,r));
            swap(s[l],t[r]);
            w=1;
            break;
          }
        }
        if(w)continue;
        for(int j=i+1;j<sz(pos);j++){
          int r=pos[j];
          if(s[l]==t[r]){
            ans.pb(mp(r,r));
            swap(s[r],t[r]);
            ans.pb(mp(r,l));
            swap(t[l],s[r]);
            break;
          }
          if(t[l]==s[r]){
            ans.pb(mp(r,r));
            swap(s[r],t[r]);
            ans.pb(mp(l,r));
            swap(s[l],t[r]);
            break;
          }
        }
      }
      cout<<"Yes"<<nl;
      cout<<sz(ans)<<nl;
      for(int i=0;i<sz(ans);i++){
        cout<<ans[i].x+1<<" "<<ans[i].y+1<<nl;
      }
    }
    for(int i=0;i<26;i++)cnt[i]=0;
  }
  return 0;
}
