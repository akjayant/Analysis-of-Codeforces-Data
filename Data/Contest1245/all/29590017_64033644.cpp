//⣿⣿⣿⣿⣿⣿⠟⠋⠁⣀⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿
//⣿⣿⣿⣿⠋⠁⠀⠀⠺⠿⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⣿
//⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⠀⠀⠀⠀⠀⣤⣦⣄⠀⠀
//⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⠏⣿⣿⣿⣿⣿⣁⠀⠀⠀⠛⠙⠛⠋⠀⠀
//⡿⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⣰⣿⣿⣿⣿⡄⠘⣿⣿⣿⣿⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀
//⡇⠀⠀⠀⠀⠀⠀⠀⠸⠇⣼⣿⣿⣿⣿⣿⣷⣄⠘⢿⣿⣿⣿⣅⠀⠀⠀⠀⠀⠀⠀⠀
//⠁⠀⠀⠀⣴⣿⠀⣐⣣⣸⣿⣿⣿⣿⣿⠟⠛⠛⠀⠌⠻⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣶⣮⣽⣰⣿⡿⢿⣿⣿⣿⣿⣿⡀⢿⣤⠄⢠⣄⢹⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣿⣿⣿⣿⣿⡘⣿⣿⣿⣿⣿⣿⠿⣶⣶⣾⣿⣿⡆⢻⣿⣿⠃⢠⠖⠛⣛⣷⠀
//⠀⠀⢸⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣮⣝⡻⠿⠿⢃⣄⣭⡟⢀⡎⣰⡶⣪⣿⠀
//⠀⠀⠘⣿⣿⣿⠟⣛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⡿⢁⣾⣿⢿⣿⣿⠏⠀
//⠀⠀⠀⣻⣿⡟⠘⠿⠿⠎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣿⣿⠧⣷⠟⠁⠀⠀
//⡇⠀⠀⢹⣿⡧⠀⡀⠀⣀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⢰⣿⠀⠀⠀⠀
//⡇⠀⠀⠀⢻⢰⣿⣶⣿⡿⠿⢂⣿⣿⣿⣿⣿⣿⣿⢿⣻⣿⣿⣿⡏⠀⠀⠁⠀⠀⠀⠀
//⣷⠀⠀⠀⠀⠈⠿⠟⣁⣴⣾⣿⣿⠿⠿⣛⣋⣥⣶⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⣿ 
//⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//⣿⠛⣷⠀⠀⢸⣟⡛⠀⠀⣿⠛⣷⠀⠀⢸⣟⡛⠀⠀⣴⢟⣛⡀⠀⠀⣸⢿⣇⠀ 
//⣿⠉⠉⠀⠀⢸⣯⣥⠀⠀⣿⠉⠉⠀⠀⢸⣯⣥⠀⠀⢿⣮⣽⡇⠀⢠⡿⠶⣿⡄ 
#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 2010
#define MAXM 900009
#define MAXLOGN 20
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define pr printf
#define sc(x) scanf("%d", &x)
#define sc2(x, y) sc(x);sc(y)
#define sc3(x, y, z) sc2(x, y);sc(z)
#define scll(x) scanf("%lld", &x)
#define sc2ll(x, y) scll(x);scll(y)
#define sc3ll(x, y, z) sc2ll(x, y);scll(z)
#define ff first
#define ss second
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x))
#define LOWBIT(A) (A & -A)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair <ll, ll> pll;
typedef pair < ll, pll > plll;

vector < pll > ladj[MAXN];
ll w[MAXN], c[MAXN];
ll ranki[MAXN];
ll pai[MAXN];
pll menor[MAXN];
bool ligado[MAXN];
int ligados;
ll custo;
vector <ll> deslg[MAXN];

ll findi(ll node){
    if(pai[node] == node)return node;
    return pai[node] = findi(pai[node]);
}

bool unioni(ll a, ll b){
    a = findi(a);
    b = findi(b);
    if(a == b)return false;
    if(ranki[a] < ranki[b])swap(a, b);
    menor[a] = min(menor[a], menor[b]);
    pai[b] = a;
    ranki[a] += ranki[b];
    return true;
}

int main() {
    int n;
    sc(n);
    vector < pll > coord;
    coord.push_back({0,0});
    FOR1(i, n){
        pai[i] = i;
        ranki[i] = 1;
        ligado[i] = true;
    }
    ligados = n;
    FOR(i, n){
        ll x, y;
        sc2ll(x, y);
        coord.push_back({x, y});
    }
    FOR1(i, n){
        scll(c[i]);
        menor[i] = {c[i], i};
        custo += c[i];
    }
    FOR1(i, n)scll(w[i]);
    vector <plll> edges;
    FOR1(i, n){
        FOR1(j, n){
            if(i >= j)continue;
            ll dist = abs(coord[i].ff - coord[j].ff) + abs(coord[j].ss - coord[i].ss);
            dist = w[i] * dist + w[j] * dist;
            edges.push_back({dist, {i, j}});
        }
    }
    sort(all(edges));
    int needed = n - 1;
    int ind = 0;
    vector <plll> chooses;
    while(needed && ind < edges.size()){
        bool cond = edges[ind].ff + min(menor[findi(edges[ind].ss.ff)], menor[findi(edges[ind].ss.ss)]).ff < (menor[findi(edges[ind].ss.ff)].ff + menor[findi(edges[ind].ss.ss)].ff);
        ll maxi = max(menor[findi(edges[ind].ss.ff)], menor[findi(edges[ind].ss.ss)]).ff;
        ll quemDesligar;
        if(menor[findi(edges[ind].ss.ff)] > menor[findi(edges[ind].ss.ss)]){
            quemDesligar = menor[findi(edges[ind].ss.ff)].ss;
        }else quemDesligar = menor[findi(edges[ind].ss.ss)].ss;
        if(cond && unioni(edges[ind].ss.ff, edges[ind].ss.ss)){
            needed--;
            custo += edges[ind].ff;
            custo -= maxi;
            ligado[quemDesligar] = false;
            ligados--;
            chooses.push_back(edges[ind]);
        }
        ind++;
    }
    pr("%lld\n", custo);
    pr("%d\n", ligados);
    FOR1(i, n)if(ligado[i])pr("%d ", i);
    pr("\n");
    pr("%d\n", sz(chooses));
    FOR(i, sz(chooses))pr("%lld %lld\n", chooses[i].ss.ff, chooses[i].ss.ss);
    return 0;
} 
