#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long a[100005];
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<pair<long long,long long> > v;
    v.push_back({a[0], 1});
    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1])
        {
            v[v.size() - 1].second++;
        }
        else
        {
            v.push_back({a[i], 1});
        }
    }
    int l = 0, r = v.size() - 1;
    while(k > 0 && v[l].first != v[r].first && (v[l].second <= k || v[r].second <= k))
    {
        if(v[l].second <= v[r].second)
        {
            long long x = (v[l + 1].first - v[l].first) * v[l].second;
            if(k >= x)
            {
                k -= x;
                v[l + 1].second += v[l].second;
                l ++;
            }
            else
            {
                long long y = k / v[l].second;
                k -= y * v[l].second;
                v[l].first += y;
            }
        }
        else
        {
            long long x = (v[r].first - v[r - 1].first) * v[r].second;
            if(k >= x)
            {
                k -= x;
                v[r - 1].second += v[r].second;
                r --;
            }
            else
            {
                long long y = k / v[r].second;
                k -= y * v[r].second;
                v[r].first -= y;
            }
        }
    }
    cout << v[r].first - v[l].first << endl;

	return 0;
}
