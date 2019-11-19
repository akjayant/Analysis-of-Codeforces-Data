#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define MOD 1000000007

#define WISHES 1
#define BACK 2

struct Ev
{
	int person;
	int type;

	bool operator < (const Ev& other) const
	{
		return std::tie(type, person) < std::tie(other.type, other.person);
	}
};

int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	long long p;
	cin >> n >> p;


	set<pair<long long, Ev>> events;
	for (int i = 0; i < n; i++)
	{
		long long t;
		cin >> t;
		Ev v;
		v.person = i;
		v.type = WISHES;
		events.insert({ t, v });
	}

	set<int> queue;
	set<int> wishing;
	vector<long long> ans(n, 0);

	long long free_from = 0;

	while (events.size() > 0)
	{
		auto v = *events.begin();
		events.erase(v);

		auto ev = v.second;

		if (ev.type == WISHES)
		{

			if (queue.size() == 0 || (*queue.begin()) > ev.person)
			{
				queue.insert(ev.person);
				long long time_start = max(v.first, free_from);
				long long time_end = time_start + p;
				free_from = time_end;
				Ev evv;
				evv.person = ev.person;
				evv.type = BACK;
				events.insert({ time_end, evv });
			}
			else
			{
				wishing.insert(ev.person);
			}

		}
		else
		{
			// back
			ans[ev.person] = v.first;
			queue.erase(ev.person);

			if (wishing.size() == 0)
				continue;
			// push one wishing
			if (queue.size() == 0 || (*wishing.begin()) < *queue.begin())
			{
				int person = *wishing.begin();
				wishing.erase(person);
				queue.insert(person);
				long long time_start = max(v.first, free_from);
				long long time_end = time_start + p;
				free_from = time_end;
				Ev evv;
				evv.person = person;
				evv.type = BACK;
				events.insert({ time_end, evv });
			}
		}

	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}