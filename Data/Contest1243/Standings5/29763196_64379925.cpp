#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

int main() {
    //freopen("in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s,t;
        cin >> n >> s >> t;
        int x = -1,y = -1;
        bool f = 1;
        for(int i = 0;i < n;++i) {
            if(s[i] != t[i]) {
                if(x == -1) x = i;
                else if(y == -1) y = i;
                else {
                    f = 0;
                    break;
                }
            }
        }
        f &= (~x && ~y && s[x] == s[y] && t[x] == t[y]);
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}