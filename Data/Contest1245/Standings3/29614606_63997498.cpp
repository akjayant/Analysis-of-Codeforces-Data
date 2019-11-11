#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int gcd(int a,int b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < n;++i) {
        int a,b;
        cin >> a >> b;
        if (gcd(a,b) > 1) cout << "Infinite" << "\n";
        else cout << "Finite" << "\n";
    }
    return 0;
}