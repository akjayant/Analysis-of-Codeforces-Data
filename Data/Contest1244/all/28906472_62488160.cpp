#include <bits/stdc++.h>

using namespace std ;

#define N 100005
#define pb push_back
#define ll long long
#define mod 1000000007
#define pll pair<ll, ll>
#define double long double
#define fi first
#define se second
#define INF 1e18
#define Base 1200

ll c[3][N];

vector<int> edge[N];
vector<int> sorted;
int color[N];


int main(){
    ios_base :: sync_with_stdio(false);
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)
        cin >> c[0][i];

    for(int i = 1 ; i <= n ; i++)
        cin >> c[1][i];

    for(int i = 1 ; i <= n ; i++)
        cin >> c[2][i];

    int x , y;
    bool flag = true;
    for(int i = 0 ; i < n - 1 ; i++){
        cin >> x >> y ;
        edge[x].pb(y);
        edge[y].pb(x);
        if(edge[x].size() > 2 || edge[y].size() > 2)
            flag = false;
    }

    if(flag == false)
        return cout << - 1 << endl , 0;

    int root ;
    for(int i = 1 ; i <= n ; i++){
        if(edge[i].size() == 1){
            root = i;
            break;
        }
    }

    sorted.pb(root);
    int node = root , p = root;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < edge[node].size(); j++){
            if(edge[node][j] == p)
                continue;
            p = node;
            node = edge[node][j];
            break;
        }
        sorted.pb(node);
    }

    ll ans = INF , temp;
    int idx;
    int a[] = {0 , 1 , 2};
    int b[3];
    do{
        temp = 0;
        for(int i = 0 ; i < n ; i++){
            node = sorted[i];
            idx = a[i % 3];
            temp += c[idx][node];
        }
        if(ans > temp){
            ans = temp;
            for(int i = 0 ; i < 3 ; i++)
                b[i] = a[i] + 1;
        }

    }while(next_permutation(a , a + 3));

    cout << ans << endl;

    for(int i = 0 ; i < n ; i ++){
        color[sorted[i]] = b[i % 3];
    }

    for(int i = 1 ; i <= n ; i++)
        cout << color[i] <<' ' ;
    cout << endl;

    return 0;
}


