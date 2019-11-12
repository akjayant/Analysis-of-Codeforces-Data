#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int a[n][n];
  int cidx = n*n;
  for(int i=0;i<n;i++) {
    if (i%2) {
      for(int j=0;j<n;j++) {
        a[j][i] = cidx--; 
      }
    } else {
      for(int j=n-1;j>=0;j--) {
        a[j][i] = cidx--;
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}