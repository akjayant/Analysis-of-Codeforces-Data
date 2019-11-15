#include <iostream>
#include <algorithm>
main()
{
	int t; std::cin >> t;
	while (t --)
	{
		int a,b; std::cin >> a >> b;
		std::cout << (std::__gcd(a,b) == 1 ? "Finite" : "Infinite") << '\n';
	}
}