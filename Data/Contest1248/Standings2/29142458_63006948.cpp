#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500+20;
const int MOD = 1e9+7;
int n,num[MAXN*2];
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if(s[i]=='(')num[i]=num[i+n]=1;
    else num[i]=num[i+n]=-1;
  }
  int ans=0,li=0,ri=0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      swap(num[i],num[j]);
      swap(num[i+n],num[j+n]);

      int start=0,maxn=0,sum=0,k=0;
      for (k = 0; k < n*2 && k - start < n && start < n; ++k) {
        sum += num[k];
        //if(i==2 && j==3)cout << " start " << start << endl;
        if(sum < 0){
          start = k+1,maxn=0,sum=0;
        }
        else if(sum==0){
          maxn++;
        }
      }
      if(sum!=0 || k - start != n){maxn=0;}
      if(ans < maxn){
        li=i,ri=j;
        ans=maxn;
      }
      ans=max(ans,maxn);
      swap(num[i],num[j]);
      swap(num[i+n],num[j+n]);
    }
  }
  cout << ans << endl;
  cout << li+1 << " " << ri+1 << endl;
}