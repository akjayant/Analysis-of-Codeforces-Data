#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

const ll N = 100010;
vector<ll> graph[N];
ll c[3][N], mod[N], visited[N];

void dfs(int ind, int pos){
    visited[ind] = 1;
    mod[ind] = pos%3;
    for(int i=0;i<graph[ind].size();i++){
        if(!visited[graph[ind][i]]){
            dfs(graph[ind][i], pos+1);
        }
    }
}

ll solve(ll arr[], ll n){
    ll res = 0;
    for(int i=1;i<=n;i++){
        res += c[arr[mod[i]]][i];
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,u,v,flag = 0,leaf, res = INT64_MAX, permind, tempind, temp;
    ll arr[3] = {0,1,2};
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>c[0][i];
    for(int i=1;i<=n;i++)   cin>>c[1][i];
    for(int i=1;i<=n;i++)   cin>>c[2][i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(graph[i].size() > 2){
            flag = 1;
            break;
        }
        else if(graph[i].size() == 1)   leaf = i;
    }
    if(!flag){
        memset(visited, 0, sizeof(visited));
        dfs(leaf,0);
        tempind = 0;
        do{
            temp = solve(arr, n);
            if(res > temp){
                res = temp;
                permind = tempind;
            }
            tempind++;
        }while (next_permutation(arr, arr + 3));
        cout<<res<<endl;
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        tempind = 0;
        do{
            if(tempind == permind){
                for(int i=1;i<=n;i++)   cout<<arr[mod[i]] + 1<<" ";
                cout<<endl;
                break;
            }
            tempind++;
        }while (next_permutation(arr, arr + 3));
    }
    else    cout<<-1<<endl;
    return 0;
}