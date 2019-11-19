#include <bits/stdc++.h>
const int N=1e3+10;
int n;
char s[N];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	int T;
	std::cin>>T;
	while(T--){
		std::cin>>n>>s;
		int ans=n;
		for(int i=1;i<=n;++i)
			if(s[i-1]=='1')
				ans=std::max(ans,std::max(i+i,n-i+n-i+2));
		std::cout<<ans<<'\n';
	}
	return 0;
}

