#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k;
ll a[100100];
map < ll, ll > cnt;
vector < pair <ll, ll >> v;
int main(){

    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]), ++cnt[a[i]];
    for (auto it : cnt)
        v.push_back(it);
	int l = 0, r = v.size()-1;
	ll mn;
	int idx;
	int dx;
	int inc;
	bool mv;
	while (l < r)
    {
        if (v[l].second < v[r].second) idx = l, dx = 1;
        else idx = r, dx = -1;
        mn = v[idx].second;
//        cout << l << " " << r << " " << idx << " " << mn << endl;
        if (mn > k)
            break;
        inc = min(abs(v[idx+dx].first - v[idx].first), k / v[idx].second);
//        cout << v[idx].first << endl;
        v[idx].first += inc * dx;

        k -= inc * v[idx].second;
//        cout << inc << " " << k << endl;
//        cout << v[idx].first << " " << v[idx].second << " " << v[idx+dx].first << " " <<v[idx+dx].second << endl;
        mv = 0;
        if (v[idx].first == v[idx+dx].first)
        {
            v[idx+dx].second += v[idx].second;
//            cout << "$$$: " <<v[idx+dx].first << " " << v[idx+dx].second << endl;
            mv = 1;
        }
        if (mv)
            if (l == idx) ++l;
            else --r;
    }
    printf("%lld\n", v[r].first - v[l].first);

	return 0;
}
