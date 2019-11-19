#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
int a[100000];
main()
{
	std::ios_base::sync_with_stdio(0),std::cin.tie(0);
	int n; std::cin >> n,std::for_each(a,a + n,[](int & a){ std::cin >> a; });
	std::sort(a,a + n);
	auto F = [](int x,int y){ return static_cast <long long>(x) * x + static_cast <long long>(y) * y; };
	std::cout << F(std::accumulate(a,a + (n >> 1),0),std::accumulate(a + (n >> 1),a + n,0)) << '\n';
}