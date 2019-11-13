#include<bits/stdc++.h>
int main(){
	int t,a,b;
	std::cin >> t;
	for(;t--;){
		std::cin >> a >> b;
		std::cout << (std::__gcd(a,b) != 1 ? "Infinite" : "Finite") << '\n';
	}
}