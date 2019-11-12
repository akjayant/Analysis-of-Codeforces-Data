#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, a, b) for(int i = (a); i > (b); --i)

typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <ll> vl;

const int mod = 1e9+7;
const int inf = 2e18+5;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);

  int t,n;
  cin>>t;
  while(t--){
  cin>>n;
  vi a(n);
  loop(i,0,n) cin>>a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int ans=0;
  loop(i,0,n){
    ans=max(ans,min(i+1,a[i]));
  }
  cout<<ans<<endl;
  }
  return 0;
}
