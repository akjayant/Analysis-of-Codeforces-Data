#include<bits/stdc++.h>
int t;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int x,y;
	scanf("%d",&t);
	while (t--) scanf("%d%d",&x,&y),printf("%s\n",gcd(x,y)==1?"Finite":"Infinite");
	return 0;
}