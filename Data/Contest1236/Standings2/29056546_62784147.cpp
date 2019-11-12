#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  {
    int a,b,c;
    cin>>a>>b>>c;
    int ans = min(c/2 , b);
    b -= ans;
    ans = ans + 2*ans;
    int x = min(b/2 , a);
    ans += x*2 + x;
    printf("%d\n" , ans);
  }

  return 0;
}