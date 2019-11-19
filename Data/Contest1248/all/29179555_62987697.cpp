#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cout.precision(15);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    long long en = 0, on = 0;
    for(int i = 0; i < n; ++i) {
      long long tmp;
      cin >> tmp;
      if(tmp % 2 == 1) on++;
      else en++;
    }
    int m;
    cin >> m;
    long long om = 0, em = 0;
    for(int i = 0; i < m; ++i) {
      long long tmp;
      cin >> tmp;
      if(tmp % 2 == 1) om++;
      else em++;
    }
    cout << om * on + em * en << endl;
  }

  return 0;
}
