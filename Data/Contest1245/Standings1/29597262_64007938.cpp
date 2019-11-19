#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <set>
#define MODD 1000000007
#define ll long long
using namespace std;

ll X[2222];
ll Y[2222];
ll C[2222];
ll K[2222];


ll GetDist(ll x1,ll y1,ll x2,ll y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int parent[2222+2];
int rankk[2222+2];

int Find(int x) {
    if (parent[x] != x) {
        parent[x]=Find(parent[x]);
    }
    return parent[x];
}

bool Union(int x,int y) {
    int xRoot=Find(x);
    int yRoot=Find(y);
    if (xRoot==yRoot)
        return false;
    
    if (rankk[xRoot]<rankk[yRoot]) {
        parent[xRoot]=yRoot;
    } else if (rankk[xRoot]>rankk[yRoot]) {
        parent[yRoot]=xRoot;
    } else {
        parent[yRoot]=xRoot;
        rankk[xRoot]++;
    }
    return true;
}



int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>X[i]>>Y[i];
    }
    for(int i=1;i<=n;i++)
        cin>>C[i];
    for(int i=1;i<=n;i++)
        cin>>K[i];
    vector<pair<ll,pair<int,int>>> cities;
    
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n+1;j++) {
            if (j <= n) {
                cities.push_back({(K[i]+K[j])*GetDist(X[i],Y[i],X[j],Y[j]), {i,j}});
            } else {
                cities.push_back({C[i], {i,j}});
            }
        }
    
    for(int i=1;i<=n+1;i++) {
        parent[i]=i;
        rankk[i]=0;
    }
    
    sort(cities.begin(),cities.end());
    ll ans = 0;
    vector<int> ps;
    vector<pair<int,int>> edges;
    for(int i=0;i<cities.size();i++) {
        int u = cities[i].second.first;
        int v = cities[i].second.second;
        if (Union(u,v)) {
            ans += cities[i].first;
            if (v == n+1) {
                ps.push_back(u);
            } else {
                edges.push_back({u,v});
            }
        }
    }
    
    cout << ans << endl;
    cout << ps.size() << endl;
    for(int p : ps) {
        printf("%d ",p);
    }
    cout << endl;
    cout << edges.size() << endl;
    for(auto uv : edges) {
        
        printf("%d %d\n",uv.first,uv.second);
    }
    
    
}
