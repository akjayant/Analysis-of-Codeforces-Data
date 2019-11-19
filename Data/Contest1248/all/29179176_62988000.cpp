#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); 
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin >> a[i];
  sort(a.begin(),a.end());
  ll sumx=0,sumy=0;
  for(int i=0;i<n;i++){
    if(i<n/2){sumx+=ll(a[i]);}
    else{sumy+=ll(a[i]);}
  }
  cout << sumx*sumx+sumy*sumy << endl;
}