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

void st() {
    int n;
    string s;
    cin >> n >> s;
    int f1 = n, l1 = -1;
    FOR(i,0,n) {
        if (s[i] == '1'){
            f1 = min(f1, i);
            l1 = max(l1, i);
        }
    }
    int bestest = 0;
    if (f1 != n){
        bestest = max(2 * (n - f1), 2 * (l1 + 1));
    }
    cout << max(n, bestest) << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        st();
    }
}
