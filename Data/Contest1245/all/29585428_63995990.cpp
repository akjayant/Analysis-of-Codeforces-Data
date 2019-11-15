#include<stdio.h>
#include<algorithm>

using namespace std;

int gcd(int a, int b) {
  int rem = 1;
  while (rem) {
    rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (gcd(a, b) == 1) printf("Finite\n");
    else printf("Infinite\n");
  }
  return 0;
}
