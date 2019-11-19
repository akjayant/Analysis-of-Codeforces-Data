#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 200005
using namespace std;
int n,T;
char s[N];
int main(){
scanf("%d",&T);
while(T--){
  scanf("%d",&n);
  int ans=n;
  scanf("%s",s+1);
  for(int i=1;i<=n;i++){
    if(s[i]=='1')ans=max(ans,2*max(i,n-i+1));
  }
  cout<<ans<<endl;
}
}