#include <bits/stdc++.h>

const int32_t MAX_N = 300;

std::vector< int32_t > v[MAX_N + 5];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t n;
	std::cin >> n;

	std::deque< int32_t > dq;
	for(int32_t i = 0; i < n * n; i++) {
		dq.push_back(i + 1);
	}

	while(!dq.empty()) {
		for(int32_t j = 0; j < n; j++) {
			if(v[j].size() == n - 1) {
				v[j].push_back(dq.front());
				dq.pop_front();
			}
			else {
				v[j].push_back(dq.front());
				dq.pop_front();
				v[j].push_back(dq.back());
				dq.pop_back();
			}
		}
	}

	for(int32_t i = 0; i < n; i++) {
		for(auto &x : v[i]) {
			std::cout << x << " ";
		}
		std::cout << '\n';
	}
}
