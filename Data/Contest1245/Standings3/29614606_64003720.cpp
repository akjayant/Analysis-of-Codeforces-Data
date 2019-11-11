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
        int a,b,c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int u = 0,v = 0,w = 0;
        for (int i = 0;i < n;++i) {
            if (s[i] == 'R') u++;
            else if (s[i] == 'P') v++;
            else w++;
        }
        int aa = min(a,w),bb = min(b,u),cc = min(c,v);
        if ((aa+bb+cc)*2 >= n) {
            cout << "YES" << "\n";
            for (int i = 0;i < n;++i) {
                if (s[i] == 'R' && bb) {
                    cout << 'P';
                    bb--;
                    b--;
                } else if (s[i] == 'P' && cc) {
                    cout << 'S';
                    cc--;
                    c--;
                } else if (s[i] == 'S' && aa) {
                    cout << 'R';
                    aa--;
                    a--;
                } else {
                    if (a > aa) {
                        cout << 'R';
                        a--;
                    } else if (b > bb) {
                        cout << 'P';
                        b--;
                    } else {
                        cout << 'S';
                        c--;
                    }
                }
            }
            cout << "\n";
        } else cout << "NO" << "\n";
    }
}