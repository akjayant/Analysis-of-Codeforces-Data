#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, x, m, a, b, t;
vector<ll> v;
vector<vector<int> > vv;

const ll inf = 1000000007;
ll pole2[100005];

void fib(){
  pole2[0] = 1;
  pole2[1] = 1;
  for(ll i = 2; i < 100005;i++){
    pole2[i] = (pole2[i-1] + pole2[i-2])%inf;
  }
}
  




int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  //cout << "fi" << endl;
  fib();

  //cout << "cin" << endl;
  cin >> n >> m;

  if(n == 1 && m == 1){
    cout << 2 << endl;
    return 0;
  }
  if((n == 1 && m == 2) || (n == 2 && m == 1)){
    cout << 4 << endl;
    return 0;
  }
  if((n==1 && m == 3) || (n==3 && m == 1)){
    cout << 6 << endl;
    return 0;
  }
    
	

  ll res1 = 0, res2 = 0, res3 = 0, res4 = 0;

  ll sum = 1;
  res1 = (pole2[n]-1)*2;
  res2 = (pole2[m]-1)*2;
  cout << (res1 + res2 + 2)%inf << endl;

}

  
