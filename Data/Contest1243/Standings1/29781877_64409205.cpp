#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

const int N = 100 * 1000 + 5;

int n, m;

set<int> g[N];


int main() {
    cin >> n >> m;

    loop(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }


    set<pii> st;
    for(int i = 1; i <= n; i++){
        st.insert({-g[i].size(), i});
    }

    int mnac = n;
    int ans = 0;
    while(!st.empty()){
        int v = st.begin()->second;
//        db(v);
        int d = -st.begin()->first;
        st.erase(st.begin());
        if(d == mnac-1){
//            cout << "add" << endl;
            ans++;
        }

        // siktir
        for(int to : g[v]){
            st.erase({-g[to].size(), to});
            g[to].erase(v);
            st.insert({-g[to].size(), to});
        }
        mnac--;
        g[v].clear();
    }

cout << ans-1 << endl;

    return 0;
}
/*



*/