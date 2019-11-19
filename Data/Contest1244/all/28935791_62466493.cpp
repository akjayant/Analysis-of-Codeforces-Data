#include <iostream>
inline void smax(int& s,const int& a) { if (s<a) s=a; }
int main() {
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int T; std::cin>>T;
	while (T-->0) {
		int n; std::cin>>n;
		int ans=n+1; bool flag=0;
		for (int i=0;i<n;++i) {
			char x; std::cin>>x;
			if (x=='1') {
				flag=1;
				smax(ans,2*(i+1));
				smax(ans,2*(n-i));
			}
		}
		if (!flag) --ans;
		std::cout<<ans<<'\n';
	}
}