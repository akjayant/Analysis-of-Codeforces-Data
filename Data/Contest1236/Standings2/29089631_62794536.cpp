#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e6 + 5, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int m = n * n, now = 1, flg = 1;
    vi G[303];
    for(int i = 1;i <= m;i ++) {
        G[now].pb(i);
        if(flg > 0) now ++; else now --;
        if(now > n) flg = -1, now = n;
        else if(now < 1) flg = 1, now = 1;
    }
    for(int i = 1;i <= n;i ++) {
        for(auto p : G[i]) cout << p << " ";
        cout << endl;
    }
    return 0;
}