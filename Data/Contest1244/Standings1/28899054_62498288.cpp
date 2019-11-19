#include <bits/stdc++.h>

template <class T>
bool Reduce(T &a,T const &b) {
    return a>b?a=b,1:0;
}

const int XN=1e5+11;

long long n,k;
int a[XN];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    std::cin>>n>>k;
    std::map<int,int> map;
    for(int i=1;i<=n;++i) {
        std::cin>>a[i];
        map[a[i]]++;
    }
    while(k && map.size()>1) {
        if(map.rbegin()->second<map.begin()->second) {
            auto p=*map.rbegin();
            map.erase(std::prev(map.end()));
            long long d=k/p.second,g=std::max(1LL*map.rbegin()->first,p.first-d);
            map[g]+=p.second;
            k-=1LL*(p.first-g)*p.second;
            if(p.first==g)
                break;
        } else {
            auto p=*map.begin();
            map.erase(map.begin());
            long long d=k/p.second,g=std::min(1LL*map.begin()->first,p.first+d);
            map[g]+=p.second;
            k-=1LL*(g-p.first)*p.second;
            if(p.first==g)
                break;
        }
    }
    std::cout<<(map.rbegin()->first-map.begin()->first)<<'\n';
	return 0;
}

