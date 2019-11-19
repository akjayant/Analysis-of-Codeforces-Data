#include <iostream>
int main() {
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int T; std::cin>>T;
	while (T-->0) {
		int a,b,c,d,k; std::cin>>a>>b>>c>>d>>k;
		int x=a/c+!!(a%c),y=b/d+!!(b%d);
		if (x+y<=k) std::cout<<x<<' '<<y<<'\n';
		else std::cout<<"-1\n";
	}
}