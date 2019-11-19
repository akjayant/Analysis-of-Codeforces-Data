#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef unordered_map<int,int> mii;

#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

vi parent,size,ks,cs;

void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

vector<pair<ll,ll>> info;

struct tup {
    ll dist;
    ll v1,v2;
};

bool operator<( tup &t1, tup &t2 ) {
    return t1.dist < t2.dist;
}

vector<tup> distv;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,a,b;
    cin >> n;
    parent.resize(n+1);
    size.resize(n+1);
    info.clear();
    rep(i,n+1) {
        make_set(i);
    }
    ks.clear();
    cs.clear();
    info.push_back(ii{-1,-1});
    ks.push_back(-1);
    cs.push_back(-1);
    rep(i,n) {
        cin >> a >> b;
        info.push_back(ii{a,b});
    }
    rep(i,n) {
        cin >> a;
        cs.push_back(a);
    }
    rep(i,n) {
        cin >> a;
        ks.push_back(a);
    }
    rap(i,1,n+1) {
        rap(j,i+1,n+1) {
            distv.push_back(tup{((abs(info[i].first - info[j].first) + abs(info[i].second - info[j].second))*(ks[i]+ks[j])),i,j});
        }
    }
    rap(i,1,n+1) {
        distv.push_back(tup{cs[i],0,i});
    }
    sort(distv.begin(),distv.end());
    vi vs;
    vii conns;
    vs.clear();
    conns.clear();
    ll i=0,a1,a2;
    ll cost=0;
    while (size[find_set(0)] < n+1) {
        a1 = find_set(distv[i].v1);
        a2 = find_set(distv[i].v2);
        if (a1 != a2) {
            if (distv[i].v1 == 0 || distv[i].v2 == 0) {
                if (distv[i].v1==0) {
                    vs.push_back(distv[i].v2);
                }
                else vs.push_back(distv[i].v1);
            }
            else {
                conns.push_back(ii{distv[i].v1,distv[i].v2});
            }
            union_sets(a1,a2);
            cost += distv[i].dist;
        }
        i++;
    }
    cout << cost << '\n';
    cout << vs.size() << '\n';
    rep(i,(int)vs.size()) {
        cout << vs[i] << ' ';
    }
    cout << '\n';
    cout << conns.size() << '\n';
    rep(i,(int)conns.size()) {
        cout << conns[i].first << ' ' << conns[i].second << '\n';
    }


    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}