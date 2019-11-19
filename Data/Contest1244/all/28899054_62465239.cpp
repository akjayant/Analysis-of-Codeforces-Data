#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int T;std::cin>>T;
    while(T--) {
        int a,b,c,d,k;
        std::cin>>a>>b>>c>>d>>k;
        bool tak=0;
        for(int i=0;i<=k;++i) {
            int j=k-i;
            if(i*c>=a && j*d>=b) {
                std::cout<<i<<' '<<j<<'\n';
                tak=1;
                break;
            }
        }
        if(!tak)
            std::cout<<-1<<'\n';
    }
	return 0;
}

