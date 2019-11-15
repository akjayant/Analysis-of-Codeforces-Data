#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
char a[100005];
char b[100005];
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    scanf("%s",a);
    scanf("%s",b);
    int cnt=0;
    vector<char>v,vv;
    v.clear();
    vv.clear();
    for(int i=0;i<n;i++){
      if(a[i]!=b[i]) {
        cnt++;
        v.push_back(a[i]);
        vv.push_back(b[i]);
      }
      if(cnt>=3) break;
    }
    if(v.size()==1||v.size()==3) printf("No\n");
    else{
      if(v.size()==2){
        if(v[1]==v[0]&&vv[0]==vv[1]){
          printf("Yes\n");
        }
        else {
          printf("No\n");
        }
      }
    }
  }
  return 0;
}