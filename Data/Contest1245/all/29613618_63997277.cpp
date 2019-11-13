#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+100;
#define gcd __gcd

int main(){
   int t; scanf("%d",&t);
   while(t--){
      int a,b;
      scanf("%d%d",&a,&b);
      if(gcd(a,b) == 1)puts("Finite");
      else puts("Infinite");
   }
}
