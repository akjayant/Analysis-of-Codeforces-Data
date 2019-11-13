#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL T;
LL gcd(LL a,LL b){
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		LL a,b;
		cin>>a>>b;
		if(gcd(a,b)==1)
			cout<<"Finite\n";
		else
			cout<<"Infinite\n";
	}
	return 0;
}
