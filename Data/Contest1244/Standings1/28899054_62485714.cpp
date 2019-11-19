#include<bits/stdc++.h>

template <class T>
bool Reduce(T &a,T const &b) {
    return a>b?a=b,1:0;
}

const int XN=1e5+11;

const long long INF=1e18;

int w[XN][3],n;
std::vector<int> G[XN];

bool ud[XN],vis[XN];

void Solve(int pos) {
    while(G[pos].size()!=1) {
        ud[pos]=1;
        for(int u : G[pos])
            if(!ud[u]) {
                pos=u;
                break;
            }
    }
    std::vector<int> s{0};
    do {
        vis[pos]=1;
        s.push_back(pos);
        for(int u : G[pos])
            if(!vis[u]) {
                pos=u;
                break;
            }
    }while(G[pos].size()!=1);
    s.push_back(pos);
    static long long f[XN][3][3];
    static std::pair<int,int> pre[XN][3][3];
    int cnt=s.size()-1;
    for(int i=1;i<=cnt;++i) {
        for(int s1=0;s1<3;++s1)
            for(int s2=0;s2<3;++s2)
                f[i][s1][s2]=INF;
        for(int s1=0;s1<3;++s1) 
            for(int s2=0;s2<3;++s2) if(s1!=s2)
                for(int s3=0;s3<3;++s3) if(s1!=s3 && s2!=s3)
                    if(Reduce(f[i][s2][s3],f[i-1][s1][s2]+w[s[i]][s3]))
                        pre[i][s2][s3]={s1,s2};
    }
    long long res=INF;
    std::pair<int,int> p;
    for(int s1=0;s1<3;++s1)
        for(int s2=0;s2<3;++s2)
            if(Reduce(res,f[cnt][s1][s2]))
                p={s1,s2};
    static int color[XN];
    for(int i=cnt;i>=1;--i) {
        color[s[i]]=p.second;
        p=pre[i][p.first][p.second];
    }
    std::cout<<res<<'\n';
    for(int i=1;i<=n;++i)
        std::cout<<(color[i]+1)<<(i==n?'\n':' ');
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    std::cin>>n;
    for(int i=1;i<=n;++i)
        std::cin>>w[i][0];
    for(int i=1;i<=n;++i)
        std::cin>>w[i][1];
    for(int i=1;i<=n;++i)
        std::cin>>w[i][2];
    for(int i=1;i<=n-1;++i) {
        int x,y;std::cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bool tak=1;
    for(int i=1;i<=n;++i)
        tak&=G[i].size()<=2;
    if(!tak)
        std::cout<<-1<<'\n';
    else {
        Solve(1);
    }
	return 0;
}

