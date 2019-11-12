#include<bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))

#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> pii;
const int mod=1e9+7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a%mod;
    a = a * a%mod;
    b >>= 1;
  }
  return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m;
	cin>>n>>m;
	ll ans=1;
	ans=binpow(2,m)-1;
	ans=binpow(ans,n);
	cout<<ans;
    return 0;
}
