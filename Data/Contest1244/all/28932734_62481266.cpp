#include <iostream>
#include <vector>

using namespace std;

int V;
vector<vector<int>> edges;
long long costs[100100][3];
bool vis[100100];
int col[100100];
int sol[100100];

long long dfs(int loc, int f, int s, int t, int c){
    vis[loc] = true;
    if(c >= 3)
        c = 0;
    if(c == 0)
        col[loc] = f;
    else if(c == 1)
        col[loc] = s;
    else
        col[loc] = t;

    long long cost = 0;

    for(int to : edges[loc])
        if(!vis[to])
            cost += dfs(to, f, s, t, c + 1);

    return cost + costs[loc][col[loc]];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int V;
    cin >> V;
    edges.resize(V+10);
    for(int i = 0; i < V; i++)
        cin >> costs[i][0];
    for(int i = 0; i < V; i++)
        cin >> costs[i][1];
    for(int i = 0; i < V; i++)
        cin >> costs[i][2];

    bool ok = true;

    for(int i = 0; i < V - 1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);

        if(edges[a].size() > 2 || edges[b].size() > 2)
            ok = false;
    }

    if(!ok){
        cout << - 1 << endl;
        return 0;
    }

    int start = 0;
    for(int i = 0; i < V; i++)
        if(edges[i].size() == 1)
            start = i;

    long long res = -1;
    for(int f = 0; f <= 2; f++){
        for(int s = 0; s <= 2; s++){
            if(f == s)
                continue;

            int t;
            if((f == 0 && s == 1) || (f == 1 && s == 0))
                t = 2;
            if((f == 1 && s == 2) || (f == 2 && s == 1))
                t = 0;
            if((f == 0 && s == 2) || (f == 2 && s == 0))
                t = 1;

            for(int i = 0; i < V; i++){
                vis[i] = false;
                col[i] = -1;
            }

            long long r = dfs(start, f, s, t, 0);
            if(res == -1 || r < res){
                res = r;
                for(int i = 0; i < V; i++)
                    sol[i] = col[i];
            }
        }
    }

    cout << res << endl;
    for(int i = 0; i < V; i++)
        cout << sol[i]+1 << " ";
    cout << endl;
    return 0;
}
