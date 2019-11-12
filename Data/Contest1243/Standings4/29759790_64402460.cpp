#include <bits/stdc++.h>

using namespace std;

#define MAXN 60

typedef pair<int,int> ii;

char s[MAXN], t[MAXN];
set<ii> char_idx['z'+1];

int main(){
  int k;
  scanf("%d", &k);

  while(k--){
    for(char ch='a'; ch<='z'; ch++){
      char_idx[ch].clear();
    }

    int n;
    scanf("%d", &n);
    scanf("%s%s", s, t);

    for(int i=0; i<n; i++){
      char_idx[s[i]].insert(ii(0, i));
      char_idx[t[i]].insert(ii(1, i));
    }

    bool test = true;
    for(char ch='a'; ch<='z'; ch++){
      if(char_idx[ch].size()%2 != 0){
        test = false;
        break;
      }
    }

    if(!test){
      printf("No\n");
      continue;
    }

    printf("Yes\n");

    vector<ii> swaps;

    for(int i=0; i<n; i++){
      if(s[i] == t[i]){
        char_idx[s[i]].erase(ii(0, i));
        char_idx[t[i]].erase(ii(1, i));
        continue;
      }

      char_idx[s[i]].erase(ii(0, i));
      ii x = *char_idx[s[i]].begin();
      char_idx[s[i]].erase(x);

      int j = x.second;

      if(x.first == 1){
        char_idx[s[j]].erase(ii(0, j));
        char_idx[t[j]].erase(ii(1, j));
        swap(s[j], t[j]);
        char_idx[s[j]].insert(ii(0, j));
        char_idx[t[j]].insert(ii(1, j));
        swaps.push_back(ii(j, j));
      }

      char_idx[s[j]].erase(ii(0, j));
      char_idx[t[i]].erase(ii(1, i));
      swap(s[j], t[i]);
      char_idx[s[j]].insert(ii(0, j));
      char_idx[t[i]].insert(ii(1, i));
      swaps.push_back(ii(j, i));

      char_idx[s[i]].erase(ii(0, i));
      char_idx[t[i]].erase(ii(1, i));
    }

    printf("%d\n", (int)swaps.size());

    for(int i=0; i<swaps.size(); i++){
      printf("%d %d\n", swaps[i].first+1, swaps[i].second+1);
    }
  }
}
