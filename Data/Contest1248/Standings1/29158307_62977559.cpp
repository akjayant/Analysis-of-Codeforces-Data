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

void solve()
{

    int t;
    cin >> t;

    while (t--){

        ll n;
        cin >> n;

        ll cnr1 = 0;

        for (int i = 0; i < n; ++ i){
            int p;
            cin >> p;
            if (p %  2 == 0)
                cnr1++;
        }

        ll m ;
        cin >> m;

        ll cnt2 = 0;

        for (int i = 0; i < m; ++ i){
            int p;
            cin >> p;
            if (p %  2 == 0)
                cnt2++;
        }

        ll answr = 0;

        answr = cnr1 * cnt2 + (n - cnr1 ) * (m - cnt2);

        cout << answr << "\n";




    }

}

int main()
{
    cout.precision(20);

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