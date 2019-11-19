#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> fib(200000);
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 200000; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;

  ll ans = (fib[n+1] + fib[m+1] - 1) % mod;
  ans = (ans * 2) % mod;


  cout << ans << endl;

  return 0;
}
