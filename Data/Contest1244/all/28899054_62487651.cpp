#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    long long n,p,w,d;
    std::cin>>n>>p>>w>>d;
    bool tak=0;
    for(long long y=0;y<=w;++y) {
        if((p-y*d)%w==0) {
            long long x=(p-y*d)/w;
            if(x+y<=n && x>=0 && y>=0) {
                std::cout<<x<<' '<<y<<' '<<(n-x-y)<<'\n';
                tak=1;
                break;
            }
        }
    }
    if(!tak)
        std::cout<<-1<<'\n';
  	return 0;
}

