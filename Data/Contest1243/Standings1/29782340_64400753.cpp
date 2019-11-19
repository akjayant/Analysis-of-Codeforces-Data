#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll n,m,tu,x,y,l,k,p,u;
vector<ll> tee[100005],v,vaad[100005];
bool b[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        tee[x].push_back(y);
        tee[y].push_back(x);
    }
    for(int i=1; i<=n; i++) sort(tee[i].begin(),tee[i].end());
    p=0;
    for(int i=2; i<=n; i++) vaad[0].push_back(i);
    for(int i=1; i<=n; i++) if(!b[i]){
        v.resize(0);
        v.push_back(i);
        tu++;
        l=0;
        while(l<v.size()){
            k=v[l];
            b[k]=1;
            u=0;
            for(int j=0; j<vaad[p].size(); j++){
                while(u<tee[k].size() && tee[k][u]<vaad[p][j]) u++;
                if(u==tee[k].size() || tee[k][u]!=vaad[p][j]) v.push_back(vaad[p][j]);
                else vaad[p+1].push_back(vaad[p][j]);
            }
            p++;
            l++;
        }
    }
    cout<<tu-1<<"\n";
}
