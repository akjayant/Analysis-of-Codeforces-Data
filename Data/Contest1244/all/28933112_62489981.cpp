#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

vector<int> tonari[100010];

void solve(){
    int n; cin>>n;
    vector<vector<int>> c(3,vector<int>(n,0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>c[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int a,b; cin>>a>>b;
        --a; --b;
        tonari[a].push_back(b);
        tonari[b].push_back(a);
    }
    int start=-1;
    //鎖か確認
    for (int i = 0; i < n; ++i) {
        int cnt=tonari[i].size();
        if(cnt>2){
            cout<<-1<<endl;
            return;
        }else if(cnt==1){
            start=i;
        }
    }

    vector<int> group(n,-1);
    queue<int> q;
    q.push(start);
    group[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto tsugi:tonari[node]){
            if(group[tsugi]>=0) continue;
            group[tsugi]=(group[node]+1)%3;
            q.push(tsugi);
        }
    }
    //for (int i = 0; i < n; ++i) cout<<group[i]<<endl;
    ll ans=1e18;
    vector<int> ansc(3);
    vector<int> col={0,1,2};
    do{
        ll tmp=0ll;
        for (int i = 0; i < n; ++i) {
            tmp+=(ll)c[col[group[i]]][i];
        }
        if(tmp<ans){
            ans=tmp;
            ansc[0]=col[0]; ansc[1]=col[1]; ansc[2]=col[2];
        }
        //cout<<tmp<<" "<<col[0]<<" "<<col[1]<<" "<<col[2]<<endl;
    }while(next_permutation(col.begin(),col.end()));
    cout<<ans<<endl;
    for (int i = 0; i <n-1 ; ++i) {
        cout<<ansc[group[i]]+1<<" ";
    }
    cout<<ansc[group[n-1]]+1<<endl;
    return;
}


int main() {
    solve();
    return 0;
}
