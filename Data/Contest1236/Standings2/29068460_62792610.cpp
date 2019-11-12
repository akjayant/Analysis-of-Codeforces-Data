#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> A(n,vector<int>(n));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      A[i][j] = i*n + j + 1;
    }
    if(i%2) reverse(A[i].begin(), A[i].end());
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cout << A[j][i] << " " ;
    }
    cout << endl;
  }
}
