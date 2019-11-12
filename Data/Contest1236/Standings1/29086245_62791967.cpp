#include <bits/stdc++.h>

const int XN=3e2+11;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int n;std::cin>>n;
    static std::vector<int> a[XN];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i&1?j:n-j+1].push_back((i-1)*n+j);
    for(int i=1;i<=n;++i)
        for(int j=0;j<n;++j)
            std::cout<<a[i][j]<<(j==n-1?'\n':' ');
	return 0;
}

