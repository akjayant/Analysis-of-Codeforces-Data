// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl;
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

typedef long long ll;
typedef long double ld;

std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = atan2(0., -1.);
const int INF = 0x3f3f3f3f;
const int N = 100100;

// 0 - unused
// 1 - used

class Event {
public:
	int type;
	ll time;
	int index;

	Event() = default;

	Event(int type, ll time, int index) : type(type), time(time), index(index) {}

	bool operator<(const Event& other) const {
		return time < other.time || (time == other.time && type < other.type)
								 || (time == other.time && type == other.type && index < other.index);
	}
};

ll t[N];
ll ans[N];

int main(void) {
	int n;
	ll p;
	scanf("%d%lld", &n, &p);

	std::set<Event> setik;
	std::set<int> queue;
	std::set<int> ready;

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &t[i]);

		setik.insert(Event(0, t[i], i));
	}

	ll timer = 0;

	while (!setik.empty()) {
		int type = setik.begin()->type;
		ll time = setik.begin()->time;
		int index = setik.begin()->index;

		setik.erase(setik.begin());

		if (type == 0) {
			if (queue.empty() || *queue.begin() > index) {
				queue.insert(index);
				setik.insert(Event(1, std::max(timer, t[index]) + p, index));
				timer = std::max(timer, t[index]) + p;
			} else {
				ready.insert(index);
			}
		} else {
			ans[index] = time;
			queue.erase(index);

			while (!ready.empty() && (queue.empty() || *queue.begin() > *ready.begin())) {
				int index = *ready.begin();
				ready.erase(ready.begin());

				queue.insert(index);
				setik.insert(Event(1, std::max(timer, t[index]) + p, index));
				timer = std::max(timer, t[index]) + p;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%lld ", ans[i]);
	}
	printf("\n");

	return 0;
}
