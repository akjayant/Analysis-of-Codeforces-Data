#include <algorithm>
#include <iostream>
#include <map>
typedef long long ll;
std::map<int,int> m;
inline std::pair<int,int> gmin() {
	return *m.begin();
}
inline std::pair<int,int> gmax() {
	std::map<int,int>::iterator it=m.end();
	return *--it;
}
int main() {
	int n; ll k; std::cin>>n>>k;
	for (int i=0;i<n;++i) {
		int x; std::cin>>x;
		++m[x];
	}
	while (1) {
		if (m.size()==1) {
			std::cout<<"0\n";
			return 0;
		}
		std::pair<int,int> a=gmin(),b=gmax();
		if (m.size()==2) {
			int sz=std::min(a.second,b.second);
			std::cout<<std::max(0ll,b.first-a.first-k/sz)<<'\n';
			return 0;
		}
		m.erase(a.first),m.erase(b.first);
		std::pair<int,int> c=gmin(),d=gmax();
		if (k<std::min(a.second,b.second)) {
			std::cout<<b.first-a.first<<'\n';
			return 0;
		}
		if (a.second>b.second) {
			if (k/b.second>=b.first-d.first)
				m[a.first]+=a.second,m[d.first]+=b.second,k-=1ll*(b.first-d.first)*b.second;
			else return std::cout<<b.first-a.first-k/b.second<<'\n',0;
		}
		else  {
			if (k/a.second>=c.first-a.first)
				m[c.first]+=a.second,m[b.first]+=b.second,k-=1ll*(c.first-a.first)*a.second;
			else return std::cout<<b.first-a.first-k/a.second<<'\n',0;
		}
	}
}