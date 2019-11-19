#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 100005
#define mod 2000003
#define oo 1000000007
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
ll n, sc, c[4][N], cul[N], i, j, x, y, start, sol, coloring[N];
bool ok;
vector<int>v[N];
void df(int nod, int tata, int x, int y) {
    for(auto it : v[nod])
        if(it != tata) {
            int z = 6 - x - y;
            sc += c[z][it];
            cul[it] = z;
            df(it, nod, y, z);
        }
}
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> n;

    for(i = 1; i <= 3; i++)
        for(j = 1; j <= n; j++)
            cin >> c[i][j];

    ok = 1;

    for(i = 1; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);

        if(v[x].size() > 2 || v[y].size() > 2)
            ok = 0 ;
    }

    if(ok == 0) {
        cout << -1;
        return 0;
    }

    for(i = 1; i <= n; i++)
        if(v[i].size() == 1)
            break;

    start = i;
    sol = 100000000000000000;

    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++)
            if(i != j) {
                sc = 0;
                cul[start] = i;
                cul[v[start][0]] = j;
                sc += c[i][start];
                sc += c[j][v[start][0]];
                df(v[start][0], start, i, j);

                if(sc < sol) {
                    sol = sc;

                    for(int k = 1; k <= n; k++)
                        coloring[k] = cul[k];
                }

                sol = min(sol, sc);
            }
    }

    cout << sol << '\n';

    for(i = 1; i <= n; i++)
        cout << coloring[i] << ' ';

    return 0;
}
