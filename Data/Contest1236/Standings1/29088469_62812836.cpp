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
#define int ll

using namespace std;

int n, m, k;
vector<vector<int>> v1;
vector<vector<int>> v2;

int32_t main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int xi, xj;
        cin >> xi >> xj;
        xi--; xj--;
        v1[xi].push_back(xj);
        v2[xj].push_back(xi);
    }

    for (int i = 0; i < n; ++i) {
        v1[i].push_back(-1);
        v1[i].push_back(m);
    }

    for (int i = 0; i < m; ++i) {
        v2[i].push_back(-1);
        v2[i].push_back(n);
    }

    for (int i = 0; i < n; ++i) {
        sort(v1[i].begin(), v1[i].end());
    }

    for (int i = 0; i < m; ++i) {
        sort(v2[i].begin(), v2[i].end());
    }

    pii pos(0, 0);
    int np = 1;
    int mni = 1;
    int mxi = n - 1;
    int mxj = m - 1;
    int mnj = 0;
    ll cnt = 1;
    set<pii> st;

    while (true) {
        //cout << pos.fi << ' ' << pos.se << ' ' << cnt << ' ' << np << endl;
        if (np == 1) {
            int s = min(mxj, *upper_bound(v1[pos.fi].begin(), v1[pos.fi].end(), pos.se) - 1);
            //cout << mxj << ' ' << s << endl;
            if ((s < pos.se) || ((s == pos.se) && (st.count(pos)))) {
                break;
            }
            cnt += s - pos.se;
            pos.se = s;
            mxj = min(mxj, pos.se - 1);
            np = 2;
            st.insert(pos);
        } else if (np == 2) {
            int s = min(mxi, *upper_bound(v2[pos.se].begin(), v2[pos.se].end(), pos.fi) - 1);
            //cout << mxi << endl;
            if ((s < pos.fi) || ((s == pos.fi) && (st.count(pos)))) {
                break;
            }
            cnt += s - pos.fi;
            pos.fi = s;
            mxi = min(mxi, pos.fi - 1);
            np = 3;
            st.insert(pos);
        } else if (np == 3) {
            int s = max(mnj, *(--upper_bound(v1[pos.fi].begin(), v1[pos.fi].end(), pos.se)) + 1);
            if ((s > pos.se) || ((s == pos.se) && (st.count(pos)))) {
                break;
            }
            cnt += pos.se - s;
            pos.se = s;
            mnj = max(mnj, pos.se + 1);
            np = 4;
            st.insert(pos);
        } else {
            int s = max(mni, *(--upper_bound(v2[pos.se].begin(), v2[pos.se].end(), pos.fi)) + 1);
            if ((s > pos.fi) || ((s == pos.fi) && (st.count(pos)))) {
                break;
            }
            cnt += pos.fi - s;
            pos.fi = s;
            mni = max(mni, pos.fi + 1);
            np = 1;
            st.insert(pos);
        }
    }


    if (((ll)n * m - k) == cnt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}