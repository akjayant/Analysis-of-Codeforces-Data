/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int MAXN =  1e4 + 5;
char s[MAXN], t[MAXN];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int tt = clock();
    int tc;
    cin >> tc;
    int n;
    while(tc--) {
        cin >> n;
        cin >> (s + 1) >> (t + 1);
        vector<int> op;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != t[i]) op.emplace_back(i);
        }
        if (op.size() != 2) {
            cout << "No\n";
            continue;
        }
        bool can = false;
        swap(s[op[0]], t[op[1]]);
        if (memcmp(s + 1, t + 1, n * sizeof(char)) == 0) {
            can = true;
        }
        swap(s[op[0]], t[op[1]]);
        swap(s[op[1]], t[op[0]]);
        if (memcmp(s + 1, t + 1, n * sizeof(char)) == 0) {
            can = true;
        }
        if (can) cout << "Yes\n";
        else cout << "No\n";
    }



    cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
