#include <bits/stdc++.h>

template <class T>
bool Enlarge(T &a,T const &b) {
    return a<b?a=b,1:0;
}

template <class T>
bool Reduce(T &a,T const &b) {
    return a>b?a=b,1:0;
}

const int XN=1e5+11;

std::vector<int> ho[XN],ve[XN];

int main() {
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m,k;std::cin>>n>>m>>k;
    long long tot=1LL*n*m-k;
    while(k--) {
        int x,y;std::cin>>x>>y;
        ho[x].push_back(y);
        ve[y].push_back(x);
    }
    for(int i=1;i<=n;++i) {
        ho[i].push_back(0);
        ho[i].push_back(m+1);
        std::sort(ho[i].begin(),ho[i].end());
   }
    for(int i=1;i<=m;++i) {
                ve[i].push_back(0);
        ve[i].push_back(n+1);
        std::sort(ve[i].begin(),ve[i].end());
    }
    int x=1,y=1;
    long long cnt=1;
    std::map<std::pair<int,int>,std::set<int>> dirs;
    int mnx=0,mny=0,mxx=n+1,mxy=m+1;
    for(;;) {
#define lb(a,b) std::lower_bound(a.begin(),a.end(),b)
#define ub(a,b) std::upper_bound(a.begin(),a.end(),b)
#define mp(x,y) std::make_pair(x,y)
#define check(x,y,c) dirs[mp(x,y)].insert(c); if(dirs[mp(x,y)].size()>2) { break; }
        int t;

        check(x,y,1);
        t=std::min(*ub(ho[x],y),mxy)-1;
        cnt+=t-y;
        y=t;
        Enlarge(mnx,x);

        check(x,y,1);
        t=std::min(*ub(ve[y],x),mxx)-1;
        check(x,y,2);
        cnt+=t-x;
        x=t;
        Reduce(mxy,y);

        check(x,y,2);
        t=std::max(*std::prev(lb(ho[x],y)),mny)+1;
        check(x,y,3);
        cnt+=y-t;
        y=t;
        Reduce(mxx,x);

        check(x,y,3);
        t=std::max(*std::prev(lb(ve[y],x)),mnx)+1;
        check(x,y,4);
        cnt+=x-t;
        x=t;
        check(x,y,4);
        Enlarge(mny,y);
    }
    std::cout<<(cnt==tot?"Yes":"No")<<'\n';
	return 0;
}

