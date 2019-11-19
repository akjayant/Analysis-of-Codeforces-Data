#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
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

        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        while (n--)
        {
            int p;
            cin >> p;
            if (p % 2)
                cnt1++;
            else
                cnt0++;
        }
        int m;
        cin >> m;
        int cnt10 = 0, cnt11 = 0;
        while (m--)
        {
            int p;
            cin >> p;
            if (p % 2)
                cnt11++;
            else
                cnt10++;
        }
        cout << 1ll * cnt0 * cnt10 + 1ll * cnt1 * cnt11 << "\n";
    }




	return 0;
}
