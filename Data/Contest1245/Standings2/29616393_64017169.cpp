#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

namespace UFS{
    #define UFS_N 2001//节点数，注意修改
    int f[UFS_N+2];
    void init(int n=UFS_N){
        rep(i,0,n+1){
            f[i]=i;
        }
    }
    int fd(int nd){
        return (f[nd]==nd? nd:f[nd]=fd(f[nd]));
    }
    void cmb(int a,int b){
        f[fd(b)]=fd(a);
    }
}

namespace MST{
    #define u second.first
    #define v second.second
    #define w first
    vector<pair<LL,pair<int,int> > > vc,ans;
    LL w_sum=0;
    void add_edge(int a,int b,LL lw){
        vc.push_back(make_pair(lw,make_pair(a,b)));
    }
    void build(int n){
        sort(vc.begin(),vc.end());
        UFS::init(n);
        for(auto &eg:vc){
            auto fu=UFS::fd(eg.u),fv=UFS::fd(eg.v);
            if(fu!=fv){
                ans.push_back(eg);UFS::cmb(fu,fv);
                w_sum+=eg.w;if(ans.size()==n-1) break;
            }
        }
    }
}
int n;LL x[2001],y[2001],c[2001],k[2001];
vector<int> bd;vector<pair<int,int> > eg;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;UFS::init(n);
    rep(i,0,n){
        cin>>x[i+1]>>y[i+1];
    }
    rep(i,1,n+1) cin>>c[i];
    rep(i,1,n+1) cin>>k[i];
    rep(i,1,n+1){
        MST::add_edge(0,i,c[i]);
        rep(j,i+1,n+1){
            MST::add_edge(i,j,
            (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])));
        }
    }
    MST::build(n+1);
    cout<<MST::w_sum<<endl;
    for(auto &p:MST::ans){
        if(p.u==0) bd.push_back(p.v);
        else eg.push_back(make_pair(p.u,p.v));
    }
    cout<<bd.size()<<endl;
    for(auto &nd:bd) cout<<nd<<' ';
    cout<<endl;
    cout<<eg.size()<<endl;
    for(auto &p:eg) cout<<p.first<<' '<<p.second<<endl;
    //system("pause");
    return 0;
}
