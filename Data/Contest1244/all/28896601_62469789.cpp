#include <bits/stdc++.h>
int a,b,c,d,k,t;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	std::cin>>t;
	while(t--){
		std::cin>>a>>b>>c>>d>>k;
		int x=a/c+(a%c>0),y=b/d+(b%d>0);
		if(x+y<=k)
			std::cout<<x<<' '<<y<<'\n';
		else std::cout<<"-1\n";
	}
	return 0;
}

