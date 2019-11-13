#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		if(__gcd(a,b)==1){
			puts("Finite");
		}
		else puts("Infinite");
	}
	return 0;
}