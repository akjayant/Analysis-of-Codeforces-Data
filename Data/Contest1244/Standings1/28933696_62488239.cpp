#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int c[3][MAX];
int ans[3][MAX];
int used[MAX];
vector <vector <int>> g;
vector <int> graph;

dfs(int v)
{
    used[v] = 1;
    graph.push_back(v);
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(used[u] == 0)
            dfs(u);
    }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n; i++)
        cin >> c[0][i];
    for(int i = 0; i < n; i++)
        cin >> c[1][i];
    for(int i = 0; i < n; i++)
        cin >> c[2][i];
    for(int i = 0; i < n - 1; i++)
    {
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    long long kray = -1;
    for(int i = 0; i < n; i++)
    {
        if(g[i].size() == 1)
            kray = i;
        if(g[i].size() >= 3)
        {
            cout << -1;
            return 0;
        }
    }

    long long ans = 1e18;
    dfs(kray);
/*for(int i = 0; i < graph.size(); i++)
    {
        cout << graph[i] << ' ';
    }
    cout << endl;*/

    vector <int> good_ans = {};

    for(int  i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i != j)
            {
                vector <int> good;
                good.resize(n);
                long long ansy = 0;
                for(int k = 0; k < n; k++)
                {
                    long long v = graph[k];
                    if(k % 3 == 0){
                        ansy += c[i][v];
                        good[v] = i;
                    }
                    if(k %3 == 1){
                        ansy += c[j][v];
                        good[v] = j;
                    }
                    if(k %3 == 2){
                        ansy += c[3 - j - i][v];
                        good[v] = 3 - i - j;
                    }
                    good[v];
                }
                if(ansy < ans)
                {
                    good_ans = good;
                    ans = ansy;
                }
            }
        }
    }


    cout << ans<< endl;
    for(int i = 0; i < n; i++)
        cout << good_ans[i]  + 1 << ' ';

}
