#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int a[MAXN];

int main(){
  int k;
  scanf("%d", &k);

  while(k--){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
      scanf("%d", &a[i]);
    }

    sort(a+1, a+1+n);

    int max_side = 0;

    for(int i=1; i<=n; i++){
      max_side = max(max_side, min(a[i], n-i+1));
    }

    printf("%d\n", max_side);
  }
}
