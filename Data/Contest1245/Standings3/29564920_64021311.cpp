#include <string.h>
#include <unordered_map>

#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <set>

#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf

#define pf printf
#define mp make_pair
#define N 5000000

using namespace std;

const int mod = 1000000007;
struct Edge{
    int a,b;
    ll c;
    Edge(){}
    Edge(int a, int b, ll c):a(a),b(b),c(c){}
}e[N];

int x[N],y[N],c[N],k[N];
int cost[N];
int n;
int cnt;

int fa[N];

void init(){
    fr(i,0,n+1){
        fa[i] = i;
        cost[i] = i;
    }
    cnt = 0;
}

int f(int t) {
    if(fa[t]!=t) fa[t] = f(fa[t]);
    return fa[t];
}

ll dis(int a, int b) {
    ll xx = abs(x[a]-x[b])+abs(y[a]-y[b]);
    return xx *( k[a]+k[b]);
}

int main() {
    cin>>n;
    init();
    fr(i,1,n+1) {
        sf("%d%d",&x[i],&y[i]);
    }
    fr(i,1,n+1) {
        sf("%d",&c[i]);
    }
    fr(i,1,n+1) {
        sf("%d",&k[i]);
    }

    fr(i,1,n+1) {
        fr(j,i+1,n+1) {
            ll w = dis(i,j);
            e[cnt++] = Edge(i,j,w);
        }
    }

    auto cmp = [&](const Edge &a, const Edge &b) {
        return a.c < b.c;
    };
    vector< pair<int,int> > ans;
    sort(e,e+cnt, cmp);
    ll tot = 0;
    for(int i = 0; i < cnt; ++i) {
        int a = e[i].a, b = e[i].b;
        if(f(a) == f(b))continue;

        ll w = e[i].c;
        //printf("a = %d b = %d w = %lld\n",a,b,w);
        int f1 = f(a), f2 = f(b);
        if(w<max(c[cost[f1]], c[cost[f2]])) {
            fa[f1] = f2;
            //printf("get a = %d b = %d w = %lld cost1 = %d cost2 = %d\n",a,b,w,cost[f1],cost[f2]);
            if(c[cost[f1]]>c[cost[f2]]) {
                cost[f2] = cost[f2];
            }
            else {
                cost[f2] = cost[f1];
            }
            ans.pb( mp(a,b) );
            tot += w;
        }
    }

    vector<int> node;
    for(int i = 1; i <= n; ++i) {
        if(f(i)==i) {
            node.pb( cost[i] );
            tot += c[cost[i]];
        }
    }

    cout<<tot<<endl;
    cout<<node.size()<<endl;
    for(auto x : node) {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<ans.size()<<endl;
    for(auto x : ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}