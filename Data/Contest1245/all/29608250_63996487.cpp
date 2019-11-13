#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int T,a,b;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&a,&b);
    puts(gcd(a,b)==1?"Finite":"Infinite");
  }
  return 0;
}