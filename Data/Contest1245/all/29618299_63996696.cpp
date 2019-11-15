#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main(){
	scanf("%d",&T);
	while(T--)scanf("%d%d",&a,&b),gcd(a,b)==1?printf("Finite\n"):printf("Infinite\n");
}