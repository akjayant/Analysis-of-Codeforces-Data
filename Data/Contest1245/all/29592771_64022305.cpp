#include <bits/stdc++.h>

#define ll long long
#define pii pair <ll, ll>
#define piii pair <pii, ll>
#define f first
#define s second
#define mp make_pair

using namespace std;

ll n, i, j, cost, cost_min;
ll c[2010], k[2010];
ll prez[2010];

priority_queue <piii, vector <piii>, greater <piii> > pq;

pii poz[2010];

vector <pii> v[2010];
vector <pii> roads;
vector <ll> stations;

int main()
{
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> poz[i].f >> poz[i].s;
    for(i=1; i<=n; i++)
    {
        cin >> c[i];
        v[0].push_back(mp(c[i], i));
    }
    for(i=1; i<=n; i++)
    {
        cin >> k[i];
    }
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
    {
        cost = (k[i] + k[j]) * (abs(poz[i].f - poz[j].f) + abs(poz[i].s-poz[j].s));
        v[i].push_back(mp(cost, j));
        v[j].push_back(mp(cost, i));
    }
    for(i=0; i<=n; i++)
        sort(v[i].begin(), v[i].end());


    for(auto it : v[0])
        pq.push(mp(it, 0));

    for(i=1; i<=n; i++)
    {
        while(prez[pq.top().f.s] != 0) pq.pop();
        piii nod = pq.top(); pq.pop();
        prez[nod.f.s] = 1;
        cost_min += nod.f.f;

        if(nod.s == 0) stations.push_back(nod.f.s);
        else roads.push_back(mp(nod.s, nod.f.s));

        for(auto it : v[nod.f.s])
            pq.push(mp(it, nod.f.s));
    }


    cout << cost_min << '\n';
    cout << stations.size() << '\n';
    for(auto it : stations)
        cout << it << " ";
    cout << '\n' << roads.size() << '\n';
    for(auto it : roads)
        cout << it.f << " " << it.s << '\n';
    return 0;
}
