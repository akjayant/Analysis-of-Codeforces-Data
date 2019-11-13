#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 200001

using namespace std;
typedef long long ll;

int main(){
    BASE
    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ret = 0;
        ret = min(c / 2, b);
        b -= ret;
        ret += min(a, b / 2);
        cout << ret * 3 << '\n';
    }
    return 0;
}
