#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> tree;
vector<int> f;

void z(int i)
{
    i += f.size();
    i/=2;
    while(i)
    {
        if(f[tree[i*2]] <= f[tree[i*2+1]])
        {
            tree[i] = tree[i*2];
        }
        else
        {
            tree[i] = tree[i*2+1];
        }
        i/=2;
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int h =1;
    while(h<n)
        h*=2;
    f.resize(h);
    tree.resize(h*2);
    for(int i=0;i<h;i++)
    {
        tree[i+h] = i;
    }
    vector<vector<int> > graf(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=n;i<f.size();i++)
    {
        f[i] = n+1;
        z(i);
    }
    //cout << "ok";
    f[0] = n+1;
    z(0);
    for(int i=0;i<graf[0].size();i++)
    {
        f[graf[0][i]]++;
        z(graf[0][i]);
    }
    //cout << "ok";
    int out = 0;
    for(int k=1;k<n;k++)
    {
        int v = tree[1];
        if(f[v] == k)
        {
            out++;
        }
        f[v] = n+1;
        z(v);
        for(int i=0;i<graf[v].size();i++)
        {
            f[graf[v][i]]++;
            z(graf[v][i]);
        }
    }
    cout << out;
    //cin >>n;
    return 0;
}
