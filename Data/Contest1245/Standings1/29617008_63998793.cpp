#include <bits/stdc++.h>
#define LL long long

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	int n;
	LL a,b;
	std::cin>>n;
	while(n--){
		std::cin>>a>>b;
		if(std::__gcd(a,b)>1){
			std::cout<<"Infinite\n";
		}else{
			std::cout<<"Finite\n";
		}
	}
	return 0;
}

