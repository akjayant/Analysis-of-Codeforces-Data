#include<bits/stdc++.h>
#define mino "A"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define Down(i,a,b) for(int i=a;i>=b;i--)
#define FOR_(i,a,b) for(int i=a;i<b;i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1000000000

const int N = 2e3 + 5;

using namespace std;

typedef pair<int,int> pii;

int n,m,cha[N],l[N];
int kt[N];
ll cp[N], k[N], x[N], y[N];
int res[N], top1;
int kq[N*N+N][2], top2;
struct canh
{
    int u,v;
    ll w;
};
canh c[N*N+N];
void nhap()
{
    cin >> n;
    FOR(i,1,n) cin >> x[i] >> y[i];
    FOR(i,1,n) cin >> cp[i];
    FOR(i,1,n) cin >> k[i];

    FOR(i,1,n) cha[i] = i;
}
bool cmp(canh A, canh B)
{
    return A.w < B.w;
}
int tim(int u)
{
    if(cha[u] != u) cha[u] = tim(cha[u]);
    return cha[u];
}
void hop(int u, int v)
{
    u = tim(u);
    v = tim(v);
    if(u == v) return;
    if(l[u] == l[v]) l[u]++;
    if(l[u] > l[v]) cha[v] = u;
    else cha[u] = v;
}
void xuli()
{
    FOR(i,1,n)
    {
        FOR(j,i,n)
        {
            if(i == j)
            {
                m++;
                c[m].u = i;
                c[m].v = j;
                c[m].w = cp[i];
            }
            else
            {
                m++;
                c[m].u = i;
                c[m].v = j;
                c[m].w = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
            }
        }
    }
    ll S = 0;
    sort(c+1,c+m+1,cmp);
    FOR(i,1,m)
    {
        int u = tim(c[i].u);
        int v = tim(c[i].v);
        if(c[i].u == c[i].v)
        {
            if(kt[u] == 0)
            {
                S += c[i].w;
                kt[u] = 1;
                top1++;
                res[top1] = c[i].u;
            }
        }
        else
        {
            if(u == v) continue;
            if(kt[u] + kt[v] == 2) continue;
            if(kt[u] + kt[v] == 1)
            {
                hop(u,v);
                kt[tim(u)] = 1;
                kt[tim(v)] = 1;
            }
            else hop(u,v);
            top2++;
            kq[top2][0] = c[i].u;
            kq[top2][1] = c[i].v;
            S += c[i].w;
        }
    }
    cout << S << '\n';
    cout << top1 << '\n';
    FOR(i,1,top1) cout << res[i] << ' ';
    cout << '\n';
    cout << top2 << '\n';
    FOR(i,1,top2)
    {
        cout << kq[i][0] << ' ' << kq[i][1] << '\n';
    }
}
int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);
    nhap();
    xuli();
}
