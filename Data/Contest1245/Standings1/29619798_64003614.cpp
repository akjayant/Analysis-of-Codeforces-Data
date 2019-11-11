#include<stdio.h>
inline int gcd(int p,int q){return q?gcd(q,p%q):p;}
int main(){
int n,p,q;
scanf("%d",&n);
while(n--){
scanf("%d%d",&p,&q);
printf("%s\n",gcd(p,q)==1?"Finite":"Infinite");
}
}