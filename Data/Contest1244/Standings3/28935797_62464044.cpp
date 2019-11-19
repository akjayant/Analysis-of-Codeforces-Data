#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FOROP(i,a,b,op) for(int i=a;i<b;op)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define PB push_back
#define FI first
#define SE second
#define umap unordered_map
#define uset unordered_set
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define ALL(X) (X).begin(),(X).end()
#ifndef DEBUG
#define endl (char)10
#endif
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int T[5];
        FOR(i,0,5) cin >> T[i];
        int x = (T[0] + T[2] - 1) / T[2];
        int y = (T[1] + T[3] - 1) / T[3];
        if (x + y <= T[4]) {
            cout << x << " " << y << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
