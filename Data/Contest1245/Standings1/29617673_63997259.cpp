#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
int main(){
	reg int T;scanf("%d",&T);
	while(T--){
		static int a,b;
		scanf("%d%d",&a,&b);
		if(__gcd(a,b)>1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}