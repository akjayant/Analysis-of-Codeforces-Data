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

int n,p,w,d;

int f(int x){
    int u = p - x*w;
    return (u+d-1)/d;
}

void input(){
    cin >> n >> p >> w >> d;

    int l = -1,r = n+1;
    while(l+1 < r){
        int mid = (l+r)/2;
        if(f(mid) > (n-mid)) l = mid;
        else r = mid;
    }

    //r = l;

    if((p > 0 && d > p) || f(n) > 0){
        cout << -1;
        exit(0);
    }

    //cout << r << endl;

    int c = (p-r*w);

    for(int i = 0;i < d+w;i++){
        if(c-i*w < 0) break;
        int a = c-i*w;

        if(a%d == 0){
            cout << r+i << ' ' << a/d << ' ' << (n-r-i-a/d);
            exit(0);
        }
    }

    cout << -1;
}

void solve(){

}

signed main(){
    volodya22();
    input();
    solve();
}
