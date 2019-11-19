#include <bits/stdc++.h>

const int XN=1e5+11;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    static int a[XN];
    int n;std::cin>>n;
    //n/2 n/2 横竖
    for(int i=1;i<=n;++i)
        std::cin>>a[i];
    /*
    int x=n/2,y=n-x;
    std::cout<<std::max(Solve(x,y),Solve(y,x))<<'\n';
    */
    std::sort(a+1,a+1+n);
    int sum[2]={0};
    for(int i=1;i<=n;++i)
        sum[i<=n/2]+=a[i];
#define p2(x) (1LL*(x)*(x))
    std::cout<<(p2(sum[0])+p2(sum[1]))<<'\n';
	return 0;
}

