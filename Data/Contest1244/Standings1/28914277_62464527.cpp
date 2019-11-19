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
 
ll t,a,b,c,d,k;

int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> t;
    while(t--){
      cin >> a >> b >> c >> d >> k;
      ll x = (a+c-1)/c;
      ll y = (b+d-1)/d;
      if(x+y<=k){
        cout << x << " " << y << endl;
      }else{
        cout << -1 << endl;
      }
    }

    return 0;
}