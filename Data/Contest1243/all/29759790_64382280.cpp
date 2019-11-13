#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

char s[MAXN], t[MAXN];

int main(){
  int k;
  scanf("%d", &k);

  while(k--){
    int n;
    scanf("%d", &n);
    scanf("%s%s", s, t);

    vector<int> diff_idx;

    for(int i=0; i<n; i++){
      if(s[i] != t[i]){
        diff_idx.push_back(i);
      }
    }

    if(diff_idx.size() != 2){
      printf("No\n");
      continue;
    }

    int i = diff_idx[0], j = diff_idx[1];

    if(s[i] == s[j] and t[i] == t[j]){
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
