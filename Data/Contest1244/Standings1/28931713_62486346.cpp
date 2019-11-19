#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <iterator>

int n;
long long k;
std::map<int, int> map;

int main()
{
	scanf("%d%lld", &n, &k);
	while (n--)
	{
		int x; scanf("%d", &x);
		++map[x];
	}
	while (k > 0 && map.size() > 1)
		if (map.begin()->second < map.rbegin()->second)
		{
			auto iter = map.begin();
			long long step = std::min(k / iter->second, (long long)(std::next(iter)->first - iter->first));
			if (step == 0) break;
			map[iter->first + step] += iter->second;
			k -= step * iter->second;
			auto nxt_iter = std::next(iter);
			map.erase(iter);
			iter = nxt_iter;
		}
		else
		{
			auto iter = map.rbegin();
			long long step = std::min(k / iter->second, (long long)(iter->first - std::next(iter)->first));
			if (step == 0) break;
			map[iter->first - step] += iter->second;
			k -= step * iter->second;
			auto nxt_iter = std::next(iter);
			map.erase(iter->first);
			iter = nxt_iter;
		}
	printf("%d\n", map.rbegin()->first - map.begin()->first);
	return 0;
}
