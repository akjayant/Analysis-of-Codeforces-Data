#include <bits/stdc++.h>
const int N=1e2+10;
int T,n,a,b,c;
char s[N],ans[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	std::cin>>T;
	while(T--){
		std::cin>>n;
		std::cin>>a>>b>>c;
		std::cin>>s;
		for(int i=0;i<n;++i)ans[i]=0;
		int tot=0;
		for(int i=0;i<n;++i)
			if(s[i]=='R'){
				if(b){
					--b;
					ans[i]='P';
					++tot;
				}
			}else if(s[i]=='P'){
				if(c){
					--c;
					ans[i]='S';
					++tot;
				}
			}else if(a){
				--a;
				ans[i]='R';
				++tot;
			}
		for(int i=0;i<n;++i)
			if(ans[i]==0){
				if(a){
					--a;
					ans[i]='R';
				}else if(b){
					--b;
					ans[i]='P';
				}else if(c){
					--c;
					ans[i]='S';
				}
			}
		if(tot>=(n+1)/2){
			std::cout<<"YES\n";
			for(int i=0;i<n;++i)
				std::cout<<ans[i];
			std::cout<<'\n';
		}else std::cout<<"NO\n";
	}
	return 0;
}

