#include <bits/stdc++.h>

template <class T>
bool Enlarge(T &a,T const &b) {
    return a<b?a=b,1:0;
}

const int XN=1e3+11;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int T;std::cin>>T;
    while(T--) {
        static char s[XN];
        int n;std::cin>>n>>(s+1);
        int Ans=n;
        for(int i=1;i<=n;++i)
            if(s[i]=='1') {
                Enlarge(Ans,2*i);
                Enlarge(Ans,2*(n-i+1));
            }
        std::cout<<Ans<<'\n';
    }
	return 0;
}

