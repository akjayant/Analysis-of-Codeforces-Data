#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<long long, int> pli;

ll mod = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  int cnt = 0;
  ll p = 1;
  for(ll i = 2;i*i <= n;i++){
    if(n % i == 0){cnt++;p = i;}
    while(n%i == 0)n /= i;
  }
  if(n > 1){cnt++;p = n;}
  if(cnt > 1)cout << 1 << endl;
  else{
    cout << p << endl;
  }
}
