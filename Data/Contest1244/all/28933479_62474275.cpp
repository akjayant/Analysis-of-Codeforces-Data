#include<bits/stdc++.h>
using namespace std;
inline long long rd() {
    long long x=0;
    bool neg=false;
    char c=getchar();
    while (c!='-'&&(c<'0'||c>'9'))
        c=getchar();
    if (c=='-')
        neg=true, c=getchar();
    while (c>='0'&&c<='9')
        x=x*10+c-'0', c=getchar();
    if (neg)
        x=-x;
    return x;
}
inline void write(long long x) {
    if (x<0) {
        putchar('-');
        x=-x;
    }
    if (x>9)
        write(x/10);
    putchar(x%10+'0');
}
typedef long long ll;
typedef pair<long long,long long> ii;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define rep(i,x) for(long long _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(long long _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(long long _b=b,i=a;i>=_b;--i)
#define x first
#define y second
#define _ putchar(' ')
#define __ putchar('\n')
using namespace std;
const long long N=1e5+2;
long long n,a[4][N],dd[N],d[N];
vector<long long> v,ad[N];
void dfs(long long u) {
    if(dd[u]) return;
    dd[u]=1;
    v.push_back(u);
    for(auto v:ad[u]) dfs(v);
}
int main() {
    fast_io;
    cin >> n;
    finc(i,1,3) finc(j,1,n) cin >> a[i][j];
    finc(i,2,n) {
        long long u,v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
        ++d[u];
        ++d[v];
    }
    finc(i,1,n) if(d[i]>2){
        cout << -1;
        return 0;
    }
    long long i=1;
    while(i<=n&&d[i]>1) ++i;
    dfs(i);
    long long res=(long long)1<<60;
    vector<long long> x= {1,2,3};
    do {
        long long total_r=0;
        finc(i,0,n-1) total_r+=a[x[i%3]][v[i]];
        res=min(res,total_r);
    } while(next_permutation(all(x)));
    cout<<res<<"\n";
    x= {1,2,3};
    vector<long long> ccc(n+1);
    do {
        long long total_r=0;
        finc(i,0,n-1) total_r+=a[x[i%3]][v[i]];
        if(total_r==res) {
            finc(i,0,n-1) ccc[v[i]]=x[i%3];
            finc(i,1,n) cout<<ccc[i]<<" ";
            return 0;
        }
    } while(next_permutation(all(x)));
    return 0;
}
