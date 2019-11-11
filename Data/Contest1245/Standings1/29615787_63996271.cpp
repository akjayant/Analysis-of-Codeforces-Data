#include<algorithm>
#include<cstdio>
using namespace std;
int T,a,b;
int gcd(int a,int b)
{return !b ? a : gcd(b,a%b);}
int main()
{
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&a,&b);
    puts(gcd(a,b)==1 ? "Finite" : "Infinite");
  }return 0;
}
