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
 
ll n,p,w,d;
string ch;




int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n >> p >> w >> d;
    ll k=p/w;
    ll x=p%w;
    ll re=-1;
    for(int i=0;i<=w;i++){
      if((x+i*w)%d==0 ){
        re=i;
        break;
      }
    }
    if(re==-1){
      cout << -1;
      return 0;
    }
    k-=re;
    ll o=(x+re*w)/d;
    if(k<0){
      cout << -1;
      return 0;
    }
    if(k+o>n){
      cout << -1;
      return 0;
    }
    cout << k << " " << o << " " << n-k-o << endl;
    return 0;
}