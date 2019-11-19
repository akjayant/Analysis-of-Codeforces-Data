#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int main(){
    int t, a, b, c, d, e;
    cin >> t;
    while(t --){
        cin >> a >> b >> c >> d >> e;
        int pen = (a + c - 1) / c;
        int pencil = (b + d - 1) / d;
        int tot = pen + pencil;
        if(tot > e){
            puts("-1");
            continue;
        }
        cout << pen << " " << pencil << endl;
    }

    return 0;
}