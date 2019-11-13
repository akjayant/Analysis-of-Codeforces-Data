#include <bits/stdc++.h>
using namespace std;
bool col[1000005];
int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    memset(col, false, sizeof(col));
    int a,b;
    scanf("%d %d",&a,&b);
    if(__gcd(a,b) != 1) printf("Infinite\n");
    else printf("Finite\n");
  }
  return 0 ;
}
