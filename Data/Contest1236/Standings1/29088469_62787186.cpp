#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <deque>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cassert>
#include <cstring>
#include <queue>
#include <random>

#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define mp(x, y) make_pair((x), (y))

using namespace std;
const ll MOD = 1000 * 1000 * 1000 + 7;

ll pw(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return pw((a * a) % MOD, b / 2);
    } else {
        return (pw(a, b - 1) * a) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    ll a, b;
    cin >> a >> b;
    cout << pw(((pw(2, b) + MOD - 1) % MOD), a) << endl;
    
    return 0;
}