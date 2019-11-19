#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, k, x, m, a, b, t;
vector<ll> v;
vector<vector<int> > vv;


int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(ll i = 0; i < n;i++){
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  ll sum1 = 0; ll sum2 = 0;
  for(ll i = 0; i < n/2;i++){
    sum1 += v[i];
  }
  for(ll i = n/2; i < n;i++){
    sum2 += v[i];
  }

  ll res = sum1*sum1 + sum2*sum2;
  cout << res << endl;

}

  
