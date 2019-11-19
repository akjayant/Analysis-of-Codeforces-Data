#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
const ll OO = 1e16;

vector < int > adj[N];
int n;
ll c[3][N] , b[N] , ans[N];
ll dp[N][4][4];

ll get(int i = 0 , int j = 3 , int k = 3)
{
    if(i == n) return 0;
    ll &ret = dp[i][j][k];
    if(ret + 1) return ret;

    ret = OO;
    if(j != 0 && k != 0)
        ret = min(ret , c[0][b[i]] + get(i+1 , 0 , j));
    if(j != 1 && k != 1)
        ret = min(ret , c[1][b[i]] + get(i+1 , 1 , j));
    if(j != 2 && k != 2)
        ret = min(ret , c[2][b[i]] + get(i+1 , 2 , j));
    return ret;
}
void getPath(int i = 0 , int j = 3 , int k = 3)
{
    if(i == n) return;

    ll ret = get(i,j,k);

    if(j != 0 && k != 0 && ret == c[0][b[i]] + get(i+1 , 0 , j))
        {
            ans[b[i]] = 1;
            getPath(i+1 , 0 , j);
            return;
        }
    if(j != 1 && k != 1 && ret == c[1][b[i]] + get(i+1 , 1 , j))
        {
            ans[b[i]] = 2;
            getPath(i+1 , 1 , j);
            return;
        }
    if(j != 2 && k != 2 && ret == c[2][b[i]] + get(i+1 , 2 , j))
        {
            ans[b[i]] = 3;
            getPath(i+1 , 2 , j);
            return;
        }
}
int cnt = 0;
bool dfs(int i , int p = -1)
{
    int ch = (int)adj[i].size() - (p != -1);
    if(ch > 1) return false;
    b[cnt++] = i;
    for(auto x : adj[i])if(x != p)
        return dfs(x , i);
    return true;
}
int main()
{
    ios::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> c[i][j];
    for(int i = 1 ; i < n ; i++)
    {
        int u , v;  cin >> u >> v;  u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root;
    for(int i = 0 ; i < n ; i++)if(adj[i].size() < 2) root = i;

    bool ok = dfs(root);
    if(!ok) return cout << "-1\n" , 0;

    memset(dp , -1 , sizeof(dp));
    cout << get() << endl;
    getPath();
    for(int i = 0 ; i < n ; i++)
    {
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
