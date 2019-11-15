#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a,b,t;
int main(){
	cin>>t;
	while(t--){
		scanf("%lld%lld",&a,&b);
		if (__gcd(a,b)==1) cout<<"Finite"<<endl;
		else cout<<"Infinite"<<endl;
	}
} 