#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while(q--){
  int n, a[200005];
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int imin = 1e9, imax = 0;
  
	for(int i = n; i >= 1; i--){
	  imin = min(imin, a[i]);
	  int ans = min(imin, n - i + 1);
	  imax = max(imax, ans);
	}
	cout << imax << endl;
  }
	return 0;
}