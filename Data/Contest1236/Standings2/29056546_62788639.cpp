#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
#define ll long long

ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    // Update x if it is more than or
    // equal to p
    x = x % p;

    while (y > 0) {
        // If y is odd, multiply x with the result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin>>n>>m;

  long long x = power(2,m,mod);

  x-=1;
  if(x < 0) x+=mod;

  cout<<power(x , n , mod)<<endl;
  return 0;
}