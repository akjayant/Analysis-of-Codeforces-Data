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

    while(t--) {
        int n;
        cin >> n;

        int br(0);
        int f(1<<29), l(0);

        vector<bool> st(n);
        char ch;
        bool bl;
        for(int i=0;i<n;i++) {
            cin >> ch;
            bl = ch-'0';
            br+=bl;
            st[i]=bl;
            if(bl) {
                f = min(f, i);
                l = max(l, i);
            }
        }

        l = n - l - 1;

        int mx(0);

        mx=max(mx, n + br);

        if(br == 0) {
            cout << mx << '\n';
            continue;
        }

        mx = max(mx, 2*n - 2*l - 2*f + 2*max(l, f));

        cout << mx << '\n';
    }

    return 0;
}
