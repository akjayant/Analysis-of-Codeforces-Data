#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
using namespace std;







int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x, y;
        x = a / c;
        if (a % c)
            x++;
        y = b / d;
        if (b % d)
            y++;
        if (x + y <= k)
            cout << x << " " << y << "\n";
        else
            cout << "-1\n";
    }



	return 0;
}
