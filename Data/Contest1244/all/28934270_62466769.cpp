#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 200005
using namespace std;
int n,T;
int main(){
scanf("%d",&n);
while(n--){
  int a,b,c,d,e;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
  int ans1=ceil((double)1.0*a/c);
  int ans2=ceil((double)1.0*b/d);
  if(ans1+ans2>e)puts("-1");
  else printf("%d %d\n",ans1,ans2);
}
}