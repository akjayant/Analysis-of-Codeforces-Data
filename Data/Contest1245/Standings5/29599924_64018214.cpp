#include<cstdio>
#include<algorithm>
#include<cctype>
#define maxn 100007
using namespace std;
int n,a,b,T;
int qread() {
  char c=getchar();int num=0,f=1;
  for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
  for(;isdigit(c);c=getchar()) num=num*10+c-'0';
  return num*f;
}
int gcd(int a, int b) {
  return !b?a:gcd(b,a%b);
}
int main() {
  T=qread();
  while(T--) {
    a=qread(),b=qread();
//    if(a==b) {
//      puts("Infinite");
//      continue;
//    }
//    if(a==1||b==1) {
//      puts("Finite");
//      continue;
//    }
    if(gcd(a,b)==1) {
      puts("Finite");
      continue;
    }
    puts("Infinite");
  }
  return 0;
}