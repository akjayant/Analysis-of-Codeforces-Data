#include <bits/stdc++.h>
#define um unordered_map
#define us unordered_set
#define f first
#define s second
#define pb push_back
#define MOD 1000000007
#define MOD2 1000000009
#define BASE 29
#define BASE2 31
#define eps 1e-9
#define INF 1000000002

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<pii,pii> piiii;
const int N = 1000002;

vector<int> adjList[N];
stack<int> stk;
vector<vector<int> > comps;
int dfn = 0;
bool inStack[N];
int dfsNum[N];
int lowLink[N];
int comp[N], outDeg[N];
int n,m;

void tarjan(int node ) {
    stk.push(node);
    inStack[node] = true;
    dfsNum[node] = lowLink[node] = ++dfn;
    for(int ch : adjList[node]) {
        if(!dfsNum[ch]) {
            tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        } else if (inStack[ch]) {
            lowLink[node] = min(lowLink[node], dfsNum[ch]);
        }
    }
    if(dfsNum[node] == lowLink[node]) {
        int x = -1;
        comps.pb(vector<int>());
        while(x != node) {
            x = stk.top(), stk.pop(), inStack[x] = false;
            comps.back().pb(x);
            comp[x] = comps.size()-1;
        }
    }
}


int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i= 1;i<=m;i++) {
            int x, y;
            scanf("%d%d",&x,&y);
            if(x == y)
                continue;
            adjList[x].pb(y);
        }
        for(int i = 1;i<=n;i++)
            if(!dfsNum[i])
                tarjan(i);
        if(comps.size() == 1) {
            printf("No\n");
        } else {
            printf("Yes\n");
            for(int i =1;i<=n;i++)
                for(int ch : adjList[i])
                    if(comp[ch] != comp[i])
                outDeg[comp[i]]++;

            for(int i = 0;i<comps.size();i++) {
                if(!outDeg[i]) {
                    printf("%d %d\n", (int)comps[i].size(), n - (int)comps[i].size());
                    int cntA = 0, cntB = 0;
                    for(int j=1;j<=n;j++) {
                        if(comp[j] == i) {
                            printf("%d ", j);
                            cntA++;
                        }
                    }
                    printf("\n");
                    for(int j=1;j<=n;j++) {
                        if(comp[j] != i) {
                            printf("%d ", j);
                            cntB++;
                        }
                    }
                    assert(cntA == comps[i].size());
                    assert(cntB == n-comps[i].size());
                    printf("\n");
                    break;
                }
            }
        }
        dfn = 0;
        for(int i =0;i<=n;i++)
            adjList[i].clear(), lowLink[i] = dfsNum[i] = comp[i] = 0, outDeg[i] = 0;
        comps = vector<vector<int> >();
        assert(!comps.size());
    }
    return 0;
}
