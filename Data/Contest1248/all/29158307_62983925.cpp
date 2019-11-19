#pragma comment(linker, "/STACK:33554432")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;
void dout() { cerr << endl; }
const int MAXN = 2e5;
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<long long, long long>;

void precalc()
{
}

void solve() {
    ll answr = 0;

    int n;
    cin >> n;

    vector<ll> nums;

    for (int i = 0; i < n; ++i) {
        ll curr;
        cin >> curr;
        nums.push_back(curr);
    }


    sort(nums.begin(), nums.end());

    ll s1 = 0;
    ll s2 = 0;

    int l = 0;
    int r = n - 1;

    int turn = 0;

    while (l <= r){

        if (turn == 0) {
            s1 += nums[r];
            r--;
        }
        else{
            s2 += nums[l];
            l++;
        }
        turn = 1 - turn;
    }

    cout << s1 * s1 + s2 * s2;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    precalc();
    solve();
#ifndef ONLINE_JUDGE
    cout << '\n' << (double)clock() / CLOCKS_PER_SEC << '\n';
#endif

}