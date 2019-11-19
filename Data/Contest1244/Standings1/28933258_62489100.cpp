#include <iostream>
#define ll long long

using namespace std;

ll vals[100001][3];
int con[100001][2];
int gc[3];
int todo[6][3] = {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {2, 1, 3}, {1, 3, 2}};
int anss[100001];

ll dfs(int c, int prev, int color)
{
    color = color % 3;
    if(c == 0)
        return 0;
    return vals[c][gc[color]-1] + dfs(con[c][con[c][0] == prev], c, color+1);
}

void printdfs(int c, int prev, int color)
{
    if(c == 0)
        return;
    color = color % 3;
    anss[c] = gc[color];
    printdfs(con[c][con[c][0]==prev], c, color+1);
}

int main()
{
    int n;
    cin >> n;
    for(int j = 0; j < 3; ++j)
        for(int i = 1; i <= n; ++i)
            cin >> vals[i][j];
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(con[a][1] || con[b][1])
        {
            cout << -1;
            return 0;
        }
        int aa = !!con[a][0];
        int bb = !!con[b][0];
        con[a][aa] = b;
        con[b][bb] = a;
    }
    int root;
    for(int i = 1; i <= n; ++i)
    {
        if(!con[i][1])
        {
            root = i;
            break;
        }
    }

    ll ans = 10000000000000000LL;
    int index;
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 3; ++j)
            gc[j] = todo[i][j];
        ll val = dfs(root, 0, 0);
        if(val < ans)
        {
            ans = val;
            index = i;
        }
    }
    cout << ans << '\n';
    for(int j = 0; j < 3; ++j)
    {
        gc[j] = todo[index][j];
    }
    printdfs(root, 0, 0);
    for(int i = 1; i <= n; ++i)
        cout << anss[i] << ' ';
    return 0;
}
