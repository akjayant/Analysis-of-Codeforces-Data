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


int main(){
  boost;
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
      if(s[i]!=t[i]){
        if(c==0){
          a=i;
          c++;
        }
        else if(c==1){
          b=i;
          c++;
        }
        else c++;
      }
    }
    if(c>2)cout<<"No";
    else {
      if(c==1)cout<<"No";
      else{
        if(s[a]==s[b]&&t[a]==t[b])cout<<"Yes";
        else cout<<"No";
      }
    }
    cout<<nl;
  }
  return 0;
}
