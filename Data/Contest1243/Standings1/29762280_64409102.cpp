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


const int K = 300;


int n,m;
set<pari > st;

set<int> t;
int used[N];

int ans = 0;

void dfs(int ind){
    used[ind] = 1;
    vi d;
    for(int i : t){
        if(!st.count({ind,i})){
            d.push_back(i);
        }
    }

    for(int i : d){
        t.erase(i);
    }

    for(int i : d){
        if(!used[i]){
            dfs(i);
        }
    }

    if(ind == 0){
        while(len(t)){
            ans++;
            dfs(*(t.begin()));
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        st.insert({a,b});
        st.insert({b,a});
    }

    for(int i = 0;i < n;i++)
        t.insert(i);

    dfs(0);

    cout << ans;
}

void solve(){

}

signed main(){
    volodya22();
    input();
    solve();
}
