#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) x.begin(),x.end()
#define len(x) (int)(x).size()
#define int long long

/*
#pragma GCC omptimize("unroll-loops")
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("no-stack-protector")
#pragma comment(linker, "/STACK:10000000000")
*/


using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pari;
typedef vector<vi > matrix;

ld PI = 3.14159265358979323846;


typedef tree<int, null_type, less<int >,
    rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void volodya22(){
    #ifdef THERE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen("fibonacci.in", "r", stdin);
        //freopen("fibonacci.out", "w", stdout);
        #define endl "\n"
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif

    //cout.precision(6);
    //cout << fixed;

}


const int N = 2e6+7;
const int alphabet = 256;
const ll INF = 1e18+7;
const ll MOD = 998244353;
const ld eps = 1e-8;
const int K = 2000+7;

int m1 = 998244353;
int m2 = 1e9+9;
int p1 = 347;
int p2 = 108;

struct Zdarovo{
    int x,c;
};

int n;
vi g[N];
int arr[N][3];

vi op;

int A[N];

int dfs(int x,int p){
    op.push_back(x);
    for(int i : g[x])
        if(i != p) dfs(i,x);
}

void input(){
    cin >> n;

    for(int i = 0;i < n;i++)
        cin >> arr[i][0];

    for(int i = 0;i < n;i++)
        cin >> arr[i][1];

    for(int i = 0;i < n;i++)
        cin >> arr[i][2];

    for(int i = 0;i < n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0;i < n;i++){
        if(len(g[i]) > 2){
            cout << -1;
            exit(0);
        }
    }

    for(int i = 0;i < n;i++){
        if(len(g[i]) == 1){
            dfs(i,i);
            break;
        }
    }

    //for(int i : op) cout << i << ' ';
    //cout << endl;

    int ans = INF;

    vi c;

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(i == j) continue;
            int p = (3-i-j);
            vi t = {i,j,p};
            int r = 0;
            int cnt = 0;
            for(int x : op){
                r += arr[x][t[cnt%3]];
                cnt++;
            }
            if(r < ans){
                ans = r;
                c = t;
            }
            //cout << i << ' ' << j << ' ' << p << ' ' << r << endl;
        }
    }

    cout << ans << endl;

    int cnt = 0;

    for(int i : op){
        //cout << c[cnt%3]+1 << ' ';
        A[i] = c[cnt%3]+1;
        cnt++;
    }

    for(int i = 0;i < n;i++)
        cout << A[i] << ' ';

}

void solve(){

}

signed main(){
    volodya22();
    input();
    solve();
}
