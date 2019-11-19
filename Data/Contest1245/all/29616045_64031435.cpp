#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define X   first
#define Y   second
#define pb  push_back
#define FOR(i,a,b)  for(int i = a ; i <= b ; ++i)

const int   N   = 2e3 + 1;
const ll    inf = 1e15;

typedef pair<int,int>   ii;
typedef pair<ll,ii>     ed;

namespace   DSU {
    int p[N];
    int s[N];

    int init(int n) {
        iota(p,p + 1 + n,0);
        fill(s,s + 1 + n,1);
        return  1;
    }
    int lead(int x) {
        return p[x] == x ? x : p[x] = lead(p[x]);
    }
    int join(int x,int y)   {
        x = lead(x);
        y = lead(y);
        if (x == y) return  0;
        if (s[x] < s[y])
            swap(x,y);
        p[y] = x;
        s[x] += s[y];
        return  1;
    }
};

int B[N], K[N];       //buildCost
int x[N], y[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    vector<ed>  E;

    FOR(i,1,n)  cin >> x[i] >> y[i];
    FOR(i,1,n)  cin >> B[i];
    FOR(i,1,n)  cin >> K[i];
    FOR(i,1,n)  FOR(j,1,n)   {
        ll  C = 1ll * (K[i] + K[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        if (i < j)
            E.pb(ed(C,{i,j}));
    }
    FOR(i,1,n)  E.pb(ed(B[i],{0,i}));

    DSU::init(n);
    sort(E.begin(),E.end());

    ll  ans = 0;

    vector<int> Vert;
    vector<ii>  Edge;

    for(ed  e : E)  {
        int x = e.Y.X;
        int y = e.Y.Y;

        if (DSU::join(x,y)) {
            ans += e.X;
            if (x == 0)
                Vert.push_back(y);
            else
                Edge.push_back({x,y});
        }
    }

    cout << ans;

    cout << "\n" << Vert.size() << "\n";    for(int x : Vert)   cout << x << " ";
    cout << "\n" << Edge.size() << "\n";    for(ii  e : Edge)   cout << e.X << " " << e.Y << "\n";
}