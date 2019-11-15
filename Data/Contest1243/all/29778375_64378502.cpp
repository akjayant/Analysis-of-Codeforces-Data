#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int q;
    cin >> q;
    for (int z = 0;z < q;++z) {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int u,v,cnt = 0;
        for (int i = 0;i < n;++i) if (s[i] != t[i]) {
            cnt++;
            if (cnt == 1) u = i;
            else v = i;
        }
        if (cnt == 2 && s[u] == s[v] && t[u] == t[v]) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    }
    return 0;
}