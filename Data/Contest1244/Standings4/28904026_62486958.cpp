#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <ctime>
#include <complex>
//#include <random>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define forn(i,n) for(int i = 0;i<n;i++)
#define for1(i,n) for(int i = 1;i<=n;i++)

#define pb push_back
//#define mp make_p/**/air
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<string,string> PSS;

typedef unsigned us;
typedef unsigned int ui;
typedef unsigned long long ull;
const ll mod=1e9+7;
const ll MOD=123456789;
const ll inf = 2e18;
const int maxn = 100005;
const int maxm = 500005;
ll printArray(ll a[],int t){cout<<"[";for(int i = 0;i<t;i++){cout<<a[i];if(i!=t-1)cout<<", ";}cout<<"]"<<endl;return 0;}
ll printArray(int a[],int t){cout<<"[";for(int i = 0;i<t;i++){cout<<a[i];if(i!=t-1)cout<<", ";}cout<<"]"<<endl;return 0;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; if(b<0) return -1; for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//ll powmod2(ll a,ll b) {ll res=1;a%=MOD; if(b<0) return -1; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll inv_mod(ll a){return powmod(a,mod-2);}

int vis[maxn];
ll cost[maxn][3];
vector<int>  e[maxn];
int du[maxn];
int color[maxn];
int anscol[maxn];
int main() {
    int n;
    cin>>n;
    for1(i,n) cin>>cost[i][0];
    for1(i,n) cin>>cost[i][1];
    for1(i,n) cin>>cost[i][2];

    forn(i,n-1){
        int u,v;
         cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        du[u] ++;
        du[v] ++;
    }


    int st = -1;
    int nt = -1;
//    printArray(du, n + 1);
    for1(i,n){
        if(du[i] == 1){
            st = i;
            nt = e[i][0];
//            cout<<st<<" "<<nt<<endl;
            break;
        }
    }

    int col[3] = {0,1,2};
    ll ans = mod * mod;
    ll temp;

    do{
//        printArray(col,3);
        memset(vis,0,sizeof(vis));

        temp = 0;
        color[st] = col[0];
        color[nt] = col[1];
        int cnt = 2;
        int i = st;
        while(i != -1){
//            cout<<"I: "<<i<<endl;
            if(color[i] != -1){
                color[i] = col[cnt++];
                cnt %= 3;
            }
            vis[i] = 1;
            if(du[i] > 2){
                cout<<-1<<endl;
                return 0;
            }

            temp += cost[i][color[i]];

            int nx = -1;

            for(auto k: e[i]){
//                cout<<"K: "<<k<<" "<<vis[k]<<endl;
                if(vis[k] == 0){
                    nx = k;
                }
            }
            i = nx;


        }
//        cout<<temp<<endl;
        if(temp < ans){
            for1(t,n){
                anscol[t] = color[t] + 1;
            }
            ans = min(ans,temp);
        }


    }while(next_permutation(col,col+3));
    cout<<ans<<endl;
    for1(i,n) cout<<anscol[i]<<" ";
    cout<<endl;



}



/*
4 6
1 2
2 3
3 1
4 1
4 2
4 3


3 3
1 2
2 3
3 1

 */





















