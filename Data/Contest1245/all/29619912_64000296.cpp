#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  ll t;
  cin>>t;
  for (ll w=0; w<t; ++w) {
    ll n;
    cin>>n;
    ll a,b,c;
    cin>>a>>b>>c;
    string s;
    cin>>s;
    vector<char> ans(n, 'Q');
    ll wins = 0;
    for (ll i=0; i<n; ++i) {
      char C = s[i];
      if (C=='R' && b) {
        ans[i] = 'P';
        b--;
        wins++;
      } else if (C=='P' && c) {
        ans[i] = 'S';
        c--;
        wins++;
      } else if (C=='S' && a) {
        ans[i] = 'R';
        a--;
        wins++;
      }
    }
    if (wins>=(n+1)/2) {
      cout<<"YES"<<endl;
      for (auto y:ans) {
        if (y=='Q') {
          if (a) {
            cout<<'R';
            a--;
          } else if (b) {
            cout<<'P';
            b--;
          } else if(c) {
            cout<<'S';
            c--;
          }
        } else {
          cout<<y;
        }
      }
      cout<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
}