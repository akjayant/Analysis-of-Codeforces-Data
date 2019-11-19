#include <bits/stdc++.h>

const int XN=2e3+11;

int dsu[XN];
int Root(int x) {
    return dsu[x]?dsu[x]=Root(dsu[x]):x;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    static int x[XN],y[XN],c[XN],k[XN];
    int n;std::cin>>n;
    for(int i=1;i<=n;++i)
        std::cin>>x[i]>>y[i];
    for(int i=1;i<=n;++i)
        std::cin>>c[i];
    for(int i=1;i<=n;++i)
        std::cin>>k[i];
    std::vector<std::tuple<long long,int,int>> edges;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            edges.emplace_back(1LL*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),i,j);
    std::vector<std::pair<int,int>> app1;
    long long sum1=0;
    int cnt=0;
    for(auto &[w,x,y] : edges)
        if(Root(x)!=Root(y)) {
            app1.emplace_back(x,y); 
            dsu[Root(x)]=y;
            sum1+=w;
            if(++cnt==n-1)
                break;
        }
    
    memset(dsu,0,sizeof(dsu));
    long long sum2=cnt=0;
    for(int i=1;i<=n;++i)
        edges.emplace_back(c[i],i,n+1);
    std::sort(edges.begin(),edges.end());
    std::vector<std::pair<int,int>> app2;
    for(auto &[w,x,y] : edges)
        if(Root(x)!=Root(y)) {
            app2.emplace_back(x,y); 
            dsu[Root(x)]=y;
            sum2+=w;
            if(++cnt==n)
                break;
        }
    auto app=app2;
    std::cout<<sum2<<'\n';
    std::vector<int> ps;
    for(auto p : app)
        if(p.second==n+1)
            ps.push_back(p.first);
    std::cout<<ps.size()<<'\n';
    for(int x : ps)
        std::cout<<x<<' ';
    std::cout<<'\n';
    std::cout<<app.size()-ps.size()<<'\n';
    for(auto p : app)
        if(p.second!=n+1)
            std::cout<<p.first<<' '<<p.second<<'\n';
	return 0;
}
