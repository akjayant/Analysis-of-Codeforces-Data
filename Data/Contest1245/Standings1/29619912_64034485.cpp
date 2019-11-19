#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll dp[100][2][2][2][2]; //also can have auxiliary info
int r1[100]; //number as digit array
int r2[100]; //number as digit array
int n; //length

ll solve(int pos, bool le1, bool ge1, bool le2, bool ge2) {
  if (dp[pos][le1][ge1][le2][ge2]>-1) {
    return dp[pos][le1][ge1][le2][ge2];
  } if (pos==n) {
    //check for predicate (here it is p(x)=True)
    return dp[pos][le1][ge1][le2][ge2]=1;
  }
  ll count = 0;
  for (ll b1=0; b1<2; b1++) {
    for (ll b2=0; b2<2; b2++) {
      if (b1&&b2) continue;
      if (le1 && r1[pos]==1 && b1==0) continue;
      if (le2 && r1[pos]==1 && b2==0) continue;
      if (ge1 && r2[pos]==0 && b1==1) continue;
      if (ge2 && r2[pos]==0 && b2==1) continue;
      count += solve(pos+1, le1&&(r1[pos]==b1), ge1&&(r2[pos]==b1), le2&&(r1[pos]==b2), ge2&&(r2[pos]==b2));
    }
  }

  return dp[pos][le1][ge1][le2][ge2]=count;
}

void D(ll x, int* r) {
  memset(r, 0, 60*sizeof(int));
  ll i=0;
  while (x) {
    r[i] = x%2;
    x/=2;
    i++;
  }
  n = max(n, (int)i);
  reverse(r, r+n);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  ll t;
  cin>>t;
  for (ll w=0; w<t; ++w) {
    ll l, r;
    cin>>l>>r;
    n=-1;
    memset(dp, -1, sizeof dp);
    D(r, r2);
    D(l, r1);
    cout<<solve(0, true, true, true, true)<<endl;
  }
}