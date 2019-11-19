#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int MAXN = 2003;

int n;
int x[MAXN], y[MAXN], c[MAXN], k[MAXN];

struct edge{
    int u,v;
    long long w;
    edge(int a, int b, long long c){
        u=a;v=b;w=c;
    }
};

bool operator<(const edge& a, const edge& b){
    return a.w>b.w;
}

vector<edge> es;
vector<int> s1;
vector<edge> s2;
int uf[MAXN];


int fnd(int x){
    if(uf[x]==x) return x;
    else return uf[x]=fnd(uf[x]);
}
void un(int a, int b){
    uf[fnd(a)]=fnd(b);
}

int main(){
    for(int i=0;i<MAXN;++i) uf[i]=i;
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i=0;i<n;++i){
        int c;
        scanf("%d", &c);
        es.push_back(edge(0, i+1, c));
    }
    for(int i=0;i<n;++i){
        scanf("%d", &k[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            es.push_back(edge(i+1, j+1, ((long long)k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))));
        }
    }
    sort(es.begin(), es.end());
    long long sol=0;
    while(!es.empty()){
        auto curr = es.back();
        es.pop_back();
        if(fnd(curr.u)!=fnd(curr.v)){
            if(curr.u==0){
                s1.push_back(curr.v);
            }else{
                s2.push_back(curr);
            }
            sol+=curr.w;
            un(curr.u, curr.v);
        }
    }
    printf("%lld\n", sol);
    printf("%ld\n", s1.size());
    for(auto i:s1) printf("%d ", i);
    printf("\n%ld\n", s2.size());
    for(auto i:s2) printf("%d %d\n", i.u, i.v);
}
