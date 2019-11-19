#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int
set<int> s[200000];
set<int> all;
void dfs (int u) {
    for (auto it = all.begin(); it != all.end();) {
        if (s[u].find(*it) != s[u].end()) {
            it++;
            continue;
        }
        int v = *it;
        all.erase(v);
        dfs(v);
        it = all.upper_bound(v);
    }
}
 
signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) all.insert(i);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (all.find(i) == all.end()) continue;
        all.erase(i);
        dfs(i);
        cnt++;
    }
    cout << cnt - 1<< endl;
}
