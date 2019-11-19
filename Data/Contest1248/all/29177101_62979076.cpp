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
        int n,m;
        ll cnt0 = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
        cin >> n;
        for (int i = 0;i < n;++i) {
            int p;
            scanf("%d",&p);
            if (p&1) cnt0++;
            else cnt1++;
        }
        cin >> m;
        for (int i = 0;i < m;++i) {
            int p;
            scanf("%d",&p);
            if (p&1) cnt2++;
            else cnt3++;
        }
        cout << cnt0*cnt2+cnt1*cnt3 << "\n";
    }
}