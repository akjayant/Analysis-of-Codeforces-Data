#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FOROP(i,a,b,op) for(int i=a;i<b;op)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define PB push_back
#define FI first
#define SE second
#define umap unordered_map
#define uset unordered_set
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define ALL(X) (X).begin(),(X).end()
#ifndef DEBUG
#define endl (char)10
#endif
using namespace std;
using ll = long long;

const int MAXN = 100005;
int T[MAXN][3];
int V[MAXN];
vii N(MAXN);
int PERM[MAXN];
int IPERM[MAXN];
bool vis[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    FOR(i,0,n) cin >> T[i][0];
    FOR(i,0,n) cin >> T[i][1];
    FOR(i,0,n) cin >> T[i][2];
    FOR(i,0,n) V[i] = 0;

    FOR(i,1,n){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a]++;
        V[b]++;
        N[a].PB(b);
        N[b].PB(a);
    }
    int ss = 0;
    FOR(i,0,n){
        if (V[i] >= 3 || V[i] == 0){
            cout << -1 << endl;
            return 0;
        }
        if (V[i] == 1) ss = i;
    }
    FOR(i,0,n) vis[i] = false;
    PERM[0] = ss;
    IPERM[ss] = 0;
    vis[ss] = true;
    FOR(i,1,n){
        for(int x : N[PERM[i - 1]]){
            if (!vis[x]){
                vis[x] = true;
                PERM[i] = x;
                IPERM[x] = i;
                break;
            }
        }
    }
    //cout << ">>>";
    //FOR(i,0,n) cout << PERM[i] << " ";
    //cout << endl;
    ll ans = (1ll << 60);
    int kto[3] = {0, 0, 0};
    FOR(i,0,3){
        FOR(j,0,3){
            if (j == i) continue;
            int k = 3 - i - j;
            ll cans = 0;
            int idx[3] = {i, j, k};
            FOR(s,0,n){
                cans += T[PERM[s]][idx[s % 3]];
            }
            if (cans < ans){
                ans = cans;
                FOR(s,0,3) kto[s] = idx[s];
            }
        }
    }
    cout << ans << endl;
    //invers perm
   FOR(i,0,n) cout << kto[IPERM[i] % 3] + 1 << " ";
    cout << endl;
}
