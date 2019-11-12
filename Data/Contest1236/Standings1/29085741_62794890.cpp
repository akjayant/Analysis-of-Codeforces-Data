#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
vector<int>v[303];
int main() {

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=1;j<=n;j++){
      v[i].push_back(i*n+j);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n/2;j++){
      printf("%d ",v[j][i]);
    }
    for(int j=n/2;j<n;j++){
      printf("%d ",v[j][n-i-1]);
    }
    printf("\n");
  }
  return 0;
}
