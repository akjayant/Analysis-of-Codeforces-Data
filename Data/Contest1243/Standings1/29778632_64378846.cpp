#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
int d[30],e[30];
char a[maxn],b[maxn];
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(d,0,sizeof(d));
     memset(e,0,sizeof(e));
    int n;
    scanf("%d",&n);
    int sum=0;
    scanf("%s",a);
    scanf("%s",b);
    for(int i=0;i<n;i++){
      if(a[i]==b[i])continue;
      else {
        sum++;
        d[a[i]-'a']++;
        e[b[i]-'a']++;
      }
    }
    if(sum!=2) printf("NO\n");
    else {
        int flag=0;
        for(int i=0;i<26;i++){
            if(d[i]==1||d[i]>2) flag=1;
            if(e[i]==1||e[i]>2) flag=1;
        }
        if(flag==0) printf("YES\n");
        else printf("NO\n");
    }
  }
  return 0;
}
