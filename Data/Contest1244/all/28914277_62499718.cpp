#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
     
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
  
const int MOD = 998244353;
const int N = 1000005;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
 
ll n,p,w,d,k;
map<ll,ll> maa;
ll a[N];
vl v;
ll oool=0;
bool ok(ll u){
  ll i=0;
  ll j=n-1;
  ll o=u;
  ll suml=maa[v[i]];
  ll sumr=maa[v[j]];
  ll res=0;
 // cout << u << endl;
  while(o){
    if(i==j){
      break;
    }
    //cout << "sm "<<i<< " " << j <<" " << suml << " " << sumr << endl;
    if(suml>sumr){
      res+=min(o,v[j]-v[j-1])*sumr;
      o-=min(o,v[j]-v[j-1]);
      sumr+=maa[v[j-1]];
      j--;
    }else{
      res+=min(o,v[i+1]-v[i])*suml;
      o-=min(o,v[i+1]-v[i]);
      suml+=maa[v[i+1]];
      i++;
    }
  }
  //cout << u << " " << res << endl;
  //cout <<k << endl;
  return res<=k;
}

int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n >> k;
    for(int i=0;i<n;i++){
      cin >> a[i];
      maa[a[i]]++;
    }
    ll l =0;
    for(auto t:maa){
      v.pb(t.f);
    }
    n=v.size();
    ll r=v[n-1]-v[0];
    ll z=r;
    while(l<r-1){
      ll mid=(l+r)/2;
      if(ok(mid)){
        l=mid;
      }else{
        r=mid;
      }
 
   }
   //cout << ok(2)<< endl;
   //cout <<l << " " << r << endl;
   //ok(4);
    if(ok(r)){
      //cout << "sdf"<< endl;
      cout << z-r ;
    }else{
      cout << z-l;
    }
    return 0;
}