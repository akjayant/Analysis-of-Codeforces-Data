#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll D = 2007;
const ll modulo = 1000000007;

vector <pair <pair <ll, ll>, ll> > edges;
ll n, x[D], y[D], c[D], k[D];
ll parent[D], cost[D];
vector <ll> stations;
vector <pair <ll, ll> > connections;

bool compare(pair <pair <ll, ll>, ll> a1, pair <pair <ll, ll>, ll> a2)
{
    return (a1.second < a2.second) || (a1.second == a2.second  &&  a1.first.first < a2.first.first) ||
           (a1.second == a2.second  &&  a1.first.first == a2.first.first  &&  a1.first.second < a2.first.second);
}

ll find_par(ll v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_par(parent[v]);
}

void unite(ll v1, ll v2, ll price)
{
    ll p1 = find_par(v1), p2 = find_par(v2);
    if (p1 == p2)
        return;

    if (v1 == 0)
        stations.push_back(v2);
    else if (v2 == 0)
        stations.push_back(v1);
    else
        connections.push_back({v1, v2});

    if (rand() % 2 == 0) // connect to p1
    {
        parent[p2] = p1;
        cost[p1] += cost[p2] + price;
    }
    else        // connect to p2
    {
        parent[p1] = p2;
        cost[p2] += cost[p1] + price;
    }

}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (ll i = 1; i <= n; i++)
        cin >> c[i];
    for (ll i = 1; i <= n; i++)
        cin >> k[i];

    for (ll i = 1; i <= n; i++)
        for (ll j = i + 1; j <= n; j++)
        {
            edges.push_back({{i, j}, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])) });
            edges.push_back({{j, i}, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])) });
        }
    for (ll i = 1; i <= n; i++)
        edges.push_back({{0, i}, c[i]}),
        edges.push_back({{i, 0}, c[i]});

    sort(edges.begin(), edges.end(), compare);
    for (ll i = 1; i <= n; i++)
        parent[i] = i, cost[i] = 0;

    for (auto edge : edges)
        unite(edge.first.first, edge.first.second, edge.second);

    cout << cost[find_par(0)] << endl;
    cout << stations.size() << endl;
    for (ll item : stations)
        cout << item << " ";
    cout << endl << connections.size() << endl;
    for (auto item : connections)
        cout << item.first << " " << item.second << endl;
    return 0;
}
