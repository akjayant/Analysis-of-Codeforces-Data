#include<bits/stdc++.h>
using namespace std;

vector<tuple<long long, int, int> > V;
int N;
int x[2020], y[2020], c[2020], k[2020];
int ufd[2020];
void init()
{
    for(int i=0; i<2020; ++i) ufd[i] = i;
}
int Find(int a)
{
    if(a==ufd[a]) return a;
    return ufd[a] = Find(ufd[a]);
}
void Union(int a, int b)
{
    ufd[Find(a)] = Find(b);
}
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) scanf("%d%d", x+i, y+i);
    for(int i=1; i<=N; ++i) scanf("%d", c+i);
    for(int i=1; i<=N; ++i) scanf("%d", k+i);

    for(int i=1; i<=N; ++i) V.emplace_back(c[i], 0, i);
    for(int i=1; i<=N; ++i)
        for(int j=1; j<i; ++j)
        {
            long long cost = 1LL*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
            V.emplace_back(cost, i, j);
        }
    sort(V.begin(), V.end());
    
    vector<pair<int, int> > E;

    long long ans = 0;
    init();
    for(auto [c, i, j]: V)
    {
        if(Find(i) == Find(j)) continue;
        Union(i, j);
        ans += c;
        E.emplace_back(i, j);
    }

    vector<int>power;
    vector<pair<int, int> > conn;
    for(auto [u, v]: E)
    {
        if(u==0 || v == 0)
        {
            power.emplace_back(u+v);
        }
        else conn.emplace_back(u ,v);
    }
    printf("%lld\n", ans);
    printf("%d\n", (int)power.size());
    for(auto x: power) printf("%d ", x); puts("");
    printf("%d\n", (int)conn.size());
    for(auto [u, v]:conn)
        printf("%d %d\n", u, v);
    return 0;

}