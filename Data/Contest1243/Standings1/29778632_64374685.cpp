#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
int a[maxn];
bool cmp(int r,int t){
  return r>t;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>=i+1) {
            ans=i+1;
        }else break;
    }
    printf("%d\n",ans);
  }
  return 0;
}
