#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = 8e18+9999;

struct city
{
    ll x, y;
    ll c, k;
    city(ll x=0, ll y=0, ll c=0, ll k=0) : x(x), y(y), c(c), k(k) {}
};

int main()
{
    int n;
    cin >> n;
    vector <city> country(n);
    vector <ll> dist(n);
    vector <int> prev(n, -1);
    vector <bool> used(n, 0);
    ll sum = 0;

    for (int i=0; i<n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        country[i] = city(x, y);
    }
    for (int i=0; i<n; ++i)
    {
        ll c;
        cin >> c;
        country[i].c = c;
        dist[i] = c;
    }
    for (int i=0; i<n; ++i)
    {
        ll k;
        cin >> k;
        country[i].k = k;
    }

    int v = 0;
    int t=-1;
    ll mn = INF;

    for (int i=0; i<n; ++i)
        if (!used[i] && dist[i] < mn)
            t = i, mn = dist[t];
    while (t != -1)
    {
        used[t] = 1;
        city city1 = country[t];
        if (prev[t] == -1)
            ++v;
        sum += mn;
        for (int i=0; i<n; ++i)
        {
            if (!used[i])
            {
                city city2 = country[i];
                ll nw = (city1.k + city2.k) * (abs(city1.x - city2.x) + abs(city1.y - city2.y));
                if (nw < dist[i])
                    dist[i] = nw, prev[i] = t;
            }
        }
        t = -1;
        mn = INF;
        for (int i=0; i<n; ++i)
            if (!used[i] && dist[i] < mn)
                t = i, mn = dist[t];
    }

    cout << sum << "\n" << v << "\n";
    for (int i=0; i<n; ++i)
        if (prev[i] == -1)
            cout << i+1 << " ";
    cout << "\n";
    cout << n - v << "\n";
    for (int i=0; i<n; ++i)
        if (prev[i] != -1)
            cout << i+1 << " " << prev[i] + 1 << "\n";

    return 0;
}










