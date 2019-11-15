#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(__gcd(a,b)==1) cout<<"Finite"<<endl;
		else cout<<"Infinite"<<endl;
	}
	
	
	
	
	return 0;
} 