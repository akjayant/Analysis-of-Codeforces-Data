#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, ans;
char a[1007];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, tests;

  cin>>tests;
  while(tests--) {
    cin>>n;
    cin>>(a+1);

    ans = n;
    for(i=1;i<=n;i++) {
      if(a[i]=='1') {
        ans = max(ans, 2 * max(i, n - i + 1));
      }
    }

    cout<<ans<<endl;
  }

  return 0;
}
