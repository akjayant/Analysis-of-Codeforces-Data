#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(a%b==0)return b;
  return gcd(b,a%b);
}
int main(){
  int t,a,b;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&a,&b);
    if(gcd(a,b)==1)printf("Finite\n");
    else printf("Infinite\n");
  }
  return 0;
}
