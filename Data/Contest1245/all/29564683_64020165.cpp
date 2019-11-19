#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long


ll mod=(ll)1e9+7;

vector<int> dpX(2e3+2,0);
vector<int> dpY(2e3+2,0);
vector<ll> c(2e3+2, 0);
vector<ll> k(2e3+2, 0);
vector<pair<ll, pair<int, int>>> vert(0);
vector<int> ansTowns(0);
vector<pair<int, int>> ansRoads(0);
vector<int> parent(2e3+2,0);
vector<int> rankk(2e3+2, 0);


int findPar(int v){
    if(parent[v]==v) return v;
    else return parent[v]=findPar(parent[v]);
}

void unite(int u, int v){
    u=findPar(u);
    v=findPar(v);
    if(u==v){
        return;
    }
    if(rankk[u]>rankk[v]){
        parent[v]=u;
    }
    else{
        if(rankk[u]==rankk[v]) rankk[v]++;
        parent[u]=v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<n+1;i++){
        cin>>dpX[i];
        cin>>dpY[i];
    }
    for(int i=1;i<n+1;i++){
        cin>>c[i];
    }
    for(int i=1;i<n+1;i++){
        cin>>k[i];
    }

    for(int i=1;i<n+1;i++){
        vert.push_back({c[i],{0, i}});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            vert.push_back({(abs(dpX[i]-dpX[j])+abs(dpY[i]-dpY[j]))*(k[i]+k[j]), {i, j}});
        }
    }

    sort(vert.begin(), vert.end());
    for(int i=0;i<n+1;i++){
        parent[i]=i;
        rankk[i]=1;
    }
    ll ans=0;
    for(auto &son:vert){
        int u=son.second.first;
        int v=son.second.second;
        if(findPar(u)==findPar(v)) continue;
        unite(u,v);
        ans+=son.first;
        if(u==0){
            ansTowns.push_back(v);
        }
        else{
            ansRoads.push_back(son.second);
        }
    }
    cout<<ans<<endl;
    cout<<ansTowns.size()<<endl;
    for(int i:ansTowns){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<ansRoads.size()<<endl;
    for(auto &i:ansRoads){
        cout<<i.first<<" "<<i.second<<endl;
    }





}