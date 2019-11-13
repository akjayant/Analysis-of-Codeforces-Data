#include <stdio.h>
//#include <conio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long LL;
int t;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0, x;
		x = min(b, c / 2);
		ans += 3 * x;
		b -= x;
		x = min(a, b / 2);
		ans += 3 * x;
		cout << ans << "\n";



	}




	//_getch();
	return 0;
}