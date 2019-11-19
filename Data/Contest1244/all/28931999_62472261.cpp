#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9+9;
const int MAXN = 1000006;


ll n, p, w, d;
int used[MAXN];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> p >> w >> d;
  ll r = p%w, x=0, y=0;
  used[r] = true;
  for (int i = 0; true; i=(i+d)%w) {
    if (used[i]) break;
    used[i] = true;
    y++;
  }
  x=max((p-y*d)/w, (ll)0);
  if (x+y<=n && x*w+y*d==p) {
    cout << x << " " << y << " " << n-x-y << endl;
  } else {
    cout << -1 << endl;
  }
  
}
