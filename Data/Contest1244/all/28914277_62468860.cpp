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
 
ll t,n;
string ch;

int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> t;
    while(t--){
      cin >> n;
      cin >> ch;
      int fir=-1, las=-1;
      for(int i=0;i<n;i++){
        if(ch[i]=='1'){
          las=i;
          if(fir==-1)fir=i;
        }
      }
      if(fir==-1){
        cout << n << endl;
        continue;
      }
      ll ans=0;
      ans=max(ans,2*(las+1));
      ans=max(ans,2*(n-fir));
      cout << ans << endl;
    }

    return 0;
}