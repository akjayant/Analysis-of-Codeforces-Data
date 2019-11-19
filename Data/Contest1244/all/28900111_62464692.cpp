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
const ll INF = 2e9+7;
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



void input(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d,k;
        bool g = 0;
        cin >> a >> b >> c >> d >> k;
        for(int i = 0;i <= k;i++){
            int u = (k-i);
            if(i*c >= a && u*d >= b){
                g = 1;
                cout << i << ' ' << u << endl;
                break;
            }
        }
        if(!g) cout << -1 << endl;
    }

}

void solve(){

}

signed main(){
    volodya22();
    input();
    solve();
}
