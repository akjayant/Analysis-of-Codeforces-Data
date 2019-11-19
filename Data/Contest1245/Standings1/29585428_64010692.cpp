#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int LL;

LL K[2005];
int ar[2005][2];
int par[2005];
vector<pair<LL,pair<int,int> > >lis;
vector<pair<int,int> >citi;
vector<int> power;

int finpar(int x) {
  if (par[x] == x) return x;
  return par[x] = finpar(par[x]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &ar[i][0], &ar[i][1]);
  }
  for (int i = 1; i <= n; i++) {
    LL x;
    scanf("%lld", &x);
    lis.push_back(pair<LL,pair<int,int>>(x, pair<int,int>(0, i)));
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &K[i]);
    for (int j = 1; j < i; j++) {
      LL dist = abs(ar[i][0] - ar[j][0]) + abs(ar[i][1] - ar[j][1]);
      lis.push_back(pair<LL,pair<int,int>>(dist * (K[j] + K[i]), pair<int,int>(i, j)));
    }
  }
  sort(lis.begin(), lis.end());
  LL ans = 0;
  for (int i = 0; i < lis.size(); i++) {
    LL c = lis[i].first;
    int a = lis[i].second.first;
    int b = lis[i].second.second;
    if (finpar(a) != finpar(b)) {
      ans += c;
      par[finpar(a)] = finpar(b);
      if (a == 0) {
        power.push_back(b);
      } else if (b == 0) {
        power.push_back(a);
      } else {
        citi.push_back(pair<int,int>(a, b));
      }
    }
  }
  printf("%lld\n", ans);
  printf("%d\n", power.size());
  for (int i = 0; i < power.size(); i++) {
    printf("%d ", power[i]);
  }
  printf("\n");
  printf("%d\n", citi.size());
  for (int i = 0; i < citi.size(); i++) {
    printf("%d %d\n", citi[i].first, citi[i].second);
  }
  return 0;
}
