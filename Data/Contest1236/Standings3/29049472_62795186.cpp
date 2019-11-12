#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  int n;
  cin >> n;
  vector<vector<int> > lab(n);
  for (int i = 0; i<  n*n ; i++) {
    if ((i/n)%2 == 0) lab[i%n].push_back(i+1);
    else lab[n-1-i%n].push_back(i+1);
  }
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < n; j++)
      cout << lab[i][j] << " "; 
    cout << "\n";
  }
}

