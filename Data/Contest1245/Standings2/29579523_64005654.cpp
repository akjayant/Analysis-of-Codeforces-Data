#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
const double pi = acos(-1.0);


// w = uu
// m = nn

char s[100010];
ll ans[100010];

int main(){
  scanf("%s",s);
  int n =strlen(s);
  rep(i,0,n){
    if(s[i] == 'm' || s[i] == 'w'){
      cout<<0<<endl;
      return 0;
    }
  }
  ans[0] = 1;
  ans[1] = 1;
  rep(i,1,n){
    ans[i+1] = ans[i];
    if( (s[i] == 'u' && s[i-1] == 'u') || (s[i]=='n' && s[i-1]=='n')){
      (ans[i+1] += ans[i-1])%=MOD;
    }
  }
  cout<<ans[n]<<endl;


  return 0;
}
