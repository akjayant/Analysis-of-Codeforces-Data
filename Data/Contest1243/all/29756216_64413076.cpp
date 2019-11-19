#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;

const int mod=1e9+7;

int n,m,x,y,ans;
set<int>s;
map<int,int>edge[100005];

void dfs(int nod){
    vector<int>viz;
    auto it=s.begin();
    while(it!=s.end()){
        if(*it!=nod){
            if(edge[*it].count(nod)==0) viz.push_back(*it);
        }
        it++;
    }
    for(int i=0;i<viz.size();i++) s.erase(s.find(viz[i]));
    for(int i=0;i<viz.size();i++) dfs(viz[i]);
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        edge[x][y]=1;
        edge[y][x]=1;
    }
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++){
        if(s.find(i)!=s.end()){ ans++; dfs(i); }
    }
    rc(ans-1);
}
