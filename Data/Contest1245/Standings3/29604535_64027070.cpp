#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)
#define FORD(i,r,l) for(int i = r; i >= l; --i)
#define REPD(i,r,l) for(int i = r; i > l; --i)
#define pi pair<int,int>
#define pii pair<LL,pi>
#define mp make_pair
#define fi first
#define se second

const int maxN = 2001 + 11;
const LL oo = 1e17 + 11;

int N;
int G[maxN];
pi A[maxN];
LL C[maxN],K[maxN],D[maxN];

struct cmp{
    bool operator ()(pii X,pii Y){
        return X.fi > Y.fi;
    }
};

priority_queue <pii,vector<pii>,cmp> heap;

vector <pi> list_edges;
vector <int> list_powers;

LL res = 0;

void build_edges(){
    FOR(i,1,N){
        heap.push(mp(C[i],mp(0,i)));
        D[i] = C[i];
    }
}

void find_result(){
    while(!heap.empty()){
        pii X = heap.top();
        heap.pop();
        //
        LL cost = X.fi;
        int u = X.se.se;
        int pa = X.se.fi;
        if(cost != D[u]) continue;
        //
        if(X.se.fi == 0) list_powers.push_back(u);
        else list_edges.push_back(mp(pa,u));

        D[u] = oo;
        res += cost;

        FOR(v,1,N){
            if(D[v] < oo){
                LL newCost = (K[u] + K[v]) * (llabs(A[u].fi - A[v].fi) + llabs(A[u].se - A[v].se));
                if(newCost < D[v]){
                    D[v] = newCost;
                    heap.push(mp(newCost,mp(u,v)));
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //

    cin >> N;

    FOR(i,1,N){
        cin >> A[i].fi >> A[i].se;
    }

    FOR(i,1,N) cin >> C[i];
    FOR(i,1,N) cin >> K[i];

    if(N <= 1){
        cout << C[1] << endl;
        cout << 1 << endl << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
   
    build_edges();

    find_result();
    
    cout << res << endl;

    cout << list_powers.size() << endl;

    REP(i,0,list_powers.size()) cout << list_powers[i] << " ";
    cout << endl;

    cout << list_edges.size() << endl;

    REP(i,0,list_edges.size()) cout << list_edges[i].fi << " " << list_edges[i].se << endl;

    return 0;
}