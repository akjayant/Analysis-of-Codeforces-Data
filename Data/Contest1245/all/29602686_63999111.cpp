#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
int main(){
	int t1,n,m;
	scanf("%d",&t1);
	while(t1--){
		scanf("%d%d",&n,&m);
		if(gcd(n,m)>1)puts("Infinite");
		 else puts("Finite");
	}
}