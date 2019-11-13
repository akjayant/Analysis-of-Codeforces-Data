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
vector<int>vec[350];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int k = 1;
  for(int i = 1; i <=n ; ++i)
  {
    if(i&1)
    {
      for(int j = 1 ; j<=n ; ++j) vec[j].push_back(k++);
    } else{
      for(int j = n ; j>=1 ; j--) vec[j].push_back(k++);
    }
  }

  for(int i = 1 ; i<=n ; ++i)
    for(int j = 1 ; j<=n ; ++j) printf("%d%c", vec[i][j-1], " \n"[j==n]);
  return 0;
}