#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using LL = long long;
using VL = vector<LL>;

LL solve(int N, LL K, VL& A)
{
    map<LL, LL> C;
    for (LL a : A)
        ++C[a];

    while (C.size() > 1) {
        auto it = C.begin();
        auto [a, ca] = *it;
        ++it;
        auto [b, cb] = *it;
        it = C.end();
        --it;
        auto [d, cd] = *it;
        --it;
        auto [c, cc] = *it;

        if (ca <= cd) {
            LL diff = b - a;
            LL p = min(K / ca, diff);
            if (p == 0)
                break;
            LL na = a + p;
            K -= p * ca;
            C.erase(a);
            C[na] += ca;
        } else {
            LL diff = d - c;
            LL p = min(K / cd, diff);
            if (p == 0)
                break;
            LL nd = d - p;
            K -= p * cd;
            C.erase(d);
            C[nd] += cd;
        }
    }

    auto it = C.begin();
    auto [a, ca] = *it;
    it = C.end();
    --it;
    auto [b, cb] = *it;
    return b - a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    LL K;
    cin >> N >> K;
    vector<LL> A(N);
    for (LL& a : A)
        cin >> a;
    cout << solve(N, K, A) << '\n';

    return 0;
}
