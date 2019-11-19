#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 1000000007
#define double long double
#define BINF 100000000000001
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 15000001
const int LG = 22;

vector<int>v[N], order;
int a[4][N], deg[N];
int vis[N];

void dfs(int u, int p){
    vis[u] = 1;
    order.push_back(u);
    for(auto i : v[u]){
        if(vis[i] == 0){
            dfs(i, u);
        }
    }
}


#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
    
    

    int n;
    cin >> n;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    int mx = 0;
    for(int i = 0; i <= n; i++)
        mx = max(mx, deg[i]);
    if(mx >= 3){
        cout << -1 << endl;
        return 0;
    }
    int root = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1){
            root = i;
            break;
        }
    }
    dfs(root, 0);

    int st = 0, sum = BINF;
    int p[] = {1, 2, 3};
    int ans[3];

    do{
        int x = 0;
        int c = 0;
        for(int j = 0; j < n; j++){
                int node = order[j];
                c += a[p[x]][node];
                x++;
                if(x == 3) x = 0;
        }

        if(c < sum){
            sum = c;
            for(int j = 0; j < 3; j++)
                ans[j] = p[j];
        }

    }while(next_permutation(p, p + 3));

    int x = 0;

    int lol[n + 1];



    cout << sum << endl;
    for(int i = 0; i < n; i++){
        int z = order[i];
        lol[z] = ans[i % 3];
    }
    for(int i = 1; i <= n; i++) cout <<  lol[i] << ' ';
    cout << endl;

    


return 0; 
}