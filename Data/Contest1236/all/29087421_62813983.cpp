#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m; cin >> n >> m;
    set<int> atrow[n];
    set<int> atcol[m];
    int k; cin >> k;
    for(int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        x -= 1; y -= 1;
        atrow[x].insert(y);
        atcol[y].insert(x);
    }
    int currx = 0;
    int curry = 0;
    int topx, downx, leftx, rightx;
    topx = 0;
    downx = n;
    leftx = -1;
    rightx = m;
    ll visited = 1;
    bool first = 1;
    while(true) {
        int newy;
        int newx;
        auto it = atrow[currx].upper_bound(curry);
        if(it == atrow[currx].end()) {
            newy = rightx - 1;
        } else {
            newy = min(*it - 1, rightx - 1);
        }

        if(newy == curry && !first) break;
        first = 0;

        visited += newy - curry;

        rightx = newy;
        curry = newy;

        it = atcol[curry].upper_bound(currx);
        if(it == atcol[curry].end()) {
            newx = downx - 1;
        } else {
            newx = min(*it - 1, downx - 1);
        }

        if(newx == currx) break;

        visited += newx - currx;

        downx = newx;
        currx = newx;

        it = atrow[currx].lower_bound(curry);

        if(it != atrow[currx].begin()) { 
            newy = max(*(--it) + 1, leftx + 1);
        } else {
            newy = leftx + 1; 
        }
        
        if(newy == curry) break;

        visited += curry - newy;

        leftx = newy;
        curry = newy;

        it = atcol[curry].lower_bound(currx);

        if(it != atcol[curry].begin()) {
            newx = max(*(--it) + 1, topx + 1);
        } else {
            newx = topx + 1;
        }

        if(newx == currx) break;

        visited += currx - newx;

        topx = newx;
        currx = newx;

    }

    if(visited == n * m - k) cout << "YES" << endl;
    else cout << "NO" << endl;
}
