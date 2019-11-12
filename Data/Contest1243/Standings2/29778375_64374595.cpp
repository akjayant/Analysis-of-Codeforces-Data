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
        vector<int> cnt(1010,0);
        for (int i = 0;i < n;++i) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        for (int i = 1000;i > 0;--i) cnt[i-1] += cnt[i];
        for (int i = 1000;i >= 0;--i) if (cnt[i] >= i) {
            cout << i << "\n";
            break;
        }
    }
}