#include <bits/stdc++.h>
#define int long long
#define ld long double
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>
using namespace std;
int n, k, x;
deque<pii> dq;
int32_t main()
{   //srand(chrono::steady_clock::now().time_since_epoch().count());
    boost;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        dq.push_back({x, 1});
    }
    sort(dq.begin(), dq.end());
    while(k > 0 && dq.size() > 1) {
       //     cout << "CUR K : " << k << "\n";

        while(dq.size() > 1 && dq[0].first == dq[1].first) {
            dq[1].second += dq[0].second;
            dq.pop_front();
        }
        while(dq.size() > 1 && dq.back().first == dq[dq.size() - 2].first) {
            dq[dq.size() - 2].second += dq.back().second;
            dq.pop_back();
        }
        if(dq.size() < 2)
            break;
        if(dq[0].second <= dq.back().second) {
            if((dq[1].first - dq[0].first) * dq[0].second <= k) {
                k -= (dq[1].first - dq[0].first) * dq[0].second;
                dq[0].first = dq[1].first;
            } else {
                int maly = dq[0].first + k / dq[0].second;
                cout << dq.back().first - maly;
                return 0;
            }
        } else {
            if((dq.back().first - dq[dq.size() - 2].first) * dq.back().second <= k) {
                k -= (dq.back().first - dq[dq.size() - 2].first) * dq.back().second;
                dq.back().first = dq[dq.size() - 2].first;
            } else {
                int duzy = dq.back().first - k / dq.back().second;
                cout << duzy - dq[0].first;
                return 0;
            }
        }
    }//cout << "E";
    cout << dq.back().first - dq[0].first;
}
