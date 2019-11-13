#include<bits/stdc++.h>
using namespace std;
int T;
int a,b,c;
int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		scanf("%d%d",&a,&b);
		c=__gcd(a,b);
		if(c==1)puts("Finite");
		else puts("Infinite");
	} 
	return 0;
}
