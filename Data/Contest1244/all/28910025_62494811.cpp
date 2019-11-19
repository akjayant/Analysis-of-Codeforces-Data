#include <bits/stdc++.h>
#define N ((int)1e5+10)
#define MD ((int)1e9+7)

using namespace std;

int n;
long long k;

map<int, int> mp;

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    long long ans = 1e18;

    while (true) {
        if (mp.size() == 1) {
            ans = 0;
            break;
        }
        map<int, int>::iterator it = mp.begin();
        map<int, int>::reverse_iterator rit = mp.rbegin();
        pair<int, int> f = *it;
        it++;
        pair<int, int> f2 = *it;
        pair<int, int> e = *rit;
        rit++;
        pair<int, int> e2 = *rit;

        ans = min(ans, 0LL + (*mp.rbegin()).first - (*mp.begin()).first);


        long long mxf = f2.first;
        long long mne = e2.first;

        if (f.second < e.second) {
            long long dis = (f2.first - f.first);
            dis = min(dis, k / f.second);
            if (dis == 0)
                break;
            long long cost = f.second * dis;
            if (cost > k)
                break;
            mp.erase(mp.begin());
            k -= cost;
            f.first += dis;
            mp[f.first] += f.second;

        } else {
            long long dis = (e.first - e2.first);
            dis = min(dis, k / e.second);
            if (dis == 0)
                break;
            long long cost = e.second * dis;
            if (cost > k)
                break;
            map<int, int>::reverse_iterator ii = mp.rbegin();
            mp.erase(--(ii.base()));
            k -= cost;
            e.first -= dis;
            mp[e.first] += e.second;
        }
    }
    printf("%lld\n", ans);


    return 0;
}
