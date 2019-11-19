#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;

const int N = 2e5+10;
set<int> posDiagToJ[N], negDiagToJ[N];
map<int, int> memoPos[N], memoNeg[N];

int n, m;

int solvePos(int i, int j) {
    if(j == m+1) return i;
    if(memoPos[i].count(j)) return memoPos[i][j];
    auto it = posDiagToJ[i+j].upper_bound(j);
    int res = -1;
    if(it == posDiagToJ[i+j].end()) {
        int temp = (m+1) - j;
        res = max(0LL, i - temp);
    } else {
        int blockedJ = *it;
        int temp = blockedJ - j;
        res = solvePos(i-temp+1, j+temp);
    }
    return memoPos[i][j] = res;
}

int solveNeg(int i, int j) {
    if(j == m+1) return i;
    if(memoNeg[i].count(j)) return memoNeg[i][j];
    auto it = negDiagToJ[j-i+n].upper_bound(j);
    int res = -1;
    if(it == negDiagToJ[j-i+n].end()) {
        int temp = (m+1) - j;
        res = min(n-1, i+temp);
    } else {
        int temp = *it - j;
        res = solveNeg(i+temp-1, j+temp);
    }
    return memoNeg[i][j] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int j = 1; j <= m; ++j) {
        int box;
        cin >> box;
        --box;
        //cout << "diag: " << j+box << endl;
        posDiagToJ[j+box].insert(j);
        negDiagToJ[j-box+n].insert(j);
    }
    vector<int> lows(n);
    vector<int> highs(n);
    for(int i = 0; i < n; ++i) {
        lows[i] = solvePos(i,0);
        highs[i] = solveNeg(i,0);
    }
    /*
    cout << "lows:\n";
    for(int i = 0; i < n; ++i) {
        cout << lows[i] << ' ';
    }
    cout << "highs:\n";
    for(int i = 0; i < n; ++i) {
        cout << highs[i] << ' ';
    }
    */
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += highs[i]-lows[i] + 1;
    }
    cout << ans << endl;
}
