#include <bits/stdc++.h>
#define endl '\n'

using namespace std;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests, a, b, c, d, k;

  cin>>tests;
  while(tests--) {
    cin>>a>>b>>c>>d>>k;

    int pens = (a + c - 1) / c, pencils = (b + d - 1) / d;

    if(pens+pencils<=k) {
      cout<<pens<<' '<<pencils<<endl;
    } else {
      cout<<-1<<endl;
    }
  }

  return 0;
}
