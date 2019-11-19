#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
ll mod = 1000LL*1000LL*1000LL + 7;

vector<pair<ll,ll>> coor;
vector<ll> c;
vector<ll> k;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout.tie(0);
    cout.sync_with_stdio(false);
    int n;
    cin >> n;
    coor.resize(n);
    c.resize(n);
    k.resize(n);
    for(int i=0;i<n;i++)
        cin >> coor[i].x >> coor[i].y;
    for(int i=0;i<n;i++)
        cin >> c[i];
    for(int i=0;i<n;i++)
        cin >> k[i];
    priority_queue<pair<ll,pair<int,int>>> a;
    for(int i=0;i<n;i++)
    {
        a.push({-c[i],{i,i}});
    }
    vector<bool> used(n,false);
    ll out = 0;
    int h =0;
    vector<int> out1;
    vector<pair<int,int>> out2;
    out1.reserve(n);
    out2.reserve(n);
    while(h<n)
    {

        int v = a.top().y.x;
        if(!used[v])
        {
            out += -a.top().x;
            if(a.top().y.x == a.top().y.y)
                out1.push_back(a.top().y.x);
            else
                out2.push_back(a.top().y);
        }

        a.pop();
        if(!used[v])
        {
            h++;
            used[v] = true;
            for(int i=0;i<n;i++)
            {
                if(v!=i && !used[i])
                {
                    a.push({-(abs(coor[i].x - coor[v].x ) + abs(coor[i].y - coor[v].y))*(k[i] + k[v]),{i,v}});
                }
            }
        }
    }
    cout << out << '\n';
    cout << out1.size() << '\n';
    for(int i=0;i<out1.size();i++)
        cout << out1[i]+1 << ' ';
    cout << '\n';
    cout << out2.size() << '\n';
    for(int i=0;i<out2.size();i++)
        cout << out2[i].x+1 << ' ' << out2[i].y+1 << '\n';
       
    return 0;
}
