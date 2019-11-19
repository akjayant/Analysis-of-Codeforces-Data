/*
ID: Miminyte500
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;

    cin >> t;

    int a, b, c, d, k;

    while(t--) {

        cin >> a >> b >> c >> d >> k;

        if(((a + c - 1) / c) + ((b + d - 1) / d) > k) cout << -1 << '\n';
        else cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << '\n';
    }

    return 0;
}
