#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

class UF
{
private:
    int         num;
    vector<int> par;
    vector<int> siz;
public:
    //vector<int> val;
public:
    UF(int n): num(n) {
        par.resize(n);
        siz.resize(n);
        //val.resize(n);
        int i;
        for(i=0; i<n; i++) {
            par[i]=i; siz[i]=1;
            //val[i]=0;
        }
    }
	
    int find(int x) {
        if(x==par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(siz[x]<siz[y]) {
            par[x]=y;
            siz[y]=siz[x]+siz[y];
            //val[y]=val[x]+val[y];
        }
        else {
            par[y]=x;
            siz[x]=siz[x]+siz[y];
            //val[x]=val[x]+val[y];
        }
    }

    bool same(int x, int y) {
        return find(x)==find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }

    int ngroup() {
    //int ngroup( int& ans ) {
        int count=0;
        int i;
        for(i=0; i<num; i++) {
            if(par[i]==i) {
                count++;
                //ans += (val[i]? siz[i]: siz[i]-1);
            }
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> x(n),y(n),c(n),k(n);
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for(i=0; i<n; i++) {
        scanf("%d", &c[i]);
    }
    for(i=0; i<n; i++) {
        scanf("%d", &k[i]);
    }

    vector<pair<ll, pair<int,int> > > z;   // dist, i, j
    for(i=0; i<n; i++) {
        z.push_back(make_pair(c[i], make_pair(n, i)));
    }
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            ll dist = ((ll)k[i]+k[j])*(abs((ll)x[i]-x[j])+abs((ll)y[i]-y[j]));
            z.push_back(make_pair(dist, make_pair(i,j)));
        }
    }
    sort(z.begin(), z.end());

    vector<pair<int,int> > ans0;
    vector<int> ans;
    ll alldist=0;
    UF uf(n+1);
    int siz=(int)z.size();
    for(i=0; i<siz; i++) {
        ll  dist=z[i].first;
        int i0=z[i].second.first;
        int i1=z[i].second.second;
        if(uf.same(i0,i1)) {
            continue;
        }

        uf.unite(i0,i1);
        alldist += dist;

        if(i0==n) ans.push_back(i1);
        else if(i1==n) ans.push_back(i0);
        else ans0.push_back(make_pair(i0,i1));
    }

    printf("%lld\n", alldist);
    printf("%d\n", (int)ans.size());
    for(i=0; i<(int)ans.size(); i++) {
        printf("%d ", ans[i]+1);
    }
    printf("\n");

    printf("%d\n", (int)ans0.size());
    for(i=0; i<(int)ans0.size(); i++) {
        printf("%d %d\n", ans0[i].first+1, ans0[i].second+1);
    }

    return 0;
}

