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
        //#define endl "\n"
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif

    cout.precision(7);
    cout << fixed;

}

struct Zdarovo{
    int b,ind,x,r,flag;
};

const int N = 1e6+7;
const ll MOD = 998244853;

const int INF = 1e18+7;


const int K = 2e2+2;


int n;
int arr[N];

void input(){
    int n;
    cin >> n;
    int p = n;
    int c = 0;
    int cnt = 0;
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0){
            cnt++;
            c = i;
            while(n%i == 0){
                n /= i;
            }
        }
    }

    if(n != 1){
        cnt++;
        c = n;
    }

    if(cnt == 1){
        cout << c;
    }else{
        cout << 1;
    }

}

void solve(){

}

signed main(){
    volodya22();
    input();
    solve();
}
