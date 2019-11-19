#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> v(100010);
ll c[3][100010];
ll cnt=0;
ll totori,nyaa;
ll root=0;
ll sc;

ll dfs(int now,int pre,int cl,int pc){
    ll ret = c[cl][now];
    if(now==root){
        ll res = dfs(v[now][0],now,(cl+1)%3,cl);
        ll re = dfs(v[now][0],now,(cl+2)%3,cl);
        if(res > re){
            sc = (cl+2)%3;
            res = re;
        }
        else sc = (cl+1)%3;
        ret += res;
    }
    else{
        for(auto i:v[now]){
            if(i != pre){
                ret += dfs(i,now,(3-pc-cl),cl);
            }
        }
    }
    return ret;
}

int col[100010];
void solve(int p,int pre,int cl,int cll){
    col[p] = cl;
    for(auto i:v[p]){
        if(i!=pre){
            solve(i,p,3-cl-cll,cl);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
        if(v[a].size()>=3 || v[b].size()>=3){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i].size()==1){
            root = i;
            break;
        }
    }
    ll ans = 1e18;
    for(int i=0;i<3;i++){
        ll t = dfs(root,-1,i,-1);
        if(t<ans){
            ans = t;
            totori = i;
            nyaa = sc;
        }
    }
    cout << ans << endl;
    solve(root,-1,totori,3-totori-nyaa);
    for(int i=0;i<n;i++){
        cout << col[i]+1 << " ";
    }
    cout << endl;
    

}