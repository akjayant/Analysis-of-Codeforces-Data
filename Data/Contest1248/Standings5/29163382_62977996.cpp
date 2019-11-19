#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, k, x, m, a, b, t;
vector<int> v;
vector<vector<int> > vv;


int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  for(int w = 0; w < t;w++){
    cin >> n;
    ll od1 = 0; ll ev1 = 0;
    ll od2 = 0; ll ev2 = 0;
    for(ll i = 0; i < n;i++){
      cin >> x;
      if(x%2 == 1){
	od1++;
      }
      else{
	ev1++;
      }
    }
    cin >> m;
    for(ll i = 0; i < m;i++){
      cin >> x;
      if(x%2 == 1){
	od2++;
      }
      else{
	ev2++;
      }
    }

    cout << od1*od2 + ev1*ev2 << endl;
  }

}

  
