#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
char a[100005];
char b[100005];
int cnt[28],cntt[28],sum[28];
int change(char x){
  return x-'a';
}
vector<pair<int ,int > >ans;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    for(int i=0;i<26;i++){
      cnt[i]=0;
      cntt[i]=0;
      sum[i]=0;
    }
    ans.clear();
    scanf("%d",&n);
    scanf("%s%s",a,b);
    for(int i=0;i<n;i++){
      cnt[change(a[i])]++;
      cntt[change(b[i])]++;
      sum[change(a[i])]++;
      sum[change(b[i])]++;
    }
    int f=0;
    for(int i=0;i<26;i++){
      if(sum[i]%2==1){
        f=1;
        break;
      }
    }
    if(f) {
      printf("No\n");
      continue;
    }
    for(int i=0;i<n;i++) {
      if (a[i] == b[i]) continue;
      if (cnt[change(a[i])] > sum[change(a[i])] / 2) {
        for (int j = i + 1; j < n; j++) {
          if (a[j] == a[i]) {
            cnt[change(a[i])]--;
            cnt[change(b[i])]++;
            cntt[change(a[i])]++;
            cntt[change(b[i])]--;
            ans.push_back({j, i});
            swap(a[j], b[i]);
            break;
          }
        }
      } else if (cnt[change(a[i])] <= sum[change(a[i])] / 2) {
        for (int j = i + 1; j < n; j++) {
          if (b[j] == a[i]) {
            for (int k = n - 1; k > i; k--) {
              if (cnt[change(a[k])] >= sum[change(a[k])] / 2) {
                cnt[change(a[k])]--;
                cnt[change(b[i])]++;
                cntt[change(b[i])]--;
                cntt[change(a[k])]++;
                ans.push_back({k, j});
                ans.push_back({k, i});
                swap(a[k], b[j]);
                swap(a[k], b[i]);
                break;
              }
            }
            break;
          }
        }
      }
    }
    printf("Yes\n");
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
      printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    }
  }
  return 0;
}