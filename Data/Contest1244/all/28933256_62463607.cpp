#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <istream>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <set>
#include <cmath>
#include <random>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <queue>
#include <string>

#define int long long
#define endl "\n"
#define all(x) x.begin(),x.end()
#define rr return 0
#define xx first
#define yy second
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans = ceil(a * 1.0 / c * 1.0) + ceil(b * 1.0 / d * 1.0);
        if(ans <= k)
            cout << ceil(a * 1.0 / c * 1.0) << " " << ceil(b * 1.0 / d * 1.0) << endl;
        else
            cout << -1 << endl;
    }
    rr;
}
